# Zone and Room Building Commands - Complete Education Guide

This guide documents all zone and room building commands used in the Online Creation (OLC) system. It covers syntax, parameters, functionality, and usage.

---

## Table of Contents
1. [Zone Commands](#zone-commands)
   - [ZSET](#zset-command)
   - [ZSAVE](#zsave-command)
2. [Room Creation Commands](#room-creation-commands)
   - [RINIT](#rinit-command)
3. [Room Property Commands](#room-property-commands)
   - [RNAME](#rname-command)
   - [RDESC](#rdesc-command)
   - [RSECTOR](#rsector-command)
4. [Room Connection Commands](#room-connection-commands)
   - [RLINK](#rlink-command)
5. [Door and Gate Commands](#door-and-gate-commands)
   - [RDOOR](#rdoor-command)
   - [RGATE](#rgate-command)
6. [Exit Configuration Commands](#exit-configuration-commands)
   - [RKEY](#rkey-command)
7. [Room Management Commands](#room-management-commands)
   - [RBLOCK](#rblock-command)
   - [RCLONE](#rclone-command)
   - [RLIST](#rlist-command)
   - [RUNUSED](#runused-command)

---

## ZONE COMMANDS

### ZSET Command

**Full Command Name:** `do_zset()`  
**File Location:** [src/olc.cpp](src/olc.cpp#L15923)

#### Syntax
```
zset <zone-number> [subcommand] [parameters]
```

#### Zone Number
- **Range:** 0-99
- **Required:** Yes
- **Example:** `zset 10` shows zone 10 info

#### What It Does (Step-by-Step)

1. **Without Subcommand** - Displays current zone information:
   - Zone ID number
   - Zone name
   - Project lead name
   - Jailer mob vnum
   - Jail room vnum
   - Dawn, sunrise, dusk, sunset messages (if custom)

2. **With Subcommand** - Modifies zone properties

#### Subcommands and Parameters

##### Name Subcommand
**Syntax:** `zset <zone> name <zone-name>`
- **Purpose:** Set the display name for a zone
- **Parameters:**
  - `<zone-name>`: Text name for the zone (string)
- **Example:** `zset 10 name The Wild Forests`
- **Output:** Sets the zone name that appears in various displays

##### Lead Subcommand
**Syntax:** `zset <zone> lead <player-name>`
- **Purpose:** Assign the project lead for a zone
- **Parameters:**
  - `<player-name>`: Character name of project lead
- **Requirements:** Requires trust level 5 (implementor only)
- **Example:** `zset 10 lead Thalos`
- **Output:** Project lead is changed and message "Project lead changed." appears

##### Jailer Subcommand
**Syntax:** `zset <zone> jailer <mob-vnum>`
- **Purpose:** Set the jailer mobile for this zone
- **Parameters:**
  - `<mob-vnum>`: Virtual number of the jailer mob
- **Validation:** Mob must exist / will check with `vnum_to_mob()`
- **Example:** `zset 10 jailer 1050`
- **Error:** "That mobile could not be found." if invalid

##### Jail Subcommand
**Syntax:** `zset <zone> jail <room-vnum>`
- **Purpose:** Set the prison room for this zone
- **Parameters:**
  - `<room-vnum>`: Virtual number of the jail room
- **Validation:** Room must exist / will check with `vnum_to_room()`
- **Example:** `zset 10 jail 1999`
- **Error:** "That room could not be found." if invalid

##### Earth Subcommand
**Syntax:** `zset <zone> earth <value>`
- **Purpose:** Apply a zone-wide earth element modifier
- **Parameters:**
  - `<value>`: Integer between -1000 and 1000
- **Example:** `zset 10 earth 150`
- **Output:** "Zone-wide earth modifier applied."
- **Effect:** Affects all spell calculations using earth element in this zone

##### Wind Subcommand
**Syntax:** `zset <zone> wind <value>`
- **Purpose:** Apply a zone-wide wind element modifier
- **Parameters:**
  - `<value>`: Integer between -1000 and 1000
- **Example:** `zset 10 wind -50`
- **Output:** "Zone-wide psychic modifier applied."
- **Note:** Message says "psychic" but affects wind element

##### Fire Subcommand
**Syntax:** `zset <zone> fire <value>`
- **Purpose:** Apply a zone-wide fire element modifier
- **Parameters:**
  - `<value>`: Integer between -1000 and 1000
- **Example:** `zset 10 fire 200`
- **Output:** "Zone-wide fire modifier applied."

##### Water Subcommand
**Syntax:** `zset <zone> water <value>`
- **Purpose:** Apply a zone-wide water element modifier
- **Parameters:**
  - `<value>`: Integer between -1000 and 1000
- **Example:** `zset 10 water 75`
- **Output:** "Zone-wide water modifier applied."

##### Shadow Subcommand
**Syntax:** `zset <zone> shadow <value>`
- **Purpose:** Apply a zone-wide shadow element modifier
- **Parameters:**
  - `<value>`: Integer between -1000 and 1000
- **Example:** `zset 10 shadow -100`
- **Output:** "Zone-wide shadow modifier applied."

##### Dawn Subcommand
**Syntax:** `zset <zone> dawn <message>`
- **Purpose:** Set custom dawn message for zone
- **Parameters:**
  - `<message>`: Custom dawn text, or 'default' to reset
- **Example:** `zset 10 dawn The sun breaks through the misty forests`
- **Output:** Message is stored (not displayed)

##### Sunrise Subcommand
**Syntax:** `zset <zone> sunrise <message>`
- **Purpose:** Set custom sunrise message for zone
- **Parameters:**
  - `<message>`: Custom sunrise text, or 'default' to reset
- **Example:** `zset 10 sunrise The morning light floods through the trees`

##### Dusk Subcommand
**Syntax:** `zset <zone> dusk <message>`
- **Purpose:** Set custom dusk message for zone
- **Parameters:**
  - `<message>`: Custom dusk text, or 'default' to reset

##### Sunset Subcommand
**Syntax:** `zset <zone> sunset <message>`
- **Purpose:** Set custom sunset message for zone
- **Parameters:**
  - `<message>`: Custom sunset text, or 'default' to reset

#### Complete Example Workflow
```
zset 10                           # View zone 10 info
zset 10 name The Mystical Woods   # Name the zone
zset 10 lead Thalos              # Assign project lead
zset 10 jailer 1050              # Set jailer mob
zset 10 jail 1999                # Set jail room
zset 10 earth 100                # Set earth modifier
zset 10 dawn The forest awakens  # Set dawn message
```

---

### ZSAVE Command

**Full Command Name:** `do_zsave()`  
**File Location:** [src/olc.cpp](src/olc.cpp#L2029)

#### Syntax
```
zsave [zone-number | all | dwellings]
```

#### What It Does (Step-by-Step)

1. **Validates** command can be used (not on player port during play mode)
2. **Saves** the specified zone(s) data to disk
3. **Also saves** related data (progs, crafts, variables, etc.) when `all` is used
4. **Backs up** if in build mode

#### Parameters

##### Zone Number Parameter
**Syntax:** `zsave <zone-number>`
- **Range:** 0-99
- **Purpose:** Save a specific zone
- **Example:** `zsave 10`
- **Output:** "Saved." on success
- **Error:** "Zone must be between 0 and 99."

##### All Keyword
**Syntax:** `zsave all`
- **Purpose:** Save ALL zones (0-99) and all related data
- **Output:** "All in-game zones have been saved, as well as progs, crafts, variables, foraged goods, and scents."
- **What's Saved:**
  - All room data (zones 0-99)
  - Mobile programs (mobprogs)
  - Object programs (objprogs)
  - Crafts file and craft programs
  - Object variables
  - Mobile variables
  - Foraged goods data
  - Defined scents
  - Mobile AIs
- **Special:** Creates backup in build mode: `sh /home/sanctuary/bp/scripts/backup.sh`

##### Dwellings Keyword
**Syntax:** `zsave dwellings`
- **Purpose:** Save dwelling rooms only
- **Output:** "Dwelling rooms saved."
- **Special:** Only saves data related to player dwellings

#### Restrictions
- **Player Port:** Cannot use during play mode on player port (port 4500)
- **Zone Locks:** Cannot save locked zones unless using special command (cmd == 226)
- **Implementor Mode:** Zone 99 cannot be saved in build mode

#### Error Messages
- "This command cannot be used on the player port."
- "That zone is locked. Please try zsaving later."
- "Sorry, but this zone can't be saved on the builder port." (Zone 99 on build port)
- "You must specify a zone between 0 and 99."
- "That is not a valid zone number."

#### Complete Example Workflow
```
zsave 10           # Save just zone 10
zsave 5            # Save zone 5
zsave all          # Save everything
zsave dwellings    # Save dwelling rooms
```

#### Data Files Created
When zones are saved, the system creates/updates:
- Zone room data files
- Mob program files
- Object program files
- Craft files
- Variable files
- Scent definition files
- Backup archives (in build mode)

---

## ROOM CREATION COMMANDS

### RINIT Command

**Full Command Name:** `do_rinit()`  
**File Location:** [src/olc.cpp](src/olc.cpp#L4444)

#### Syntax
```
rinit <room-number | n> [direction]
```

#### What It Does (Step-by-Step)

1. **Allocates** a new room in memory
2. **Assigns** a virtual room number
3. **Initializes** default properties
4. **Optionally** creates an exit in specified direction
5. **Confirms** room creation

#### Parameters

##### Room Number Parameter
**Syntax:** `rinit <room-number>` OR `rinit n`
- **Range (Numeric):** 0 to ROOM_MAX
- **Special Value 'n':** Automatically find next available slot in current zone
- **Requirement:** MUST be provided
- **Example:** `rinit 1050` (create specific room 1050)
- **Example:** `rinit n` (auto-assign next available in current zone)

##### Direction Parameter (Optional)
**Syntax:** `rinit <room-number> <direction>`
- **Valid Directions:** north, south, east, west, up, down, northeast, northwest, southeast, southwest
- **Purpose:** Automatically creates mutual exits
- **Example:** `rinit 1050 north`
- **Result:** 
  - Creates exit north from current room to 1050
  - Creates exit south from room 1050 back to current room

#### Initialization Process

When a room is created via `rinit`, the following defaults are set:

```
vnum              = <your specified number>
contents          = NULL (no objects)
people            = NULL (no NPCs/players)
light             = 0 (zero light sources)
zone              = vnum / ZONE_SIZE (auto-calculated)
name              = "New Room"
description       = "No Description Set.\n"
ex_description    = NULL (no extra descriptions)
wdesc             = NULL (no weather description)
extra             = NULL (no extra data)
all exits         = NULL (no connections)
```

#### Step-by-Step Example Workflow

**Step 1: Create room in zone 10**
```
rinit 1050
```
- Room 1050 is created in zone 10 (calculated as 1050/1000 = 1)
- Output: "Room 1050 has been initialized."

**Step 2: Create room with automatic exit**
```
rinit 1051 north
```
- Room 1051 is created
- Exit north from 1051 to current room is created
- Exit south from current room to 1051 is created
- Output: "Done." (from the rlink that's called internally)

**Step 3: Use auto-slot assignment**
```
rinit n
```
- Searches zone 10 (1000-1999) for first available slot
- Creates room at next available vnum
- Output: "Room <vnum> has been initialized."

#### Error Messages

- "You must supply a new room number, or 'n' to use the next available slot."
- "The argument must be a digit, or 'n' to use the next available slot."
- "That room number already exists."
- "Room numbers cannot exceed <ROOM_MAX>, You need to recompile and increase ROOM_MAX"
- "What direction is that?" (if direction is invalid)

#### After RINIT

Once created, you typically need to:
1. Set the room name: `rname <new name>`
2. Set the room description: `rdesc` (enter description editor)
3. Set the room sector: `rsector <sector-type>`
4. Create more exits with `rlink` if needed
5. Add doors/gates with `rdoor`/`rgate`

#### Technical Details

- **Room allocation** uses `allocate_room()` function
- **Zone assignment** is automatic based on vnum / ZONE_SIZE
- **Mutual exits** are created bidirectionally if direction provided
- **No exits initially** - must be added with `rlink`, `rexit`, or `rcret`

---

## ROOM PROPERTY COMMANDS

### RNAME Command

**Full Command Name:** `do_rname()`  
**File Location:** [src/olc.cpp](src/olc.cpp#L4433)

#### Syntax
```
rname <new-room-name>
```

#### What It Does
- **Sets** the display name of the room you're currently in
- **Must be in the room** to modify it
- **Applies immediately**

#### Parameters

##### Room Name Parameter
**Syntax:** `rname <new-room-name>`
- **Content:** Can be multiple words/any text
- **Special Chars:** Supported
- **Max Length:** Limited by MAX_INPUT_LENGTH
- **Purpose:** Text that players see when entering room
- **Example:** `rname A Mystical Forest Clearing`
- **Example:** `rname The Great Hall of the Castle`
- **Example:** `rname Bedroom`

#### Processing
1. **Whitespace removal:** All leading spaces are stripped
2. **Hash storage:** Text is stored using hash function for memory efficiency
3. **Immediate effect:** Changes apply to current room

#### Output
- "Done." on success

#### Example Workflow
```
# You're in room 1050
rname A Dense Forest
# The room is now called "A Dense Forest"

rname The Tavern of Whispers
# The room is now called "The Tavern of Whispers"
```

#### Technical Notes
- Uses `add_hash()` function to store the name
- Stored in `room->name` property
- This is what players see at the top of room descriptions

---

### RDESC Command

**Full Command Name:** `do_rdesc()`  
**File Location:** [src/olc.cpp](src/olc.cpp#L4584)

#### Syntax
```
rdesc [reformat]
```

#### What It Does (Step-by-Step)

1. **If "reformat" provided:** Reformats existing description
2. **Otherwise:** Opens description editor
3. **Shows old description** (if not in visual edit mode)
4. **Enters text input mode** to collect new description
5. **Stores new description** when terminated with '@'

#### Parameters

##### No Parameters
**Syntax:** `rdesc`
- **Purpose:** Edit room description
- **Behavior:**
  1. Shows old description (if exists)
  2. Announces "begins editing a room description"
  3. Enters rich text editor
  4. Wait for user to enter description
  5. Termination: Type '@' on new line to finish

##### Reformat Parameter
**Syntax:** `rdesc reformat`
- **Purpose:** Reformat existing description (fix line breaks, etc.)
- **Output:** Displays reformatted description immediately
- **No Editor:** Does not open text editing mode

#### Editing Process

**Text Editor Mode:**
1. Screen shows text ruler: `1-------10--------20--------30--------40--------50--------60---65`
2. Enter text freely, press Enter for line breaks
3. Type '@' alone on a line to finish
4. description is stored

**Visual Edit Mode (if enabled):**
1. Uses Visual Editor (VE) screen setup
2. Different editing interface than standard text mode

#### Output Messages

**Starting Edit:**
- "The old description was: \n<description text>"
- "$n begins editing a room description." (to others in room)

**Directing Input:**
- "Please enter the new description; terminate with an '@'\n\n"
- Text ruler display

**After Complete:**
- New description is stored

#### Example Workflow

```
# You're in room 1050 with old description "Poor dark cave"
rdesc
# System shows: "The old description was: Poor dark cave\n"
# Enters editor mode
# You type:
A deep, mysterious cave entrance lies before you.
Stalactites hang from the ceiling like ancient sentries.
The air is cool and carries the scent of minerals.
@
# Description is saved

# Later, reformat old description
rdesc reformat
# System reorganizes line breaks and displays result
```

#### Storage
- Stored in `room->description`
- Uses hash function for storage efficiency
- Can be very long (up to MAX_STRING_LENGTH)

#### Technical Details
- Uses message editor processor (`post_rdesc`)
- Can work in two modes: standard text edit or visual edit
- Old description shown unless in VISEDIT mode
- Message data stored in descriptor

---

### RSECTOR Command

**Full Command Name:** `do_rsector()`  
**File Location:** [src/olc.cpp](src/olc.cpp#L4816)

#### Syntax
```
rsector [sector-type | ?]
```

#### What It Does (Step-by-Step)

1. **If no parameter:** Shows current sector type
2. **If "?":** Shows available sector types
3. **If sector name:** Sets the sector type

#### Parameters

##### No Parameter
**Syntax:** `rsector`
- **Purpose:** Display current sector type
- **Output:** "Current sector type: <sector-name>"
- **Example Output:** "Current sector type: city"

##### Question Mark Parameter
**Syntax:** `rsector ?`
- **Purpose:** List all available sector types
- **Output:**
  ```
  The following sector types are available:
  <sector-type-1>   <sector-type-2>   <sector-type-3>   <sector-type-4>
  <sector-type-5>   ...
  ```
- **Formatting:** 4 per line, aligned

##### Sector Type Parameter
**Syntax:** `rsector <sector-type>`
- **Purpose:** Change room's sector type
- **Valid Types:** Parsed from `sector_types[]` array
- **Case-Insensitive:** Uses partial matching
- **Output:** "Done."

#### Available Sector Types

The system includes sector types for different terrain/room types. Common examples (from code):
- `city` - Urban areas
- `forest` - Wooded areas
- `mountain` - Rocky terrain
- `water` - Water locations
- `road` - Roads and paths
- `indoors` - Interior rooms
- `desert` - Sandy areas
- And many others in central sector_types table

#### Example Workflow

```
# Check current sector
rsector
# Output: Current sector type: city

# See available sectors
rsector ?
# Output: Shows all available types

# Change to forest
rsector forest
# Output: Done.
# Now rsector shows: Current sector type: forest
```

#### Validation
- **Partial Matching:** Uses `parse_argument()` with sector_types table
- **Case Handling:** Uses str_cmp (case-insensitive comparison)
- **Error:** If invalid sector type, no "Done" and command repeats

#### Storage
- Stored in `room->sector_type`
- Integer index into sector_types array
- Used for terrain effects, room properties, and descriptions

#### Technical Notes
- Uses `index_lookup()` to find sector in sector_types[]
- Sector affects:
  - Movement speed
  - Combat modifiers
  - Environmental effects
  - Room appearance

---

## ROOM CONNECTION COMMANDS

### RLINK Command

**Full Command Name:** `do_rlink()`  
**File Location:** [src/olc.cpp](src/olc.cpp#L4293)

#### Syntax
```
rlink <direction> <room-number>
```

#### What It Does (Step-by-Step)

1. **Validates** direction is valid
2. **Validates** target room exists
3. **Removes** any existing exit in that direction
4. **Creates** new exit from current room to target
5. **Creates** mutual reverse exit in target room
6. **Initializes** exit properties (no description, no key, etc.)

#### Parameters

##### Direction Parameter
**Syntax:** `<direction>` (first argument)
- **Valid Options:** north, south, east, west, up, down, northeast, northwest, southeast, southwest
- **Lookup:** Uses `lookup_dir()` function
- **Case-Insensitive:** Partial matching supported
- **Required:** Yes
- **Example:** `rlink north 1051`

##### Room Number Parameter
**Syntax:** `<room-number>` (second argument)
- **Format:** Valid virtual room number
- **Validation:** Room must exist
- **Required:** Yes
- **Example:** `rlink north 1051`

#### Exit Creation Process

**From Current Room:**
- `dir_option[direction]` created
- `general_description` = NULL
- `keyword` = NULL
- `exit_info` = 0 (no flags set)
- `key` = -1 (no key required)
- `to_room` = target room vnum

**From Target Room (Reverse):**
- `dir_option[reverse_direction]` created (south if north was linked)
- All same properties as above
- `to_room` = current room vnum

#### Exit Direction Mapping
- north ↔ south
- east ↔ west
- up ↔ down
- northeast ↔ southwest
- northwest ↔ southeast

#### Example Workflow

```
# You're in room 1050
rlink north 1051
# Creates:
#   Exit north from 1050 to 1051
#   Exit south from 1051 to 1050

rlink east 1052
# Creates:
#   Exit east from 1050 to 1052
#   Exit west from 1052 to 1050

rlink up 1100
# Creates:
#   Exit up from 1050 to 1100
#   Exit down from 1100 to 1050
```

#### Output
- "Done." on success

#### Error Messages
- "Syntax: rlink <direction> <room-number>" (if missing args)
- "What direction is that?" (if invalid direction)
- "No room exists with that number." (if target room doesn't exist)

#### Important Notes
- **Mutual Creation:** ALWAYS creates exit in both directions
- **Overwrites Old:** If exit already exists in that direction, it's removed and replaced
- **Default Properties:** New exits have no keys, no descriptions, no special flags
- **Must Configure:** Use `rdoor`, `rgate`, `rkey` to add features to exits

#### Related Commands
After `rlink`, you typically use:
- `rkey` - Add key requirement
- `rdoor` - Make it a door
- `rgate` - Make it a gate
- `rdflag` - Set exit flags

---

## DOOR AND GATE COMMANDS

### RDOOR Command

**Full Command Name:** `do_rdoor()`  
**File Location:** [src/olc.cpp](src/olc.cpp#L2342)

#### Syntax
```
rdoor <direction> [door-keyword]
```

#### What It Does (Step-by-Step)

1. **Validates** direction is valid
2. **Checks** exit exists in that direction
3. **Sets** door flag on the exit
4. **Sets** door keyword (the thing you examine/interact with)

#### Parameters

##### Direction Parameter
**Syntax:** `<direction>` (first argument)
- **Valid Options:** north, south, east, west, up, down, etc.
- **Lookup:** Uses `lookup_dir()` function
- **Case-Insensitive:** Supported
- **Required:** Yes
- **Example:** `rdoor north`

##### Door Keyword Parameter
**Syntax:** `[door-keyword]` (optional second argument)
- **Default:** If not provided, defaults to "door"
- **Purpose:** What players see when examining the door
- **Examples:** "door", "gate", "wooden door", "iron grate", "oak door"
- **Storage:** Stored in `exit_info->keyword` via hash
- **Example:** `rdoor north wooden door`

#### Door Flag Setting

The command sets the `EX_ISDOOR` flag:
```c
room->dir_option[dir]->exit_info |= EX_ISDOOR;
```

This flag tells the game engine:
- This is a door that can be opened/closed
- Players can 'open', 'close', 'lock', 'unlock' the exit
- May require key if set

#### Example Workflow

```
# You're in room 1050 with an exit north to 1051
rlink north 1051    # Create the exit

rdoor north
# Creates a door with keyword "door"

rdoor north wooden door
# Creates a door with keyword "wooden door"
# Players can now "examine wooden door"

rkey north 5012
# Make the door locked with key vnum 5012
```

#### Output
- "Done." on success

#### Error Messages
- "What direction is that?" (if invalid direction)
- "There is no exit in that direction." (if no exit exists)

#### Technical Details
- **Flag Setting:** Uses bitwise OR operation (|=) to set EX_ISDOOR
- **Keyword Storage:** Uses `add_hash()` for memory efficiency
- **Immutability:** Setting door multiple times overwrites the keyword

#### Default Behavior
If direction has no exit, the command fails with "There is no exit in that direction."

#### Related Commands
- `rgate` - Create gates instead of doors
- `rkey` - Add key requirement
- `rdflag` - Set additional exit flags (locked, closed, etc.)

---

### RGATE Command

**Full Command Name:** `do_rgate()`  
**File Location:** [src/olc.cpp](src/olc.cpp#L2376)

#### Syntax
```
rgate <direction> [gate-keyword]
```

#### What It Does (Step-by-Step)

1. **Validates** direction is valid
2. **Checks** exit exists in that direction
3. **Sets** gate flag on the exit (EX_ISGATE)
4. **Sets** gate keyword (the thing you examine/interact with)

#### Parameters

##### Direction Parameter
**Syntax:** `<direction>` (first argument)
- **Valid Options:** north, south, east, west, up, down, etc.
- **Lookup:** Uses `lookup_dir()` function
- **Required:** Yes
- **Example:** `rgate east`

##### Gate Keyword Parameter
**Syntax:** `[gate-keyword]` (optional second argument)
- **Default:** If not provided, defaults to "gate"
- **Purpose:** What players see when examining the gate
- **Examples:** "gate", "iron gate", "silver gate", "locked gate"
- **Example:** `rgate east iron gate`

#### Gate Flag Setting

The command sets the `EX_ISGATE` flag:
```c
room->dir_option[dir]->exit_info |= EX_ISGATE;
```

This flag tells the game engine:
- This is a gate (more permanent/magical than a door)
- Players can 'open', 'close' the gate
- May require key if set

#### Difference Between Doors and Gates

| Feature | Door | Gate |
|---------|------|------|
| Flag | EX_ISDOOR | EX_ISGATE |
| Open/Close | Yes | Yes |
| Lock/Unlock | Yes | Yes |
| Keyword | Custom | Custom |
| Durability | Lesser | Greater |
| Typical Use | Rooms, rooms | Magical barriers, compound gates |

#### Example Workflow

```
# You're in room 1050 with an exit east to 1051
rlink east 1051        # Create the exit

rgate east
# Creates a gate with keyword "gate"
# Output: Done.

rgate east iron gate
# Creates a gate with keyword "iron gate"

rkey east 5015
# Make the gate require key vnum 5015
```

#### Output
- "Done." on success

#### Error Messages
- "What direction is that?" (if invalid direction)
- "There is no exit in that direction." (if no exit exists)

#### Technical Details
- **Flag Setting:** Uses bitwise OR operation (|=) to set EX_ISGATE
- **Keyword Storage:** Uses `add_hash()` for memory efficiency
- **Immutability:** Setting gate multiple times overwrites the keyword

#### Related Commands
- `rdoor` - Create doors instead of gates
- `rkey` - Add key requirement
- `rdflag` - Set additional exit flags

---

## EXIT CONFIGURATION COMMANDS

### RKEY Command

**Full Command Name:** `do_rkey()`  
**File Location:** [src/olc.cpp](src/olc.cpp#L4996)

#### Syntax
```
rkey <direction> <key-vnum> [pick-penalty]
```

#### What It Does (Step-by-Step)

1. **Validates** direction is valid
2. **Checks** exit exists in that direction
3. **Sets** key vnum required to unlock the exit
4. **Optionally** sets the difficulty to pick the lock

#### Parameters

##### Direction Parameter
**Syntax:** `<direction>` (first argument)
- **Valid Options:** north, south, east, west, up, down, etc.
- **Lookup:** Uses `lookup_dir()` function
- **Required:** Yes
- **Example:** `rkey north`

##### Key VNUM Parameter
**Syntax:** `<key-vnum>` (second argument)
- **Format:** Must be digit
- **Purpose:** Virtual number of the object that unlocks
- **Validation:** Any integer accepted (doesn't check object exists)
- **Required:** Yes
- **Example:** `rkey north 5012`

##### Pick Penalty Parameter
**Syntax:** `[pick-penalty]` (optional third argument)
- **Format:** Must be digit
- **Purpose:** Difficulty to pick the lock (0 = easy, higher = harder)
- **Optional:** If omitted, no pick penalty set
- **Example:** `rkey north 5012 30`
- **Example:** `rkey north 5012 100` (very hard to pick)

#### Storage

**Key Vnum:**
```c
room->dir_option[dir]->key = atoi(buf);
```

**Pick Penalty (if provided):**
```c
room->dir_option[dir]->pick_penalty = atoi(buf);
```

#### Example Workflow

```
# You're in room 1050 with a locked door north
rlink north 1051       # Create exit
rdoor north            # Make it a door

rkey north 5012
# Now the door is locked with key vnum 5012
# Players need key vnum 5012 to unlock

rkey north 5012 50
# Same as above, but lock is hard to pick (penalty 50)
# Output: Done.
```

#### Output
- "Done." on success

#### Error Messages
- "What direction is that?" (if invalid direction)
- "There is no exit in that direction." (if no exit exists)
- "Syntax: rkey <dir> <key-vnum> [pick-penalty]" (if key-vnum is not digit)

#### Technical Details

**Key Setting Process:**
1. Direction is converted to integer (0-9)
2. Key vnum is stored in exit structure
3. Pick penalty optionally set
4. No validation of key object - will work even if obj doesn't exist

**Default Values:**
- If no `rkey` called: `key = -1` (no lock)
- If no pick penalty: `pick_penalty = 0` (no penalty)

#### Lock Behavior in Game
- **With key:** Players need exact key object to unlock
- **Pick Penalty:** Rogue can attempt to pick lock at difficulty penalty
- **Both:** Key can open instantly, rogue can pick with penalty

#### Related Commands
- `rdoor` - Mark exit as door first
- `rgate` - Mark exit as gate first
- `rdflag` - Lock/unlock status

---

## ROOM MANAGEMENT COMMANDS

### RBLOCK Command

**Full Command Name:** `do_rblock()`  
**File Location:** [src/olc.cpp](src/olc.cpp#L5608)

#### Syntax
```
rblock <zone> <width> <height>
```

#### What It Does (Step-by-Step)

1. **Calculates** how many rooms are unused in the zone
2. **Determines** if enough space for requested block
3. **Reports** free space available
4. **Confirms** or rejects the block request

#### Parameters

##### Zone Parameter
**Syntax:** `<zone>` (first argument)
- **Format:** Zone number (digit)
- **Range:** 0-99 (typically)
- **Purpose:** Which zone to build block in
- **Example:** `rblock 10 5 5`

##### Width Parameter
**Syntax:** `<width>` (second argument)
- **Format:** Number of rooms wide
- **Purpose:** Horizontal dimension
- **Example:** `rblock 10 5 5` (5 rooms wide)

##### Height Parameter
**Syntax:** `<height>` (third argument)
- **Format:** Number of rooms tall
- **Purpose:** Vertical dimension
- **Example:** `rblock 10 5 5` (5 rooms tall)

#### Space Requirements

The command calculates:
- **Used rooms:** Count of existing rooms in zone
- **Available slots:** 1000 - used (ZONE_SIZE is 1000)
- **Needed space:** width × height

#### Validation Process

```
If (bfree < (width * height))
    ERROR: "Not enough free rooms for block."
Else
    Proceed with block creation
```

#### Output

**Success:**
- `bfree:<number>` displayed
- (Then presumably block is created through another system)

**Failure:**
- `bfree:<number>` displayed
- "Not enough free rooms for block."

#### Example Workflow

```
# Zone 10 has 500 rooms used, 500 free
rblock 10 5 5
# Needs 25 rooms (5×5)
# At least 500 free available
# Output: bfree:500
# Block creation proceeds

# Zone 10 has 990 rooms used, 10 free
rblock 10 5 5
# Needs 25 rooms but only 10 free
# Output: bfree:10
#         "Not enough free rooms for block."
```

#### Technical Details

**Space Calculation:**
```c
for (troom = full_room_list; troom; troom = troom->lnext) {
    if (troom->zone == zone)
        used++;
}
bfree = (ZONE_SIZE - used);
```

**ZONE_SIZE:** Typically 1000 (rooms 0-999 per zone)

#### Important Notes
- **Zone Size Limit:** 1000 rooms maximum per zone (0-999)
- **Used Capacity:** Command counts actual rooms, not vnum slots
- **Not Automatic:** This command REPORTS capacity; actual block creation may use other system
- **No Room Reservation:** Other builders could use spaces simultaneously

#### Related Commands
- `rinit` - Create individual rooms
- `rclone` - Clone existing rooms
- `zsave` - Save zone after building

---

### RCLONE Command

**Full Command Name:** `do_rclone()`  
**File Location:** [src/olc.cpp](src/olc.cpp#L2293)

#### Syntax
```
rclone <source-room> [target-room]
rclone block
```

#### What It Does (Step-by-Step)

1. **If "block" keyword:** Clones current room block contiguously
2. **Otherwise:** Copies all properties from source room to target room
3. **Creates duplicate** of room exits, doors, gates, etc.
4. **New room vnum** reported on success

#### Parameters

##### Block Keyword
**Syntax:** `rclone block`
- **Purpose:** Clone an entire contiguous room block
- **Behavior:**
  1. Identifies all rooms in the current block
  2. Creates copies of all rooms as contiguous group
  3. Returns starting room vnum of new block
- **Output:** "Done; start room is at <vnum>."
- **Example:** `rclone block` (in room 1050)

##### Source Room Parameter
**Syntax:** `<source-room>` (first argument)
- **Format:** Virtual room number
- **Purpose:** The room to copy FROM
- **Validation:** Room must exist
- **Required:** Yes
- **Example:** `rclone 1050`

##### Target Room Parameter
**Syntax:** `[target-room]` (optional second argument)
- **Default:** If omitted, current room (ch->room)
- **Purpose:** The room to copy TO
- **Validation:** Room must exist if specified
- **Example:** `rclone 1050 1051` (clone 1050 into 1051)
- **Example:** `rclone 1050` (clone 1050 into current room)

#### Cloning Process

**What Gets Copied:**
- Room name
- Room description
- Room sector type
- Room flags
- Exit connections
- Door settings (if any)
- Gate settings (if any)
- Lock settings (if any)

**What Doesn't Get Copied:**
- Objects in the room
- NPCs in the room
- Players in the room

#### Example Workflow

```
# Clone one room into another
# You're in room 1050 (nicely decorated room)
rclone 1050 1051
# Room 1051 now has same properties as 1050
# Output: Done.

# Clone into current room
rclone 1050
# Current room gets all properties of 1050
# Output: Done.

# Clone a room block
# You're in room 1050 (first room of block)
rclone block
# All connected rooms cloned as new block
# Output: Done; start room is at 1100.
# New block starts at room 1100
```

#### Block Cloning Details

**What Triggers Block Detection:**
- Uses `clone_contiguous_rblock()` function
- Identifies rooms that are connected/contiguous
- Clones entire structure as group

**Output:**
- Returns starting vnum of newly created block

#### Error Messages
- "You must supply a virtual room number." (no source specified)
- "No such source room." (source room doesn't exist)
- "No such target room." (target room specified but doesn't exist)

#### Technical Details

**Cloning Function:**
```c
clone_room(source_room, target_room, false, false);
```

**Block Cloning Function:**
```c
clone_contiguous_rblock(ch->room, -1, false);
```

#### Important Notes
- **Overwrites Target:** All properties of target room are replaced
- **Preserves Links:** Exits and connections are maintained
- **Two Parameters:** Source and target, in that order
- **Current Room Default:** If no target, uses ch->room

#### Related Commands
- `rinit` - Create new rooms
- `rlink` - Connect rooms
- `rdoor`/`rgate` - Mark exits

---

### RLIST Command

**Full Command Name:** `do_rlist()`  
**File Location:** [src/olc.cpp](src/olc.cpp#L17473)

#### Syntax
```
rlist [filter-options]
```

#### Filter Options

Multiple filters can be combined:

```
rlist +<keyword> -<keyword> z<zone> s<sector> $<flag> /<flag>
```

#### What It Does (Step-by-Step)

1. **Parses** multiple filter criteria
2. **Searches** entire room database
3. **Applies** all filters simultaneously
4. **Displays** matching rooms (max 200)
5. **Shows count** if results exceed limit

#### Detailed Parameters

##### Keyword Filters (+ and -)

**Syntax:** `+<keyword>` or `-<keyword>`
- **+keyword:** Include rooms whose name contains keyword
- **-keyword:** Exclude rooms whose name contains keyword
- **Matching:** Uses isname() function (word matching, not substring)
- **Multiple:** Can use up to 3 keywords total
- **Example:** `rlist +bedroom` (rooms with "bedroom" in name)
- **Example:** `rlist +bedroom -poor` (bedrooms that aren't poor)

##### Zone Filter

**Syntax:** `z<zone>` or just `<zone>`
- **Purpose:** Show only rooms in specific zone
- **Format:** `z10` or `10`
- **Example:** `rlist z10` (only zone 10 rooms)
- **Example:** `rlist 10` (same as above)
- **Validation:** Zone 0-99 (error if >= 100)

##### Sector Filter

**Syntax:** `s<sector>`
- **Purpose:** Show only rooms of specific sector type
- **Format:** `s<sector-type-name>`
- **Example:** `rlist s city` (only city sector rooms)
- **Example:** `rlist s forest` (only forest rooms)
- **Lookup:** Uses index_lookup() of sector_types

##### Flag Filters ($ and /)

**Syntax:** `$<flag>` or `/<flag>`
- **$flag:** Include rooms WITH the flag set
- **/<flag>:** Exclude rooms WITH the flag (include ones without)
- **Matching:** Uses index_lookup() of room_bits
- **Multiple:** Can use up to 3 flags total
- **Example:** `rlist $scum` (rooms with scum flag)
- **Example:** `rlist /scum` (rooms without scum flag)

#### Filter Combination

Filters work with AND logic (all must match):

**Example:** `rlist +bedroom -poor $scum s city z 10`
- Must have "bedroom" in name
- Must NOT have "poor" in name
- Must have "scum" flag set
- Must be city sector
- Must be in zone 10
- Only shows rooms matching ALL criteria

#### Help Display

**No Arguments:**
```
rlist
```
Shows:
```
Selection Parameters:

   +/-<room keyword>       Include/exclude room keyword.
   z <zone>                Rooms from zone only.
   $<flag>                 Include rooms with rflag.
   /<flag>                 Exclude rooms with rflag.
   s  <sector>             Include rooms with sector-type.

Example:   rlist +bedroom -poor $scum s city z 10
will only get bedrooms of non-poor rooms, that are scum, in the city of zone 10.
```

#### Output Format

**Per Room:**
```
#6<room-name>#0 #2[<vnum>: <flags>#6<sector-type>#2]#0 [Prog]
```

**Examples:**
```
#6The Mystical Forest#0 #2[1050: peaceful#6forest#2]#0
#6The Dark Cave#0 #2[1051: scum#6cave#2]#0 [Prog]
```

**Legend:**
- `<room-name>` - Display name
- `<vnum>` - Room virtual number
- `<flags>` - Bitfield of room_flags set
- `<sector-type>` - Environment type
- `[Prog]` - Shows if room has programs attached

#### Result Handling

**Under 200 Results:**
- All matching rooms displayed
- Listed in room database order

**Over 200 Results:**
```
You have selected <count> rooms (too many to print).
```
- Shows count only
- Does not display results
- Use more filters to narrow search

#### Example Workflows

```
# Find all rooms in zone 10
rlist z 10

# Find all poor rooms
rlist +poor

# Find nice bedrooms in city sector
rlist +bedroom -poor s city

# Find all scum rooms lacking darkness
rlist $scum /dark

# Find unpopulated rooms in zone 5
rlist z 5 -populated

# Find all forest rooms in zone 8
rlist s forest z 8
```

#### Technical Details

**Filter Variable Types:**
- `key1, key2, key3` - Keywords to include/exclude
- `yes_key1, yes_key2, yes_key3` - 1 for include, 0 for exclude
- `flag_key1, flag_key2, flag_key3` - Flag indices
- `yes_flag1, yes_flag2, yes_flag3` - 1 for include, 0 for exclude
- `sector` - Index into sector_types
- `zone` - Zone number

**Matching Functions:**
- `isname()` - Keyword matching (word-based)
- `IS_SET()` - Bitfield flag checking
- `index_lookup()` - Finding in array

#### Related Commands
- `rinit` - Create rooms
- `rname` - Set room name
- `rsector` - Set sector type
- `rflags` - Set room flags

---

### RUNUSED Command

**Full Command Name:** `do_runused()`  
**File Location:** [src/olc.cpp](src/olc.cpp#L5637)

#### Syntax
```
runused [zone-number]
```

#### What It Does (Step-by-Step)

1. **Determines** which zone to check
2. **Scans** all existing rooms
3. **Marks** which room vnums are used
4. **Displays** all unused vnum slots
5. **Formats** output in grid (12 per row)

#### Parameters

##### Zone Parameter (Optional)
**Syntax:** `runused` or `runused <zone>`
- **Default:** If omitted, uses current zone (calculated from ch->in_room)
- **Specific Zone:** `runused <zone-number>`
- **Format:** Zone number 0-99
- **Example:** `runused` (unused in current zone)
- **Example:** `runused 10` (unused in zone 10)

#### Validation

**Zone Validation:**
```
if (!just_a_number(buf) || atoi(buf) < 0 || atoi(buf) >= MAX_ZONE)
    ERROR: "Syntax: runused [zone #]"
```

#### Output Format

**Display:**
```
  0001  0002  0004  0005  0007  0010  0015  0020  0025  0033  0040  0050
  0051  0062  0100  ...
```

**Formatting:**
- 12 room vnums per line
- 4-digit numbers right-aligned
- Lined up for easy scanning

#### Availability Calculation

**Process:**
1. Creates array: `unused[ZONE_SIZE]` (1000 slots)
2. Scans all rooms in room database
3. Marks used slots as `unused[i] = 1`
4. Unused slots remain `0`
5. Displays all where `unused[i] == 0`

#### Example Workflow

```
# Show unused in current zone 10
runused
# Output:
  1000  1002  1005  1010  1015  1040  1050  1100  1200  1300  1500  1600

# Show unused in zone 5
runused 5
# Output:
  5001  5002  5005  5010  5050  5100  5200  ...

# The numbers shown are vnums available for new rooms
# For zone 10, vnum 1000 is available
# For zone 5, vnum 5001 is available
```

#### Zone Numbering

**Zone 0:** vnums 0-999
**Zone 1:** vnums 1000-1999
**Zone 2:** vnums 2000-2999
...
**Zone 99:** vnums 99000-99999

**Formula:** `vnum = zone * 1000 + slot`

#### Practical Use

1. **Planning:** See what slots are free before building
2. **Avoiding Conflicts:** Don't build on used vnums
3. **Optimization:** See gaps in numbering
4. **Cleanup:** Identify unused areas

#### Example Interpretation

```
Zone 10 runused shows: 1025, 1050, 1075

This means:
- Vnums 1000-1024 are in use
- Vnum 1025 is free
- Vnums 1026-1049 are in use
- Vnum 1050 is free
- Vnums 1051-1074 are in use
- Vnum 1075 is free
```

#### Grid Display Logic

**Line Breaking:**
- `line_entry` counter tracks position (0-11)
- After 12 items, `\n` and indent added
- Keeps output readable

#### Error Messages
- "Syntax: runused [zone #]" (if zone invalid)

#### Related Commands
- `munused` - Same for mobiles (mobs)
- `ounused` - Same for objects
- `rblock` - Create room blocks
- `rinit` - Create individual rooms

---

## COMMAND REFERENCE SUMMARY TABLE

| Command | Purpose | Syntax |
|---------|---------|--------|
| **zset** | Modify zone properties | `zset <zone> [subcommand] [params]` |
| **zsave** | Save zone data to disk | `zsave <zone \| all \| dwellings>` |
| **rinit** | Create new room | `rinit <room-number \| n> [direction]` |
| **rname** | Set room name | `rname <name>` |
| **rdesc** | Edit room description | `rdesc [reformat]` |
| **rsector** | Set room terrain type | `rsector [sector-type \| ?]` |
| **rlink** | Create exit between rooms | `rlink <direction> <room-number>` |
| **rdoor** | Mark exit as door | `rdoor <direction> [keyword]` |
| **rgate** | Mark exit as gate | `rgate <direction> [keyword]` |
| **rkey** | Add lock to exit | `rkey <direction> <key-vnum> [penalty]` |
| **rblock** | Check space for room block | `rblock <zone> <width> <height>` |
| **rclone** | Copy room or block | `rclone <source> [target] \| block` |
| **rlist** | Search and filter rooms | `rlist [filters...]` |
| **runused** | Show available room vnums | `runused [zone]` |

---

## ZSET SUBCOMMANDS SUMMARY

| Subcommand | Purpose | Syntax |
|------------|---------|--------|
| name | Set zone name | `zset <zone> name <text>` |
| lead | Set project lead | `zset <zone> lead <player>` |
| jailer | Set jailer mob | `zset <zone> jailer <mob-vnum>` |
| jail | Set jail room | `zset <zone> jail <room-vnum>` |
| earth | Zone earth modifier | `zset <zone> earth <-1000..1000>` |
| wind | Zone wind modifier | `zset <zone> wind <-1000..1000>` |
| fire | Zone fire modifier | `zset <zone> fire <-1000..1000>` |
| water | Zone water modifier | `zset <zone> water <-1000..1000>` |
| shadow | Zone shadow modifier | `zset <zone> shadow <-1000..1000>` |
| dawn | Zone dawn message | `zset <zone> dawn <text>` |
| sunrise | Zone sunrise message | `zset <zone> sunrise <text>` |
| dusk | Zone dusk message | `zset <zone> dusk <text>` |
| sunset | Zone sunset message | `zset <zone> sunset <text>` |

---

## WORKFLOW EXAMPLE: Building a Complete Zone Room

**Step 1: Create the room**
```
rinit 1050 north
```
- Creates room 1050
- Links north to current room

**Step 2: Name it**
```
rname The Mystical Forest Clearing
```

**Step 3: Set description**
```
rdesc
# (Editor opens, type description, end with @)
```

**Step 4: Set sector type**
```
rsector forest
```

**Step 5: Create additional exits**
```
rlink east 1051
rlink south 1052
rlink west 1053
```

**Step 6: Add doors to some exits**
```
rdoor east wooden door
rkey east 5012 25
```

**Step 7: Add a gate**
```
rgate south iron gate
rkey south 5015
```

**Step 8: Check your work**
```
rsector
rdesc reformat
rlist +clearing
```

**Step 9: Save**
```
zsave 10
```

---

## BEST PRACTICES AND TIPS

1. **Always use "zsave all" or specific zone after building** - Changes are not permanent until saved
2. **Check runused before picking vnums** - Avoid conflicts with existing rooms
3. **Use rdesc reformat** - Cleans up old descriptions periodically
4. **Test exits** - Walk through and make sure all connections work bidirectionally
5. **Set keys before gates/doors** - Logical workflow for security
6. **Use rlist to verify** - Double-check rooms exist and have correct properties
7. **Name rooms clearly** - Use descriptive names for building management
8. **Use consistent sectors** - Helps with environmental effects consistency
9. **Clone similar rooms** - Faster than creating from scratch
10. **Back up regularly** - Use zsave all frequently during building

---

## TECHNICAL CONSTANTS

```cpp
ZONE_SIZE           1000        // Rooms per zone (0-999)
MAX_ZONE            100         // Zones 0-99
MAX_INPUT_LENGTH    256         // Input buffer size
MAX_STRING_LENGTH   4096        // Description max
ROOM_MAX            100000      // Max possible room vnums (approx)
LAST_DIR            10          // Number of directions
```

---

## DIRECTION NAMES

```
North       (0)
South       (1)
East        (2)
West        (3)
Up          (4)
Down        (5)
Northeast   (6)
Northwest   (7)
Southeast   (8)
Southwest   (9)
```

---

## CONTACT AND REFERENCES

All commands are implemented in [src/olc.cpp](src/olc.cpp) in the zone and room building functions starting around line 2029 onwards.

See [structs.h](structs.h) for ROOM_DATA and ROOM_DIRECTION_DATA structure definitions.

