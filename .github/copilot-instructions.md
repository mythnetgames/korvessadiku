# OpenRPI Copilot Instructions

## Project Overview
OpenRPI is a C++ MUD (text-based multiplayer game) engine derived from DIKU. It runs on Ubuntu via SSH at `ubuntu@18.118.12.229` (key: `C:\Users\Owner\.ssh\LightsailDefaultKey-us-east-2.pem`). Three server modes: playerport (4500/`pp`), buildport (4501/`bp`), testport (4502/`tp`).

## Required Workflow — Every Fix
After every code change, run this full cycle without exception:

```powershell
# 1. Commit and push locally
git add -A && git commit -m "fix: <description>" && git push

# 2. SSH: pull, kill, clean build, relaunch both ports
ssh -i C:\Users\Owner\.ssh\LightsailDefaultKey-us-east-2.pem ubuntu@18.118.12.229 "cd ~/RPI && git pull && pkill -9 server; sleep 2; rm -f lib/booting lib/last_crash; cd src && make clean && make 2>&1 | grep -i error | head -20; cd ~/RPI && ./start-server pp > /tmp/pp.log 2>&1 & sleep 4; rm -f lib/booting; ./start-server bp > /tmp/bp.log 2>&1 &"

# 3. Verify both ports are up
ssh -i C:\Users\Owner\.ssh\LightsailDefaultKey-us-east-2.pem ubuntu@18.118.12.229 "sleep 5; ss -tlnp | grep ':45'; ps aux | grep 'bin/server' | grep -v grep"
```

If the `lib/booting` lockfile is not removed between starting pp and bp, buildport will fail to start.

## Architecture
- **`src/`** — All C++ source. Compiled to `bin/server`. Build with `make` inside `src/`.
- **`lib/`** — Runtime instance data (objects, mobiles, player saves, logs, lockfile `lib/booting`)
- **`regions/`** — World files (rooms, mobs, objects per zone)
- **`regions/registry`** — Skill formulas
- **`lib/text/`** — Menus and static text shown to players
- **`tmp/`** — Server stdout logs (`rpi_engine_output.4500-*.txt`, etc.)
- **`crashes/`** — Crash logs (alongside `lib/last_crash`)

## Key Source Files
| File | Purpose |
|---|---|
| `structs.h` | All core data structures (`char_data`, `room_data`, `obj_data`), bit flags, direction constants |
| `commands.cpp` | Command table — maps player input strings to handler functions |
| `protos.h` | All function prototypes |
| `constants.h` | Buffer sizes (`MAX_STRING_LENGTH=49152`, `AVG_STRING_LENGTH=256`) |
| `staff.cpp` | Staff/admin commands including `do_set` (player toggles) and `do_map` |
| `act.informative.cpp` | `do_look`, room display, minimap renderer |
| `act.movement.cpp` | `do_move`, movement hooks — calls `do_look(ch, "", 77)` after each move |
| `olc.cpp` | In-game world-building (OLC) commands, `do_zsave` |
| `mysql.cpp` | All database persistence |
| `db.cpp` | World/zone loading at boot |

## Core Patterns

### Adding a Player Toggle (`set <keyword>`)
1. Add `#define MY_FLAG (1 << N)` after existing flags in the `/* plr_flags */` section of `structs.h` (next available: `1 << 27`)
2. Add handler in `do_set` in `staff.cpp` following the pattern:
```cpp
} else if ( !str_cmp( subcmd, "keyword" ) ) {
    if ( !IS_SET(ch->plr_flags, MY_FLAG) ) {
        ch->plr_flags |= MY_FLAG;
        send_to_char("Enabled.\n", ch);
        return;
    }
    ch->plr_flags &= ~MY_FLAG;
    send_to_char("Disabled.\n", ch);
    return;
}
```

### Adding a Command
1. Write `void do_mycmd(CHAR_DATA *ch, char *argument, int cmd)` in an appropriate `.cpp` file
2. Add prototype to `protos.h`
3. Register in `commands.cpp` command table: `{"mycmd", do_mycmd, DEAD, C_LV1}`
   - Trust levels: `DEAD`(0)=any, `FIGHT`=alive, `C_LV1`=immortal+
   - Flags: `C_HID` (keeps hidden), `C_DOA` (usable when dead), `C_BLD` (usable when blind)

### Room & Character Access
```cpp
ch->room                          // ROOM_DATA* current room
ch->in_room                       // int vnum of current room
vnum_to_room(vnum)                // convert vnum → ROOM_DATA*
ch->room->dir_option[NORTH]       // ROOM_DIRECTION_DATA* (check != NULL first)
ch->room->dir_option[NORTH]->to_room  // int destination vnum
IS_SET(exit->exit_info, EX_CLOSED)    // check door state
```

### Bit Flags
```cpp
IS_SET(ch->plr_flags, PLR_MAP)     // test
ch->plr_flags |= PLR_MAP;          // set
ch->plr_flags &= ~PLR_MAP;         // clear
TOGGLE(ch->plr_flags, PLR_MAP);    // toggle (macro in utils.h)
```

### Direction Constants (structs.h)
`NORTH=0, EAST=1, SOUTH=2, WEST=3, UP=4, DOWN=5, OUTSIDE=6, INSIDE=7, NORTHEAST=8, NORTHWEST=9, SOUTHEAST=10, SOUTHWEST=11` ... `LAST_DIR=DOWNSOUTHWEST=27`

### Output
```cpp
send_to_char("text\n", ch);
act("$n does something.", false, ch, obj, victim, TO_ROOM | _ACT_FORMAT);
sprintf(buf, "#6colored#0 text\n");  // color codes: #0=reset #1=red #2=green #6=cyan
```

## Critical Pitfalls
- **Buffer sizes**: Use `MAX_STRING_LENGTH` (49152) for output buffers — never `AVG_STRING_LENGTH` (256) for anything that accumulates multiple lines. This causes stack overflows.
- **`static` in recursive functions**: Never use `static` local counters in recursive functions (e.g. `fill_map`). Pass depth as a parameter instead.
- **Array bounds before access**: In C, `&&` is short-circuit but array dereference in `!array[bad_index]` crashes before the bounds check. Always put bounds check *first*: `if (x >= 0 && !array[x])` not `if (!array[x] && x >= 0)`.
- **`lib/booting` lockfile**: Must be deleted between starting pp and bp or buildport hangs.
- **`make clean` before `make`**: Always run `make clean` after header changes (`structs.h`, `protos.h`) to avoid stale `.o` files causing link errors.
- **Compiler**: `g++ -std=gnu++98 -fpermissive` — C++98 only. No STL containers in game-loop hot paths, no range-for, no `auto`.
