# Artificer Perk Trees

## Overview
Artificers in Luminari blend arcane method, magical engineering, and practical battlefield invention. This design takes inspiration from D&D artificer identity (infusions, flash-style support reactions, spell-storing/item mastery) and Pathfinder inventor/alchemist identity (gadgets, unstable overcharge, reconfiguration), while grounding effects in systems already present in this codebase (weird science devices, device recharge, salvage, metamagic science, and golem construction).

**Design goals:**
- 3 trees, 4 tiers each, 4 perks per tier
- Strong rank-based progression in early and mid tiers
- Encourage multiple viable artificer archetypes (support caster, device striker, construct commander)
- Keep crafting bonuses moderate so martificers do not over-index on economy/profession throughput

**Total layout:** 48 perks (12 per tier band across the class)

---

## Tree 1: Weird Science Engineering
*Focus: device performance, reliability, overcharge risk/reward, and combat use of inventions.*

### Tier 1 (1 point each)

1. **Device Efficiency I**
      - Cost: 3 points per rank
   - Max Rank: 1
   - Effect: Weird science devices gain +1 max use.
   - Prerequisite: None

2. **Stable Circuitry I**
      - Cost: 3 point per rank
   - Max Rank: 1
   - Effect: Reduce device DC penalty growth by 1 per rank when forcing exhausted devices.
   - Prerequisite: None

3. **Arcane Battery I**
      - Cost: 1 point per rank
   - Max Rank: 2
   - Effect: Reduce personal device recharge interval by 2 seconds per rank (minimum floor enforced globally).
   - Prerequisite: None

4. **Volatile Theorem**
      - Cost: 2 points
   - Max Rank: 1
   - Effect: Unlock `device overcharge` mode (toggle). Overcharge grants +10% spell effect magnitude but applies +2 extra instability/DC pressure on failure.
   - Prerequisite: None

### Tier 2 (2 points each)

5. **Device Efficiency II**
      - Cost: 4 points per rank
   - Max Rank: 1
   - Effect: Additional +1 max use per rank to devices.
   - Prerequisite: Device Efficiency I (3)

6. **Stable Circuitry II**
      - Cost: 2 points per rank
   - Max Rank: 2
   - Effect: 10% chance per rank that when a device would break, it doesn't. 5 minute cooldown.
   - Prerequisite: Stable Circuitry I (3)

7. **Dual-Layer Imprint**
      - Cost: 2 points per rank
   - Max Rank: 2
   - Effect: Devices with multiple spells gain +5% to damage and/or duration per rank
   - Prerequisite: Volatile Theorem

8. **Combat Calibration**
      - Cost: 2 points per rank
   - Max Rank: 2
   - Effect: +1 to save DCs per rank for violent device effects only.
   - Prerequisite: Arcane Battery I (1)

### Tier 3 (3 points each)

9. **Arcane Battery II**
      - Cost: 3 points per rank
   - Max Rank: 2
   - Effect: Additional 2 seconds faster recharge per rank; first recharge pulse after combat ends happens 1 tick sooner.
   - Prerequisite: Arcane Battery I (2)

10. **Predictive Venting**
      - Cost: 3 points per rank
   - Max Rank: 2
   - Effect: When a device would break, 10% per rank chance to instead become disabled for 30 seconds.
   - Prerequisite: Stable Circuitry II (1)

11. **Adaptive Payload**
      - Cost: 3 points per rank
   - Max Rank: 2
   - Effect: Violent devices gain +2 spell penetration style bonus per rank against resistive targets.
   - Prerequisite: Combat Calibration (1)

12. **Field Recompiler**
      - Cost: 3 points
   - Max Rank: 1
   - Effect: Once every 10 minutes, swap one spell in an existing device without destroying it (same violence category rules still apply).
   - Prerequisite: Dual-Layer Imprint (1)

### Tier 4 (5 points each)

13. **Master Battery Architecture**
      - Cost: 5 points
   - Max Rank: 1
   - Effect: Device recharge interval reduced by an additional 2 seconds; recharge has 5% chance on completion to recharge 2 uses instead of one.
   - Prerequisite: Arcane Battery II (2)

14. **Perfected Weird Science**
      - Cost: 5 points
   - Max Rank: 1
   - Effect: Overcharge no longer increases self-instability on success; retains risk on failure.
   - Prerequisite: Predictive Venting (2), Volatile Theorem

15. **Spell-Stored Cascade**
      - Cost: 5 points
   - Max Rank: 1
   - Effect: Once per combat, first device activation will deal +10% damage and/or duration
   - Prerequisite: Adaptive Payload (2)

16. **Unbound Invention**
      - Cost: 5 points
   - Max Rank: 1
   - Effect: +1 max active device slot and +1 max spell circle budget in weird science allocation rules.
   - Prerequisite: Field Recompiler

---

## Tree 2: Infusion & Battlefield Support
*Focus: infused utility, ally assistance, reaction-based support, and controlled magical augmentation.*

### Tier 1 (1 point each)

1. **Infusion Theory I**
      - Cost: 1 point per rank
   - Max Rank: 3
   - Effect: +1 save DC to artificer-delivered spell/device effects per rank (support/control only, excludes raw damage scaling).
   - Prerequisite: None

2. **Flash Insight I**
      - Cost: 1 point per rank
   - Max Rank: 3
   - Effect: Once per 5 minutes use a swift action to give an ally +1 per rank to their next saving throw or skill check.
   - Prerequisite: None

3. **Tool Adept**
      - Cost: 1 point per rank
   - Max Rank: 2
   - Effect: +1  per rank to disable device and use magic device checks
   - Prerequisite: None

4. **Emergency Infusion**
      - Cost: 1 point
   - Max Rank: 1
   - Effect: Swift action to give +2 to random ability score (str,con,dex,int,wis,cha) for 1 minute, 5 minute cooldown.
   - Prerequisite: None

### Tier 2 (2 points each)

5. **Infusion Theory II**
      - Cost: 2 points per rank
   - Max Rank: 2
   - Effect: Additional +1 DC per rank to eligible support/control effects.
   - Prerequisite: Infusion Theory I (3)

6. **Flash Insight II**
      - Cost: 4 points per rank
   - Max Rank: 1
   - Effect: Bonus increases to +2
   - Prerequisite: Flash Insight I (3)

7. **Resonant Imbuement**
      - Cost: 2 points per rank
   - Max Rank: 2
   - Effect: Beneficial single-target device buffs has a 10% chance per rank to affect a random other party member in the same room.
   - Prerequisite: Emergency Infusion

8. **Harmonic Stabilizers**
      - Cost: 2 points per rank
   - Max Rank: 2
   - Effect: +1 concentration and use magic device skill per rank 
   - Prerequisite: Tool Adept (1)

### Tier 3 (3 points each)

9. **Spell Matrix I**
      - Cost: 3 points per rank
   - Max Rank: 2
   - Effect: Store one additional prepared support spell profile per rank for quick deployment.
   - Prerequisite: Infusion Theory II (1)

10. **Aegis Protocol**
      - Cost: 3 points per rank
   - Max Rank: 2
   - Effect: When an ally within range takes spell damage, grant reactive shielding equal to 3% max HP per rank (internal cooldown).
   - Prerequisite: Flash Insight II (1)

11. **Reinforcing Motif**
      - Cost: 3 points per rank
   - Max Rank: 2
   - Effect: Buff durations from artificer support effects increase by 10% per rank (hard cap applies).
   - Prerequisite: Resonant Imbuement (1)

12. **Efficient Crafter**
      - Cost: 3 points
   - Max Rank: 1
   - Effect: +2 crafting check bonus and 10% reduced crafting time for non-legendary recipes only.
   - Prerequisite: Tool Adept (2)
   - Balance note: intentionally modest economy gain.

### Tier 4 (5 points each)

13. **Spell Matrix II**
      - Cost: 5 points
   - Max Rank: 1
   - Effect: Stored spell profiles can include one 3rd-circle equivalent support effect and swap instantly out of combat.
   - Prerequisite: Spell Matrix I (2)

14. **Genius Under Pressure**
      - Cost: 5 points
   - Max Rank: 1
   - Effect: Flash Insight can now target self or ally against death/poison-style saves with doubled bonus (once per short interval).
   - Prerequisite: Flash Insight II (2), Aegis Protocol (1)

15. **Soulbound Infusion**
      - Cost: 5 points
   - Max Rank: 1
   - Effect: Once per 15 minutes, when dropping to 0 HP, consume one active infusion to remain at 1 HP.
   - Prerequisite: Harmonic Stabilizers (2)

16. **Grand Artifice**
      - Cost: 5 points
   - Max Rank: 1
   - Effect: +1 to all saves per two active infused effects on your gear (up to +3).
   - Prerequisite: Reinforcing Motif (2), Spell Matrix II

---

## Tree 3: Construct Command
*Focus: golem handling, construct durability/throughput, tactical command, and frontline martificer identity.*

### Tier 1 (1 point each)

1. **Construct Tuning I**
      - Cost: 1 point per rank
   - Max Rank: 3
   - Effect: Your commanded construct gains +2% max HP and +1 accuracy per rank.
   - Prerequisite: None

2. **Command Uplink I**
      - Cost: 1 point per rank
   - Max Rank: 3
   - Effect: +1 command responsiveness per rank (faster command resolution / reduced idle delay).
   - Prerequisite: None

3. **Reinforced Chassis I**
      - Cost: 1 point per rank
   - Max Rank: 3
   - Effect: Construct gains +1 AC per rank and minor damage reduction scaling.
   - Prerequisite: None

4. **Battlefield Retrieval**
      - Cost: 1 point
   - Max Rank: 1
   - Effect: Unlock quick recall/redeploy command for active golem with brief lockout.
   - Prerequisite: None

### Tier 2 (2 points each)

5. **Construct Tuning II**
      - Cost: 2 points per rank
   - Max Rank: 2
   - Effect: Additional +3% max HP and +1 damage per rank to commanded construct.
   - Prerequisite: Construct Tuning I (3)

6. **Command Uplink II**
      - Cost: 2 points per rank
   - Max Rank: 2
   - Effect: Additional command latency reduction and +5% per rank chance to avoid command interruption.
   - Prerequisite: Command Uplink I (3)

7. **Arcane Servomotors**
      - Cost: 2 points per rank
   - Max Rank: 2
   - Effect: Construct movement and reposition speed +5% per rank.
   - Prerequisite: Battlefield Retrieval

8. **Golem Safeguards**
      - Cost: 2 points per rank
   - Max Rank: 2
   - Effect: Construct takes 5% less AoE damage per rank; immune to friendly knockdown effects.
   - Prerequisite: Reinforced Chassis I (2)

### Tier 3 (3 points each)

9. **Reinforced Chassis II**
      - Cost: 3 points per rank
   - Max Rank: 2
   - Effect: Additional +1 AC per rank and improved DR scaling vs non-magical attacks.
   - Prerequisite: Reinforced Chassis I (3)

10. **Tactical Directives**
      - Cost: 3 points per rank
   - Max Rank: 2
   - Effect: Unlock stance commands (`guard`, `pressure`) and grant +1 tactical bonus per rank in active stance.
   - Prerequisite: Command Uplink II (1)

11. **Companion Conduit**
      - Cost: 3 points per rank
   - Max Rank: 2
   - Effect: A portion of your infusion/support buffs transfer to construct at 30% per rank effectiveness.
   - Prerequisite: Arcane Servomotors (1)

12. **Salvage Discipline**
      - Cost: 3 points
   - Max Rank: 1
   - Effect: +5% salvage material chance and +5% mote chance from dismantle, no gold-yield increase.
   - Prerequisite: Construct Tuning II (1)
   - Balance note: crafting-adjacent but economy-capped.

### Tier 4 (5 points each)

13. **Master Construct Protocol**
      - Cost: 5 points
   - Max Rank: 1
   - Effect: Construct gains one extra action-equivalent command each combat round with reduced potency.
   - Prerequisite: Tactical Directives (2), Command Uplink II (2)

14. **Fortress Engine**
      - Cost: 5 points
   - Max Rank: 1
   - Effect: While construct is active, you and construct share 10% incoming damage (cannot reduce below 1).
   - Prerequisite: Reinforced Chassis II (2), Golem Safeguards (2)

15. **Arcana Siege Frame**
      - Cost: 5 points
   - Max Rank: 1
   - Effect: Construct basic attacks gain conditional anti-resistance profile and one short-cooldown slam with knockback.
   - Prerequisite: Construct Tuning II (2), Companion Conduit (1)

16. **Omni-Forge Commander**
      - Cost: 5 points
   - Max Rank: 1
   - Effect: Once per long interval, instantly refit active construct mode (defense/offense/support) out of combat; first command in next combat is free.
   - Prerequisite: Master Construct Protocol, Arcana Siege Frame

---

## Balance & Scope Notes

### Crafting restraint policy (for martificer balance)
Only three perks directly improve crafting/salvage throughput:
- **Efficient Crafter** (modest +2 check, 10% time only)
- **Salvage Discipline** (+material/mote chance only, no gold boost)
- Existing baseline class feat **Elbow Grease** remains primary crafting driver

This keeps artificer power centered on combat invention, support reactions, and construct play rather than economy dominance.

### Suggested implementation priority
1. Tree 1 Tier 1-2 (device reliability/recharge) using existing device systems
2. Tree 2 Tier 1-2 (flash/support reactions + infusion scaling)
3. Tree 3 Tier 1-2 (construct command quality-of-life)
4. Tier 3-4 capstones after telemetry and balance testing

### Existing code systems this aligns with
- Weird science device creation/use/cooldown and instability handling
- Out-of-combat device recharge cadence
- Metamagic science hooks
- Salvage and crafting check pipelines
- Construct/golem crafting command flow
