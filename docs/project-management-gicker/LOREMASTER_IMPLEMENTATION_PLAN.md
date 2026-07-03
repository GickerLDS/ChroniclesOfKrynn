# Loremaster Prestige Class Implementation Plan

This plan adds the Pathfinder 1e **Loremaster** prestige class to Chronicles of Krynn. It incorporates the Opus writer/codebase research and the GPT adversarial review findings through the final correction pass.

## 1. Rules Target

### Class chassis

| Property | Implementation target |
| --- | --- |
| Class slot | Reuse `CLASS_PLACEHOLDER_2` slot 37 as `CLASS_LOREMASTER` |
| Levels | 10-level prestige class |
| Hit die | d6 |
| Skill points | 4 + Intelligence modifier |
| BAB | Low progression |
| Saves | Good Will only; Fortitude and Reflex poor (`assign_class_saves(CLASS_LOREMASTER, B, B, G, B, B)`) |
| Proficiencies | None; do not grant weapon or armor proficiency |
| Spellcasting | At every Loremaster level, choose one eligible pre-existing spellcasting class to advance |

### Class skills

Set the following to class skills in `assign_class_abils(CLASS_LOREMASTER, ...)`:

- Appraise
- Diplomacy
- Handle Animal
- Heal
- Knowledge equivalents: `ABILITY_LORE`/`ABILITY_ARCANA`, `ABILITY_HISTORY`, `ABILITY_RELIGION`, `ABILITY_NATURE`/`ABILITY_SURVIVAL`
- Linguistics
- Perform
- Spellcraft
- Use Magic Device

All other abilities should remain cross-class unless the existing engine convention for knowledge/caster classes requires otherwise.

### Feature schedule

| Level | Feature | Spellcasting |
| --- | --- | --- |
| 1 | Secret | +1 existing spellcasting class |
| 2 | Lore | +1 existing spellcasting class |
| 3 | Secret | +1 existing spellcasting class |
| 4 | Bonus language | +1 existing spellcasting class |
| 5 | Secret | +1 existing spellcasting class |
| 6 | Greater Lore | +1 existing spellcasting class |
| 7 | Secret | +1 existing spellcasting class |
| 8 | Bonus language | +1 existing spellcasting class |
| 9 | Secret | +1 existing spellcasting class |
| 10 | True Lore | +1 existing spellcasting class |

## 2. Slot 37 Conversion

Reuse slot 37 to avoid changing `NUM_CLASSES`/`MAX_CLASSES` and resizing persisted class-indexed arrays.

Update all placeholder touchpoints:

| File | Required change |
| --- | --- |
| `src/structs.h` | Rename `CLASS_PLACEHOLDER_2 37` to `CLASS_LOREMASTER 37`; optionally keep a compatibility alias only if needed |
| `src/class.c` | Replace the placeholder `classo(...)` block with the full Loremaster definition |
| `src/constants.c` | Update `class_names[]` row 37 to `"Loremaster"` |
| `src/constants.c` | Keep `spell_prep_dict[][4]` row 37 present with empty strings; update the comment to Loremaster |
| `src/constants.c` | Keep `spell_consign_dict[][4]` row 37 present with empty strings; update the comment to Loremaster |
| `src/constants.c` | Add a real `class_short_descriptions[]` row 37 blurb |
| `src/casting_visuals.c` | Replace the index-37 placeholder/`NULL` visual style with Loremaster flavor |
| `src/perks.c` | Add prestige-aware perk routing for `CLASS_LOREMASTER` |

After implementation, `grep -rn "CLASS_PLACEHOLDER_2\|Placeholder 2" src --include='*.c' --include='*.h'` should find only an intentional alias, if one remains.

## 3. Entry Prerequisites

Do **not** use only `class_prereq_ability`, `class_prereq_feat`, or `CLASS_PREREQ_SPELLCASTING` for Loremaster. The existing prerequisite list is AND-oriented and cannot express the class correctly. Also avoid `CASTING_TYPE_ANY`; the current implementation in `class.c` is known to be inverted/buggy.

Add a custom prerequisite type, for example:

```c
#define CLASS_PREREQ_LOREMASTER 12
```

Then add a registrar such as `class_prereq_loremaster(CLASS_LOREMASTER)` and a `CLASS_PREREQ_LOREMASTER` case in `meets_class_prerequisite()` that calls `loremaster_meets_prereqs(ch)`.

The custom checker must enforce all of the following:

1. **Knowledge ranks:** at least two distinct Knowledge-equivalent abilities at 7 ranks or more. Count from `ABILITY_LORE`/`ABILITY_ARCANA`, `ABILITY_HISTORY`, `ABILITY_RELIGION`, and `ABILITY_NATURE`/`ABILITY_SURVIVAL`.
2. **Knowledge Skill Focus:** `Skill Focus` must be attached to one of those Knowledge-equivalent abilities. The correct macro order is:

   ```c
   HAS_SKILL_FEAT(ch, ability, feat_to_skfeat(FEAT_SKILL_FOCUS))
   ```

   Do not accept generic Skill Focus on a non-Knowledge skill.
3. **Three qualifying feats:** count any mix of metamagic feats and the explicit item-creation feat list. Use `feat_list[i].feat_type == FEAT_TYPE_METAMAGIC` for metamagic. For item creation, enumerate only:
   - `FEAT_BREW_POTION`
   - `FEAT_CRAFT_MAGICAL_ARMS_AND_ARMOR`
   - `FEAT_CRAFT_ROD`
   - `FEAT_CRAFT_STAFF`
   - `FEAT_CRAFT_WAND`
   - `FEAT_CRAFT_WONDEROUS_ITEM`
   - `FEAT_FORGE_RING`
   - `FEAT_SCRIBE_SCROLL`

   Do not count every `FEAT_TYPE_CRAFT` feat; that category includes mundane/racial crafting feats.
4. **Seven divination spells:** count seven distinct divination spell IDs the character can actually cast, with at least one castable as a 3rd-circle-or-higher spell by one of the character's own casting classes. The high-level check must use the spell circle for a class the character can actually cast with, not the minimum circle across unrelated classes.

Recommended divination algorithm:

1. Iterate each candidate spellcasting class the character has.
2. For each spell in that class's accessible/known/prepared/spellbook source, check `spell_info[spellnum].schoolOfMagic == DIVINATION`.
3. Count each spell ID once, using a `seen[TOP_SPELL_DEFINE]`/similar guard.
4. Set `has_third_or_higher = true` if `compute_spells_circle(ch, class, spellnum, METAMAGIC_NONE, domain)` or the class's spell assignment for that same castable class is `>= 3`.
5. Require `distinct_divinations >= 7 && has_third_or_higher`.

Mirror this custom logic in the class-prerequisite display so players can see which subrequirements are failing.

## 4. Spellcasting Advancement

Pathfinder Loremaster chooses which eligible spellcasting class to advance **at each Loremaster level**. It is not fixed at first Loremaster level.

### Existing prestige caster preference helper

The repo already has a global prestige-caster preference helper:

- `GET_PREFERRED_ARCANE(ch)` / `GET_PREFERRED_DIVINE(ch)` in `utils.h`
- Saved as `PCAr` / `PCDi` in `players.c`
- Edited through the `Preferred Caster Classes (Prestige)` study menu in `study.c` (`set_preferred_caster`, `set_preferred_arcane`, `set_preferred_divine`, `STUDY_SET_P_CASTER`)
- Used primarily for routing prestige-class known-spell menus, such as Sorcerer/Bard/Summoner/Inquisitor known-spell selection

Reuse that UI/pattern where it helps, but do **not** use those two global fields as Loremaster's only source of truth. They are character-wide arcane/divine preferences, not per-Loremaster-level advancement choices. They also cannot represent advancing Wizard at Loremaster 1, Cleric at Loremaster 2, Bard at Loremaster 3, etc. Loremaster therefore needs the per-level storage below, while its study menus can borrow the existing preferred-caster menu style and known-spell routing patterns.

### Eligible classes

Eligible classes are Vancian/spontaneous spellcasting classes whose progression can be advanced through `BONUS_CASTER_LEVEL` and related slot/circle code:

- Wizard
- Sorcerer
- Bard
- Summoner
- Cleric
- Druid
- Ranger
- Paladin
- Inquisitor

Exclude Warlock, Psionicist, prestige classes, and other pseudo-casters whose spell/power progression is not driven by this path. Exclude Alchemist unless the implementation first adds explicit `BONUS_CASTER_LEVEL` support for Alchemist extracts and validates that all extract-slot/known-extract logic respects it.

### Pre-existing class enforcement

The class advanced at a Loremaster level must be a spellcasting class the character belonged to before adding the Loremaster prestige level. Because the repo does not persist class-level acquisition history, add a snapshot.

Persist:

```c
int loremaster_entry_classes[NUM_CLASSES];
int loremaster_caster_class[10];
```

- `loremaster_entry_classes[class]` is set when the character takes the first Loremaster level, before the level is finalized. It records eligible spellcasting classes with `CLASS_LEVEL(ch, class) > 0`.
- `loremaster_caster_class[level_index]` stores which class is advanced by each Loremaster level, where `level_index = loremaster_level - 1`.
- For legacy characters with Loremaster levels but no snapshot, fall back safely by rebuilding eligibility from existing spellcasting class levels once, then persist the rebuilt snapshot.

At each Loremaster level, the study UI should list only classes in `loremaster_entry_classes[]` that are also in the eligible spellcasting set. Do not require the chosen class itself to cast 3rd-circle spells; that is only an entry prerequisite.

### Level-up overlay

During `study`, the current Loremaster level's choice lives in `LEVELUP(ch)`, but slot previews and known-spell menus need to see it before finalization. Add helper functions that overlay staged data:

```c
int loremaster_levels_advancing(struct char_data *ch, int class);
int loremaster_levels_advancing_arcane(struct char_data *ch);
int loremaster_levels_advancing_divine(struct char_data *ch);
```

These helpers must count persisted `loremaster_caster_class[]` and, when `LEVELUP(ch) && LEVELUP(ch)->class == CLASS_LOREMASTER`, also include the staged current-level choice from `LEVELUP`.

Use these helpers in:

- `compute_bonus_caster_level()`
- `compute_arcane_level()`
- `compute_divine_level()`
- any study-time slot/known-spell preview helpers that cannot safely call the normal path

On finalize, copy the staged `LEVELUP` arrays back into saved fields. Block finalization while the current Loremaster advancement class is unset.

### Known-spell routing

For spontaneous known-spell classes, use the staged chosen advancement class to show the correct known-spell menu before finalization:

- Sorcerer → sorcerer known-spells menu
- Bard → bard known-spells menu
- Summoner → summoner known-spells menu
- Inquisitor → inquisitor known-spells menu

Prepared classes need no known-spell menu.

## 5. Secrets

Secrets are selected at Loremaster levels 1, 3, 5, 7, and 9. A secret may be selected only once, and only if:

```c
CLASS_LEVEL(ch, CLASS_LOREMASTER) + GET_INT_BONUS(ch) >= secret_threshold
```

Use a dedicated selection/storage system modeled on paladin mercies or alchemist discoveries, not generic class-feat points.

Persist:

```c
int loremaster_secrets[NUM_LOREMASTER_SECRETS];
int loremaster_instant_mastery_skill;
int loremaster_applicable_knowledge_feat;
int loremaster_newfound_class;
int loremaster_more_newfound_class;
```

Recommended tags: `LrSc`, `LrIM`, `LrAK`, `LrNf`, `LrMn`.

### Secret table and effects

| Threshold | Secret | Implementation |
| --- | --- | --- |
| 1 | Instant Mastery | Choose a skill with 0 ranks; grant exactly 4 ranks. Store the chosen skill and revalidate at finalize. |
| 2 | Secret Health | Grant PF Toughness-equivalent benefit through a dedicated Loremaster effect/feat, not repo `FEAT_TOUGHNESS`. |
| 3 | Secrets of Inner Strength | Direct +2 Will save bonus in `saving_throws()`. Do not grant Iron Will. |
| 4 | Lore of True Stamina | Direct +2 Fortitude save bonus in `saving_throws()`. Do not grant Great Fortitude. |
| 5 | Secret Knowledge of Avoidance | Direct +2 Reflex save bonus in `saving_throws()`. Do not grant Lightning Reflexes. |
| 6 | Weapon Trick | Direct +1 attack bonus in the attack-bonus path. Do not grant Weapon Finesse or Weapon Focus. |
| 7 | Dodge Trick | Direct +1 dodge AC in `compute_armor_class()`/dodge bonus handling. Do not grant Dodge. |
| 8 | Applicable Knowledge | Choose any feat for which the character meets prerequisites; store the selected feat ID and grant it on finalize without consuming normal feat points. |
| 9 | Newfound Arcana | Choose one eligible spellcasting class; grant one bonus 1st-circle slot for that class only. |
| 10 | More Newfound Arcana | Choose one eligible spellcasting class; grant one bonus 2nd-circle slot for that class only. |

### Secret Health

Secret Health grants **Toughness as a bonus feat**. Repo `FEAT_TOUGHNESS` is not Pathfinder Toughness; it is implemented as +1 HP per level per rank and can stack by rank. To keep the class feature rules-accurate without changing the existing global feat, add a dedicated PF-accurate bonus-feat wrapper, `FEAT_LOREMASTER_SECRET_HEALTH`, named/described as the Loremaster's Toughness bonus feat.

```c
if (HAS_FEAT(ch, FEAT_LOREMASTER_SECRET_HEALTH))
  max_hp += MAX(3, GET_LEVEL(ch));
```

Selecting Secret Health grants this bonus feat. It should not increment repo `FEAT_TOUGHNESS` ranks. If any code later needs to ask whether the character has "Toughness" for rules purposes, add a helper such as `has_pathfinder_toughness(ch)` that returns true for either repo `FEAT_TOUGHNESS` or `FEAT_LOREMASTER_SECRET_HEALTH`, rather than overloading the existing ranked feat storage.

### Applicable Knowledge

Add a subchoice flow:

1. Selecting Applicable Knowledge opens a feat-selection menu filtered by `feat_is_available(ch, feat, ...)`/existing prerequisite checks.
2. Store the selected feat ID in `loremaster_applicable_knowledge_feat` and in `LEVELUP`.
3. Block finalization until a feat is selected.
4. Revalidate prerequisites at finalize.
5. Grant the feat directly and mark the Applicable Knowledge secret selected.

This subchoice must not use or decrement normal feat/class-feat points.

### Newfound Arcana target classes

Newfound and More Newfound each target exactly one selected spellcasting class. The target class must be able to cast the relevant spell circle after applying committed and staged Loremaster advancement: circle 1 for Newfound Arcana and circle 2 for More Newfound Arcana. Do not allow the player to select a class that cannot use the slot.

Inject slots only for the stored class and fixed circle:

```c
if (circle == 1 &&
    HAS_FEAT(ch, FEAT_LOREMASTER_NEWFOUND_ARCANA) &&
    class == GET_LOREMASTER_NEWFOUND_CLASS(ch))
  spell_slots++;

if (circle == 2 &&
    HAS_FEAT(ch, FEAT_LOREMASTER_MORE_NEWFOUND_ARCANA) &&
    class == GET_LOREMASTER_MORE_NEWFOUND_CLASS(ch))
  spell_slots++;
```

The target class choice must be stored and persisted. It must not grant bonus slots to every class the Loremaster has advanced.

## 6. Lore, Greater Lore, and True Lore

### Lore

At level 2, grant `FEAT_LORE`.

Effect:

- Add `CLASS_LEVEL(ch, CLASS_LOREMASTER) / 2` to all Knowledge-equivalent checks.
- Allow Knowledge checks untrained.
- Stack with Bardic Knowledge.

Code surfaces:

- `spec_procs.c::compute_ability_full()` for `ABILITY_LORE`, `ABILITY_HISTORY`, `ABILITY_RELIGION`, and `ABILITY_SURVIVAL`/`ABILITY_NATURE`.
- `act.other.c::do_lore()` raw `GET_ABILITY` gate: allow if `HAS_FEAT(ch, FEAT_LORE)`.
- `act.other.c::do_glore()` raw `GET_ABILITY` gate: allow if `HAS_FEAT(ch, FEAT_LORE)`.
- `act.informative.c::eqstats` benefits automatically if it calls `compute_ability`; clamp `lore_app[]` indexing to avoid over-read when bonuses are high.

### Greater Lore

At level 6, grant `FEAT_GREATER_LORE`.

Pathfinder gives +10 circumstance bonus on Spellcraft checks to identify magic item properties. This engine identifies item properties through the object branch of `can_lore_target()` and through `eqstats`, not a separate Spellcraft item-ID path. Implement the class feature as a faithful engine adaptation:

- In `act.other.c::can_lore_target()`, object branch only, compare the normal Knowledge total against `compute_ability(ch, ABILITY_SPELLCRAFT) + 10` when `HAS_FEAT(ch, FEAT_GREATER_LORE)`, and use the better total for the item-property DC.
- In `act.informative.c::eqstats`, use the better of normal Lore total and `Spellcraft + 10` for worn-item property identification when `HAS_FEAT(ch, FEAT_GREATER_LORE)`.
- Do not edit `act.item.c:83`; it is only a forward declaration of `can_lore_target()`. Existing act.item callers should benefit through the real `can_lore_target()` definition.

Greater Lore is item-identification-specific; do not add +10 to all Spellcraft or all Knowledge checks.

### True Lore

At level 10, grant `FEAT_TRUE_LORE`.

Implement `truelore` as a 1/day command offering:

- Analyze dweomer style reveal: full magical properties of an item/creature target.
- Legend lore style reveal: lore on a named subject/item, with 1-minute delayed/interruptible casting time.

Required command gating:

- Add `ACMD_DECL(do_truelore);` in `act.h`.
- Add `ACMDCHECK(can_truelore);` in `act.h`.
- Implement `can_truelore` with `ACMDCHECK_PREREQ_HASFEAT(FEAT_TRUE_LORE, ...)` and a daily-use check.
- Register the interpreter command with the `can_truelore` check pointer, not `NULL`.
- `do_truelore` should also call `PREREQ_CHECK(can_truelore)` before performing the effect.

Required daily-use/event wiring:

1. Add `FEAT_TRUE_LORE` to `get_daily_uses()` with exactly 1 use/day.
2. Append `eTRUE_LORE` after the current final event enum `eBASTION_COOLDOWN` in `mud_event.h`.
3. Append the matching `mud_event_index[]` row in `mud_event_list.c` at the final position.
4. Update `mud_event.c::init_events()` expected-size validation from `(size_t)eBASTION_COOLDOWN + 1` to `(size_t)eTRUE_LORE + 1`.
5. Add `dailyfeat(FEAT_TRUE_LORE, eTRUE_LORE)` in `feats.c`.
6. Add `players.c` event-save whitelist handling for `eTRUE_LORE` near other daily feat cooldowns. `load_events()` is generic, but save is manual and must include the new event.
7. On successful command use, call `start_daily_use_cooldown(ch, FEAT_TRUE_LORE)`.

## 7. Bonus Languages

At Loremaster levels 4 and 8, add one bonus language slot each. Add a shared helper:

```c
int loremaster_bonus_languages(struct char_data *ch)
{
  return (CLASS_LEVEL(ch, CLASS_LOREMASTER) >= 4) +
         (CLASS_LEVEL(ch, CLASS_LOREMASTER) >= 8);
}
```

Apply it to all language-cap calculations:

- `class.c::has_unchosen_languages()`
- `study.c::choose_languages()`
- `study.c` `STUDY_CHOOSE_LANGUAGES` handler

Changing only `class.c` is insufficient; the study display and enforcement recompute the cap.

## 8. Feats and OLC Modes

Append feat IDs only. Do not renumber existing feats.

| Feat | ID |
| --- | --- |
| `FEAT_LORE` | 1266 |
| `FEAT_GREATER_LORE` | 1267 |
| `FEAT_TRUE_LORE` | 1268 |
| `FEAT_LOREMASTER_NEWFOUND_ARCANA` | 1269 |
| `FEAT_LOREMASTER_MORE_NEWFOUND_ARCANA` | 1270 |
| `FEAT_LOREMASTER_SECRET_HEALTH` | 1271 |

Then update:

```c
#define FEAT_LAST_FEAT 1272
#define NUM_FEATS 1273
```

Add `feato(...)` registrations for each new feat as class abilities.

Current max study mode is 78. Add new modes after it:

```c
#define STUDY_SELECT_LOREMASTER_ADVANCE 79
#define STUDY_SELECT_LOREMASTER_SECRET 80
#define STUDY_INSTANT_MASTERY_SKILL 81
#define STUDY_NEWFOUND_CLASS 82
#define STUDY_MORE_NEWFOUND_CLASS 83
#define STUDY_APPLICABLE_KNOWLEDGE_FEAT 84
```

## 9. Persistence

Add saved fields to `player_special_data_saved` and mirrored fields to `level_up`.

| Field | Suggested tag | Default |
| --- | --- | --- |
| `loremaster_entry_classes[NUM_CLASSES]` | `LrEn` | all 0; legacy rebuild fallback |
| `loremaster_caster_class[10]` | `LrAd` | `CLASS_UNDEFINED` |
| `loremaster_secrets[NUM_LOREMASTER_SECRETS]` | `LrSc` | all 0 |
| `loremaster_instant_mastery_skill` | `LrIM` | `-1` |
| `loremaster_applicable_knowledge_feat` | `LrAK` | `FEAT_UNDEFINED` |
| `loremaster_newfound_class` | `LrNf` | `CLASS_UNDEFINED` |
| `loremaster_more_newfound_class` | `LrMn` | `CLASS_UNDEFINED` |
| True Lore cooldown | `Evnt` block | absent = available |

Use existing array save/load patterns such as mercies/discoveries. Ensure level-up finalization copies all staged values from `LEVELUP` to saved fields.

## 10. Perks

`class_to_perk_class()` has no `ch`, so it cannot resolve per-level Loremaster advancement. Add the real logic to `get_award_perk_classes()`:

- For `CLASS_LOREMASTER`, inspect `loremaster_caster_class[]`.
- Route perk points to the most-advanced base spellcasting class.
- If multiple classes tie, use a deterministic order documented in code: highest Loremaster advancement count, then highest base class level, then lowest class ID.
- Add only a static fallback to `class_to_perk_class()` so no path returns `-1`.

## 11. Validation

Primary build options already present in this repo:

- Autotools/root Makefile: `make circle` builds the main binary target when the generated Makefile is present.
- CMake: `cmake --build build/ --target circle` when `build/` is configured.
- If neither is configured: `cmake -S . -B build/ && cmake --build build/ --target circle`.

Run the smallest applicable test/build path after implementation:

1. Build with the configured path (`make circle` or CMake target).
2. Run existing unit tests available in the repo (`make check` or the relevant CuTest target if configured).
3. Grep audit:
   - `grep -rn "CLASS_PLACEHOLDER_2\|Placeholder 2" src`
   - `grep -rn "eTRUE_LORE" src/mud_event.h src/mud_event_list.c src/mud_event.c src/players.c src/feats.c`
4. Manual QA:
   - Verify exact prerequisites, including Knowledge-only Skill Focus and divination spell level for an actually castable class.
   - Take Loremaster levels 1-10 and choose different advancement classes.
   - Confirm current-level study previews use staged advancement.
   - Verify all secrets, including Applicable Knowledge subchoice and Newfound target-class slots.
   - Verify Lore untrained use, Greater Lore item identification, bonus languages at levels 4 and 8.
   - Use True Lore, save/relog/reboot, and confirm cooldown persists.

## 12. Implementation Sequence

1. Slot 37 rename and placeholder table updates.
2. Feat IDs, OLC modes, persistence fields, and access macros.
3. Class registration with chassis, saves, skills, titles, no proficiencies.
4. Custom Loremaster prerequisite checker and display.
5. Entry snapshot and per-level spellcasting advancement storage/UI.
6. LEVELUP overlay helpers and known-spell routing.
7. Secret selection system, subchoices, direct effects, and finalize gates.
8. Lore, Greater Lore, bonus languages, and True Lore command/event/cooldown.
9. Perk routing.
10. Save/load, build, unit validation, and manual QA.
