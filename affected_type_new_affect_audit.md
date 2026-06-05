# affected_type variables without new_affect initialization

Scope: source files under `src/`. Build artifacts were ignored. Pointer-only declarations were ignored because they do not create a fresh `struct affected_type`.

## No `new_affect` before applying the affect

| Declaration | Function | What happens before apply | Apply site |
| --- | --- | --- | --- |
| `src/alchemy.c:4289` | `do_poisontouch` | `struct affected_type af;` is populated directly; no zeroing or `new_affect(&af)` seen. | `src/alchemy.c:4298` |
| `src/spec_abilities.c:1054` | `armor_specab_blinding` | `struct affected_type af[2];` elements are populated directly; no zeroing or `new_affect(&(af[i]))` seen. | `src/spec_abilities.c:1122` |
| `src/spec_procs.c:4814` | `shar_heart` | `struct affected_type af;` is populated directly; no zeroing or `new_affect(&af)` seen. | `src/spec_procs.c:4847` |
| `src/spec_procs.c:4893` | `dog` | `struct affected_type af;` is populated directly; no zeroing or `new_affect(&af)` seen. | `src/spec_procs.c:4935` |
| `src/spec_procs.c:10802` | `menzo_chokers` | `struct affected_type af;` is populated directly; no zeroing or `new_affect(&af)` seen. | `src/spec_procs.c:10837` |
| `src/traps.c:220` | `event_trap_triggered` | Manually initializes selected fields and `bitvector`; no `new_affect(&af)` seen. | `src/traps.c:505` |
| `src/traps_new.c:1603` | `event_trap_triggered` | Manually initializes selected fields and `bitvector`; no `new_affect(&af)` seen. | `src/traps_new.c:1878` |

## Zeroed or cleared, but still no `new_affect`

| Declaration | Function | Alternate initialization seen | Apply site |
| --- | --- | --- | --- |
| `src/act.offensive.c:16329` | `apply_natures_wrath_buff` | `memset(&af, 0, sizeof(af))` at `src/act.offensive.c:16330`; reused for multiple applications. | first apply at `src/act.offensive.c:16335` |
| `src/magic.c:3939` | `mag_damage` | `memset(&af, 0, sizeof(af))` at `src/magic.c:3940`. | `src/magic.c:3946` |
| `src/magic.c:3962` | `mag_damage` | `memset(&af, 0, sizeof(af))` at `src/magic.c:3963`. | `src/magic.c:3969` |
| `src/magic.c:3984` | `mag_damage` | `memset(&af, 0, sizeof(af))` at `src/magic.c:3985`. | `src/magic.c:3991` |
| `src/magic.c:13248` | `mag_summons` | `memset(&af, 0, sizeof(af))` at `src/magic.c:13249`. | `src/magic.c:13254` |
| `src/spells.c:2210` | `spell_alter_self` | Same `af` variable is reset with `memset(&af, 0, sizeof(af))` before each application at `src/spells.c:2262`, `src/spells.c:2272`, `src/spells.c:2282`, and `src/spells.c:2293`. | `src/spells.c:2270`, `src/spells.c:2278`, `src/spells.c:2288`, `src/spells.c:2299` |
| `src/specs.artifacts.c:94` | `OakenDefender` | `bzero(&af, sizeof(af))` at `src/specs.artifacts.c:216`. | `src/specs.artifacts.c:221` |
| `src/specs.artifacts.c:1574` | `HornOfHenekar` | `bzero(&af, sizeof(af))` at `src/specs.artifacts.c:1813`. | `src/specs.artifacts.c:1818` |
