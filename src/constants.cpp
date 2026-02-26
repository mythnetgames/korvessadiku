/*------------------------------------------------------------------------\
 |  constants.c : Program Constants                    www.middle-earth.us |
 |  Copyright (C) 2004, Shadows of Isildur: Traithe                        |
 |  Derived under license from DIKU GAMMA (0.0).                           |
 \------------------------------------------------------------------------*/

#include "structs.h"



const char *verbal_number[] = {
  "zero",
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eight",
  "nine",
  "ten",
  "eleven",
  "twelve",
  "thirteen",
  "fourteen",
  "fifteen",
  "sixteen",
  "seventeen",
  "eighteen",
  "nineteen",
  "twenty",
  "twenty one",
  "twenty two",
  "twenty three",
  "twenty four",
  "twenty five",
  "twenty six",
  "twenty seven",
  "twenty eight",
  "twenty nine",
  "thirty",
  "thirty one",
  "thirty two",
  "thirty three",
  "thirty four",
  "thirty five",
  "thirty six",
  "thirty seven",
  "thirty eight",
  "thirty nine",
  "forty",
  "forty one",
  "forty two",
  "forty three",
  "forty four",
  "forty five",
  "forty six",
  "forty seven",
  "forty eight",
  "forty nine",
  "fifty",
  "fifty one",
  "fifty two",
  "fifty three",
  "fifty four",
  "fifty five",
  "fifty six",
  "fifty seven",
  "fifty eight",
  "fifty nine",
  "sixty",
  "sixty one",
  "sixty two",
  "sixty three",
  "sixty four",
  "sixty five",
  "sixty six",
  "sixty seven",
  "sixty eight",
  "sixty nine",
  "seventy",
  "seventy one",
  "seventy two",
  "seventy three",
  "seventy four",
  "seventy five",
  "seventy six",
  "seventy seven",
  "seventy eight",
  "seventy nine",
  "eighty",
  "eighty one",
  "eighty two",
  "eighty three",
  "eighty four",
  "eighty five",
  "eighty six",
  "eighty seven",
  "eighty eight",
  "eighty nine",
  "ninety",
  "ninety one",
  "ninety two",
  "ninety three",
  "ninety four",
  "ninety five",
  "ninety six",
  "ninety seven",
  "ninety eight",
  "ninety nine",
  "one hundred",
  "\n"
};


const char *verbose_dirs[] = {
  "the north",
  "the east",
  "the south",
  "the west",
  "above",
  "below",
  "outside",
  "inside",
  "the northeast",
  "the northwest",
  "the southeast",
  "the southwest",
  "the upper north",
  "the upper east",
  "the upper south",
  "the upper west",
  "the upper northeast",
  "the upper northwest",
  "the upper southeast",
  "the upper southwest",
  "the lower north",
  "the lower east",
  "the lower south",
  "the lower west",
  "the lower northeast",
  "the lower northwest",
  "the lower southeast",
  "the lower southwest"
  "\n"
};

const char *season_string[] = {
  "spring",
  "summer",
  "autumn",
  "winter",
  "\n"
};

const char *that_time_of_day[] = {
  "day",
  "night",
  "\n"
  };

const char *month_short_name[12] = {
  "Plowbreak",
  "Seedwake",
  "Sproutmere",
  "Tallgrow",
  "Sunpress",
  "Firstreap",
  "Fullreap",
  "Stubblewake",
  "Turnsoil",
  "Coldroot",
  "Storethin",
  "Lastseed"
};

const char *month_lkup[] = {
  "(null)",
  "Plowbreak",
  "Seedwake",
  "Sproutmere",
  "Tallgrow",
  "Sunpress",
  "Firstreap",
  "Fullreap",
  "Stubblewake",
  "Turnsoil",
  "Coldroot",
  "Storethin",
  "Lastseed",
  "\n"
};

const char *weekday_name[DAYS_PER_WEEK] = {
  "Eveday",
  "Watchday",
  "Trialday",
  "Velorday",
  "Feyday",
  "Regaldy"
};

const char *weekday_theme[DAYS_PER_WEEK] = {
  "Beginnings and Intent",
  "Scrutiny and Truth",
  "Learning and Testing",
  "Discipline and Service",
  "Chance and Risk",
  "Authority and Consequence"
};

const char *patron_name[] = {
  "None",
  "Velora",
  "The Watcher",
  "The Three Children",
  "Feyliks",
  "Regalus",
  "Superstition",
  "\n"
};

/*
 * Holiday table: 3 holidays per month, 12 months = 36 entries.
 * { month (0-based), day (1-based), patron, short_name, description }
 */
struct holiday_data holiday_table[NUM_HOLIDAYS] = {
  /* Plowbreak */
  { MONTH_PLOWBREAK,    3,  PATRON_VELORA,       "Turning Oath",
    "Followers of Velora reaffirm discipline. Tools are cleaned and checked." },
  { MONTH_PLOWBREAK,   12,  PATRON_WATCHER,      "The Watched Furrow",
    "Fields are worked in silence. Lies spoken today are said to surface later." },
  { MONTH_PLOWBREAK,   21,  PATRON_SUPERSTITION, "The Uneven Line",
    "One furrow is plowed crooked to confuse ill fate." },

  /* Seedwake */
  { MONTH_SEEDWAKE,      2,  PATRON_THREE,        "Casting of Hands",
    "The young and inexperienced are set to sow. Effort matters more than result." },
  { MONTH_SEEDWAKE,     11,  PATRON_WATCHER,      "Held Seed",
    "No planting is done. Blight following this day is blamed on those who ignored the warning." },
  { MONTH_SEEDWAKE,     23,  PATRON_FEYLIKS,      "Open Palm",
    "Seed is shared freely, gambled, or traded. Hoarding sours fortune." },

  /* Sproutmere */
  { MONTH_SPROUTMERE,    5,  PATRON_VELORA,       "Green Oath",
    "Commitments are renewed. Contracts sworn today are expected to endure hardship." },
  { MONTH_SPROUTMERE,   14,  PATRON_THREE,        "Small Feet",
    "Children and apprentices walk the fields. Negligence by elders is not forgiven." },
  { MONTH_SPROUTMERE,   26,  PATRON_WATCHER,      "Watching Leaves",
    "Fields are inspected closely. Blight found after today is blamed on willful blindness." },

  /* Tallgrow */
  { MONTH_TALLGROW,      4,  PATRON_VELORA,       "Bound Work",
    "Crops are tied and corrected. Neglect here is remembered at harvest." },
  { MONTH_TALLGROW,     13,  PATRON_FEYLIKS,      "Foolstep",
    "Risky labor is undertaken deliberately. Failure is blamed on luck, not skill." },
  { MONTH_TALLGROW,     22,  PATRON_SUPERSTITION, "The Quiet Mark",
    "Midday labor pauses briefly. Ignoring the pause invites injury." },

  /* Sunpress */
  { MONTH_SUNPRESS,      6,  PATRON_WATCHER,      "Thirstcount",
    "Water stores are measured honestly. Lying about supply is believed to draw drought." },
  { MONTH_SUNPRESS,     15,  PATRON_VELORA,       "Heat Mercy",
    "Excessive punishment and labor are avoided. Cruelty today is remembered." },
  { MONTH_SUNPRESS,     27,  PATRON_SUPERSTITION, "Flygift",
    "Food is left out for vermin spirits to keep them from livestock." },

  /* Firstreap */
  { MONTH_FIRSTREAP,     1,  PATRON_VELORA,       "First Sheaf",
    "The earliest harvest is cut carefully. Waste today is deeply frowned upon." },
  { MONTH_FIRSTREAP,    10,  PATRON_FEYLIKS,      "Bread of Chance",
    "First loaves from new grain are eaten. Ill fortune blamed on luck, not milling." },
  { MONTH_FIRSTREAP,    19,  PATRON_WATCHER,      "Counted Silence",
    "Harvest totals are tallied quietly. Boasting invites suspicion." },

  /* Fullreap */
  { MONTH_FULLREAP,      3,  PATRON_REGALUS,      "Open Field",
    "Harvest begins under authority. Theft during this period carries harsh consequence." },
  { MONTH_FULLREAP,     16,  PATRON_VELORA,       "Measure True",
    "Weights and measures are checked. False accounting is treated as deliberate crime." },
  { MONTH_FULLREAP,     28,  PATRON_FEYLIKS,      "Feast of Plenty",
    "Excess is permitted briefly. Those who abstain are assumed fearful." },

  /* Stubblewake */
  { MONTH_STUBBLEWAKE,   7,  PATRON_THREE,        "Gleaning Right",
    "The landless may gather remains. Denial is seen as cruelty." },
  { MONTH_STUBBLEWAKE,  18,  PATRON_SUPERSTITION, "Herd Turn",
    "Livestock are moved. Injuries are blamed on poor fortune rather than skill." },
  { MONTH_STUBBLEWAKE,  25,  PATRON_WATCHER,      "The Last Look",
    "Fields are inspected one final time. Missed harvest is blamed on neglect." },

  /* Turnsoil */
  { MONTH_TURNSOIL,      4,  PATRON_REGALUS,      "Second Claim",
    "Land boundaries are reaffirmed or seized. Authority asserted now is expected to hold." },
  { MONTH_TURNSOIL,     14,  PATRON_SUPERSTITION, "Ashmark",
    "Controlled burning is permitted. Fire afterward is unforgivable." },
  { MONTH_TURNSOIL,     26,  PATRON_VELORA,       "Broken Spade",
    "Tools that fail are repaired or discarded. Using broken tools is stubborn pride." },

  /* Coldroot */
  { MONTH_COLDROOT,      5,  PATRON_VELORA,       "Rootpull",
    "Root crops are harvested carefully. Delay beyond today is blamed for rot." },
  { MONTH_COLDROOT,     17,  PATRON_WATCHER,      "Cellar Seal",
    "Stores are closed and counted. Missing goods spark accusations." },
  { MONTH_COLDROOT,     24,  PATRON_SUPERSTITION, "Mistwalk",
    "Travel avoided where possible. Loss today is attributed to fate." },

  /* Storethin */
  { MONTH_STORETHIN,     6,  PATRON_REGALUS,      "Short Measure",
    "Rations are reduced by decree. Failure to comply is treated as defiance." },
  { MONTH_STORETHIN,    15,  PATRON_WATCHER,      "Quiet Hearth",
    "Social visits decline. Secrets shared are believed remembered." },
  { MONTH_STORETHIN,    27,  PATRON_FEYLIKS,      "Coin Turn",
    "Last risky trades before scarcity bites. Loss is blamed on chance." },

  /* Lastseed */
  { MONTH_LASTSEED,      3,  PATRON_WATCHER,      "Final Count",
    "Stores are tallied honestly. Lies now are remembered into the next year." },
  { MONTH_LASTSEED,     14,  PATRON_VELORA,       "Hard Night",
    "No excess is permitted. Discipline is observed openly." },
  { MONTH_LASTSEED,     30,  PATRON_REGALUS,      "Dominion Mark",
    "The year ends in authority. Debts are named, punishments declared." }
};

const char *somatics[] = {
  "an unknown somatic effect",
  "a headache",
  "a minor concussion",
  "a major concussion",
  "a broken left arm",
  "a broken right arm",
  "a broken right leg",
  "a broken rib",
  "a mysterious illness",
  "an admin punishment",
  "a severed right arm",
  "a severed left arm",
  "a severed right leg",
  "a severed leg leg",
  "a severed head",
  "a severed torso",
  "a severed right hand",
  "a severed right leg",
  "a severed head",
  "\n"
};


const char *skills[] = {
  "Unused", // 0
  "Brawling",         // 1
  "Small-Blade",      // 2
  "Long-Blade",       // 3
  "Polearm",          // 4
  "Bludgeon",         // 5
  "Dodge",            // 6
  "Parry",            // 7  (was Deflect)
  "Sole-Wield",       // 8
  "Dual-Wield",       // 9
  "Aim",              // 10
  "Grapple",          // 11 (was Handgun)
  "Shortbow",         // 12 (was Rifle)
  "Longbow",          // 13 (was Machinegun)
  "Crossbow",         // 14 (was Gunnery)
  "Thrown",           // 15 (was Explosives)

  "Sneak",            // 16
  "Hide",             // 17
  "Steal",            // 18
  "Picklock",         // 19
  "Haggle",           // 20
  "Persuasion",       // 21 (was Handle)
  "Streetwise",       // 22 (was Hunting)
  "First-Aid",        // 23
  "Tracking",         // 24 (was Medicine)
  "Forage",           // 25
  "Eavesdrop",        // 26
  "Butchery",         // 27

  "Herbalism",        // 28 (was Chemistry)
  "Blacksmithing",    // 29 (was Mechanics)
  "Carpentry",        // 30 (was Gunsmith)
  "Appraise",         // 31 (was Computerology)
  "Investigation",    // 32 (was Electronics)
  "Lore",             // 33 (was Biology)
  "Weaponcraft",      // 34
  "Armorcraft",       // 35
  "Handicraft",       // 36
  "Artistry",         // 37

  "Education",        // 38
  "Sense-Motive",     // 39 (was Empathy)
  "Common",           // 40
  "Metalcraft",       // 41
  "Leathercraft",     // 42
  "Textilecraft",     // 43
  "Woodcraft",        // 44
  "Cooking",          // 45
  "Baking",           // 46
  "Brewing",          // 47
  "Fishing",          // 48
  "Stonecraft",       // 49
  "Earthencraft",     // 50
  "Gardening",        // 51
  "Farming",          // 52
  "Athletics",        // 53 (was Shortbow dup)
  "Bandaging",        // 54 (was Longbow dup)
  "Chirurgy",         // 55 (was Crossbow dup)
  "Music",            // 56
  "Meditation",       // 57 (was Astronomy)
  "Perception",       // 58 (was Orkish)
  "Handle",           // 59 (was Wargish - animal handling)
  "Hunting",          // 60 (was Dalish)
  "Endurance",        // 61 (was Sindarin)
  "Adaptability",     // 62 (was Khuzdul)
  "Climbing",         // 63 (was Tengwar)
  "Swimming",         // 64 (was Cirth)
  "Warcraft",         // 65
  "\n"
};

const char *where[] = {
  "<used as light>          ",	// 0
  "<worn on finger>         ",	// 1
  "<worn on finger>         ",
  "<worn at neck>           ",
  "<worn at neck>           ",
  "<worn on body>           ",
  "<worn on head>           ",
  "<worn on legs>           ",
  "<worn on feet>           ",
  "<worn on hands>          ",
  "<worn on arms>           ",	// 10
  "<worn as shield>         ",
  "<worn about body>        ",
  "<worn about waist>       ",
  "<worn on right wrist>    ",
  "<worn on left wrist>     ",
  "<wielded primary>        ",
  "<wielded secondary>      ",
  "<wielded both hands>     ",
  "<worn around the chest>  ",
  "<worn on belt>           ",	// 20
  "<worn on belt>           ",
  "<across the back>        ",
  "<over the eyes>          ",
  "<worn at throat>         ",
  "<worn on the ears>       ",
  "<worn over shoulder>     ",
  "<worn over shoulder>     ",
  "<worn on right ankle>    ",
  "<worn on left ankle>     ",
  "<worn in hair>           ",	// 30
  "<worn on face>           ",
  "",
  "",
  "<about upper right arm>  ",	// 34
  "<about upper left arm>   ",	// 35
  "<worn over the body>     ",	// 36
  "<worn over the eyes>     ",	// 37
  "<worn around the hips>   ",  // 38
  "<worn as an error>		",  // 39
  "\n"
};

const char *locations[] = {
  "hand",
  "finger",
  "finger",
  "neck",
  "neck",
  "body",
  "head",
  "legs",
  "feet",
  "hands",
  "arms",
  "hands",
  "body",
  "waist",
  "wrist",
  "wrist",
  "hand",
  "hand",
  "hand",
  "hand",
  "belt",
  "belt",
  "back",
  "eyes",
  "throat",
  "ears",
  "shoulder",
  "shoulder",
  "ankle",
  "ankle",
  "hair",
  "face",
  "something",
  "something",
  "arm",
  "arm",
  "body",
  "eyes",
  "\n"
};


const char *color_liquid[] = {
  "clear",
  "brown",
  "clear",
  "brown",
  "dark",
  "golden",
  "red",
  "green",
  "clear",
  "light green",
  "white",
  "brown",
  "black",
  "red",
  "clear",
  "black"
};

const char *fullness[] = {
  "less than half ",
  "about half ",
  "more than half ",
  ""
};


const char *exit_bits[] = {
  "IsDoor",
  "Closed",
  "Locked",
  "RSClosed",
  "RSLocked",
  "PickProof",
  "Secret",
  "Trapped",
  "Toll",
  "IsGate",
  "\n"
};

extern const int electric_list [] = {
	ITEM_E_RADIO,
	ITEM_E_LIGHT,
	ITEM_E_PHONE,
	ITEM_E_BOOST,
	ITEM_E_REMOTE,
	ITEM_E_ROBOT,
	ITEM_E_BUG,
	ITEM_E_CLOCK,
	ITEM_E_MEDICAL,
	ITEM_E_GOGGLE,
	ITEM_E_BOOK,
	ITEM_E_BREATHER,
};




const int earth_grid[] = {
  120,				/* Inside */
  320,				/* City */
  170,				/* Road */
  110,				/* Trail */
  100,				/* Field */
  90,				/* Woods */
  80,				/* Forest */
  80,				/* Hills */
  65,				/* Mountains */
  120,				/* Swamp */
  270,				/* Water_swim */
  340,				/* Water_noswim */
  585,				/* Ocean */
  510,				/* Dock */
  230,				/* Reef */
  580,				/* Crowsnest */
  135,				/* Pasture */
  95,				/* Heath */
  75,				/* Pit */
  100				/* Lean-to  */
};

const int wind_grid[] = {
  640,				/* Inside */
  175,				/* City */
  220,				/* Road */
  240,				/* Trail */
  80,				/* Field */
  240,				/* Woods */
  280,				/* Forest */
  120,				/* Hills */
  100,				/* Mountains */
  140,				/* Swamp */
  90,				/* Water_swim */
  60,				/* Water_noswim */
  50,				/* Ocean */
  75,				/* Dock */
  300,				/* Reef */
  55,				/* Crowsnest */
  120,				/* Pasture */
  65,				/* Heath */
  850,				/* Pit */
  100				/* Lean-to */
};

const int fire_grid[] = {
  120,				/* Inside */
  115,				/* City */
  175,				/* Road */
  190,				/* Trail */
  210,				/* Field */
  275,				/* Woods */
  350,				/* Forest */
  150,				/* Hills */
  135,				/* Mountains */
  475,				/* Swamp */
  525,				/* Water_swim */
  675,				/* Water_noswim */
  895,				/* Ocean */
  520,				/* Dock */
  475,				/* Reef */
  340,				/* Crowsnest */
  125,				/* Pasture */
  140,				/* Heath */
  125,				/* Pit */
  100				/* Lean-to  */
};

const int water_grid[] = {
  450,				/* Inside */
  275,				/* City */
  300,				/* Road */
  275,				/* Trail */
  200,				/* Field */
  140,				/* Woods */
  100,				/* Forest */
  175,				/* Hills */
  225,				/* Mountains */
  75,				/* Swamp */
  60,				/* Water_swim */
  50,				/* Water_noswim */
  30,				/* Ocean */
  65,				/* Dock */
  95,				/* Reef */
  100,				/* Crowsnest */
  275,				/* Pasture */
  175,				/* Heath */
  675,				/* Pit */
  100				/* Lean-to  */
};

const int shadow_grid[] = {
  70,				/* Inside */
  90,				/* City */
  200,				/* Road */
  320,				/* Trail */
  410,				/* Field */
  500,				/* Woods */
  540,				/* Forest */
  490,				/* Hills */
  570,				/* Mountains */
  70,				/* Swamp */
  500,				/* Water_swim */
  500,				/* Water_noswim */
  500,				/* Ocean */
  340,				/* Dock */
  300,				/* Reef */
  650,				/* Crowsnest */
  200,				/* Pasture */
  65,				/* Heath */
  520,				/* Pit */
  510,				/* Lean-to */
};



const char *seasons[] = {
  "Spring",
  "Summer",
  "Autumn",
  "Winter",
  "\n"
};

const char *affected_bits[] = {
  "Undefined",
  "Invisible",
  "Infravision",
  "Detect-Invisible",
  "Detect-Magic",
  "Sense-Life",			/* 5 */
  "Transporting",
  "Sanctuary",
  "Group",
  "Curse",
  "Magic-only",			/* 10 */
  "Poison",
  "AScan",
  "AFallback",
  "Undefined",
  "Undefined",			/* 15 */
  "Sleep",
  "Dodge",
  "ASneak",
  "AHide",
  "Fear",			/* 20 */
  "Follow",
  "Hooded",
  "Charm",			/* was affected_bits[21] */
  "\n"
};

const char *smallgood_types[] = {
  "smallgoods",
  "ore",
  "grain",
  "fur",
  "meat",
  "\n"
};

const char *action_bits[] = {
  "Memory",
  "Sentinel",
  "Rescuer",
  "IsNPC",
  "NoVNPC",
  "Aggressive",
  "Stayzone",
  "Fixer",
  "Sent-Aggro",
  "BulkTrader",
  "Shooter",
  "NoBuy",
  "Enforcer",
  "PackAnimal",
  "Vehicle",
  "Stop",
  "Squeezer",
  "Pariah",
  "Mount",
  "Scented",                   /* Mob has, or should have, some venom */
  "PCOwned",
  "Wildlife",			/* Mob won't attack other wildlife */
  "Stayput",			/* Mob saves and reloads after boot */
  "Passive",			/* Mob won't assist clan brother in combat */
  "Auctioneer",			/* Mob is an auctioneer - auctions.cpp */
  "Econzone",			/* NPC, if keeper, uses econ zone price dis/markups */
  "Jailer",
  "\n"
};


const char *position_types[] = {
  "Dead",
  "Mortally wounded",
  "Unconscious",
  "Stunned",
  "Sleeping",
  "Resting",
  "Sitting",
  "Fighting",
  "Standing",
  "\n"
};

const char *connected_types[] = {
  "Playing",
  "Entering Name",
  "Confirming Name",
  "Entering Password",
  "Entering New Password",
  "Confirming New password",
  "Choosing Gender",
  "Reading Message of the Day",
  "Main Menu",
  "Changing Password",
  "Confirming Changed Password",
  "Rolling Attributes",
  "Selecting Race",
  "Decoy Screen",
  "Creation Menu",
  "Selecting Attributes",
  "New Player Menu",
  "Documents Menu",
  "Selecting Documentation",
  "Reading Documentation",
  "Picking Skills",
  "New Player",
  "Age Select",
  "Height-Frame Select",
  "New Char Intro Msg",
  "New Char Intro Wait",
  "Creation Comment",
  "Read Reject Message",
  "Web Connection",
  "\n"
};

const char *sex_types[] = {
  "Sexless",
  "Male",
  "Female",
  "\n"
};

const char *sex_noun[] = {
  "it",
  "him",
  "her",
  "\n",
};

const char *weather_room[] = {
  "default",
  "foggy",
  "cloudy",
  "rainy",
  "stormy",
  "snowy",
  "blizzard",
   "\n"
};
