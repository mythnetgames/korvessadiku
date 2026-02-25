-- ============================================================================
-- Korvessa: 7-Stat to 6-Stat Migration
-- ============================================================================
-- This script migrates the database schema from the original 7-stat system
-- (STR, INT, WIL, CON, DEX, AUR, AGI) to the new 6-stat system
-- (STR, INT, WIS, CON, DEX, CHA).
--
-- Mapping:
--   WIL -> WIS  (rename)
--   AUR -> CHA  (rename)
--   AGI -> DEX  (merged — AGI bonus folded into DEX, column dropped)
--
-- BACK UP YOUR DATABASES BEFORE RUNNING THIS SCRIPT.
-- ============================================================================

-- ---------------------------------------------------------------------------
-- 1. PFILES TABLE (rpi_player database)
-- ---------------------------------------------------------------------------

-- Merge AGI into DEX: take the higher of the two values for each character.
-- This preserves the "better" stat after the merge.
UPDATE pfiles SET dex = GREATEST(COALESCE(dex, 0), COALESCE(agi, 0))
  WHERE agi IS NOT NULL AND agi > dex;

UPDATE pfiles SET start_dex = GREATEST(COALESCE(start_dex, 0), COALESCE(start_agi, 0))
  WHERE start_agi IS NOT NULL AND start_agi > start_dex;

-- Rename WIL -> WIS
ALTER TABLE pfiles CHANGE COLUMN `wil` `wis` int(11) default NULL;

-- Rename AUR -> CHA
ALTER TABLE pfiles CHANGE COLUMN `aur` `cha` int(11) default NULL;

-- Drop AGI (data already merged into DEX above)
ALTER TABLE pfiles DROP COLUMN `agi`;

-- Rename start stats
ALTER TABLE pfiles CHANGE COLUMN `start_wil` `start_wis` int(11) default NULL;
ALTER TABLE pfiles CHANGE COLUMN `start_aur` `start_cha` int(11) default NULL;
ALTER TABLE pfiles DROP COLUMN `start_agi`;


-- ---------------------------------------------------------------------------
-- 2. PFILES_ALPHA_BACKUP TABLE (if it exists — same schema as pfiles)
-- ---------------------------------------------------------------------------

-- Merge AGI into DEX
UPDATE pfiles_alpha_backup SET dex = GREATEST(COALESCE(dex, 0), COALESCE(agi, 0))
  WHERE agi IS NOT NULL AND agi > dex;

UPDATE pfiles_alpha_backup SET start_dex = GREATEST(COALESCE(start_dex, 0), COALESCE(start_agi, 0))
  WHERE start_agi IS NOT NULL AND start_agi > start_dex;

ALTER TABLE pfiles_alpha_backup CHANGE COLUMN `wil` `wis` int(11) default NULL;
ALTER TABLE pfiles_alpha_backup CHANGE COLUMN `aur` `cha` int(11) default NULL;
ALTER TABLE pfiles_alpha_backup DROP COLUMN `agi`;
ALTER TABLE pfiles_alpha_backup CHANGE COLUMN `start_wil` `start_wis` int(11) default NULL;
ALTER TABLE pfiles_alpha_backup CHANGE COLUMN `start_aur` `start_cha` int(11) default NULL;
ALTER TABLE pfiles_alpha_backup DROP COLUMN `start_agi`;


-- ---------------------------------------------------------------------------
-- 3. RACES TABLE (rpi_engine database)
-- ---------------------------------------------------------------------------
-- Original column order: str_mod, con_mod, dex_mod, agi_mod, int_mod, wil_mod, aur_mod
-- After migration:       str_mod, con_mod, dex_mod, int_mod, wis_mod, cha_mod
--
-- Since AGI merged into DEX, add agi_mod bonus to dex_mod for each race.
-- (Races that had bonuses to both AGI and DEX keep the sum.)
UPDATE races SET dex_mod = dex_mod + agi_mod WHERE agi_mod != 0;

-- Drop agi_mod
ALTER TABLE races DROP COLUMN `agi_mod`;

-- Rename wil_mod -> wis_mod
ALTER TABLE races CHANGE COLUMN `wil_mod` `wis_mod` smallint(6) default '0';

-- Rename aur_mod -> cha_mod
ALTER TABLE races CHANGE COLUMN `aur_mod` `cha_mod` smallint(6) default '0';


-- ---------------------------------------------------------------------------
-- 4. VERIFY
-- ---------------------------------------------------------------------------
-- After running, confirm columns with:
--   DESCRIBE pfiles;
--   DESCRIBE races;
--
-- Expected pfiles stat columns (in order):
--   str, intel, wis, con, dex, cha,
--   start_str, start_intel, start_wis, start_con, start_dex, start_cha
--
-- Expected races mod columns (in order):
--   str_mod, con_mod, dex_mod, int_mod, wis_mod, cha_mod
-- ============================================================================
