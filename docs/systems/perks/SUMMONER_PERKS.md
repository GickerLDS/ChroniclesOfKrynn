# Summoner Perk Trees

## Overview
Summoners are masters of conjuration magic who forge powerful bonds with their eidolons and command creatures from across the planes. They have three main perk trees focusing on different aspects of summoning mastery.

**Class Focus:** Summoners excel at:
- Commanding and enhancing their personal eidolon companion
- Summoning creatures through Summon Creature I-IX spells
- Casting arcane spells with a focus on conjuration and support magic

**Total Design Budget:** 120 points worth of perks (for 90 perk points earned)

---

## Tree 1: Eidolon Mastery (45 points total)
*Enhance the bond with your eidolon, unlocking new evolutions and abilities*

### Tier 1 Perks (1 point each)

1. **Evolution Pool I**
   - Cost: 1 point per rank
   - Max Rank: 3
   - Effect: +1 evolution point for your eidolon per rank
   - Prerequisite: None
   - Notes: Allows more evolutions to be selected during eidolon customization

2. **Eidolon Resilience I**
   - Cost: 1 point per rank
   - Max Rank: 5
   - Effect: +5 hit points to your eidolon per rank
   - Prerequisite: None
   - Notes: Increases eidolon survivability

3. **Natural Armor Enhancement I**
   - Cost: 1 point per rank
   - Max Rank: 3
   - Effect: +1 natural armor bonus to eidolon per rank
   - Prerequisite: None
   - Notes: Stacks with EVOLUTION_IMPROVED_NATURAL_ARMOR

4. **Bond of Life**
   - Cost: 1 point
   - Max Rank: 1
   - Effect: Rejuvenate Eidolon spells heal +10% HP
   - Prerequisite: None
   - Notes: Enhances SPELL_LESSER_REJUVENATE_EIDOLON, SPELL_REJUVENATE_EIDOLON, SPELL_GREATER_REJUVENATE_EIDOLON

---

### Tier 2 Perks (2 points each)

5. **Evolution Pool II**
   - Cost: 2 points per rank
   - Max Rank: 2
   - Effect: +1 additional evolution point per rank
   - Prerequisite: Evolution Pool I (max)
   - Notes: Total of +5 evolution points with max ranks

6. **Eidolon Resilience II**
   - Cost: 2 points per rank
   - Max Rank: 3
   - Effect: +10 hit points to your eidolon per rank
   - Prerequisite: Eidolon Resilience I (max)
   - Notes: Significant HP boost for tougher encounters

7. **Enhanced Evolution: Attacks**
   - Cost: 2 points
   - Max Rank: 1
   - Effect: All eidolon natural attacks deal +2 damage
   - Prerequisite: Natural Armor Enhancement I (2 ranks)
   - Notes: Applies to bite, claws, gore, tentacle, etc.

8. **Shield Ally Enhancement**
   - Cost: 2 points
   - Max Rank: 1
   - Effect: Shield ally bonus increases by +1 (from +2 to +3, etc.)
   - Prerequisite: Bond of Life
   - Notes: Enhances the get_shield_ally_bonus() function

9. **Rapid Summoning**
   - Cost: 2 points
   - Max Rank: 1
   - Effect: Reduce eidolon summoning cooldown by 25%
   - Prerequisite: None
   - Notes: Reduces CALL_EIDOLON_COOLDOWN

10. **Evolution Surge Enhancement**
    - Cost: 2 points
    - Max Rank: 1
    - Effect: Evolution Surge spells last +2 rounds
    - Prerequisite: Evolution Pool I (1 rank)
    - Notes: Extends SPELL_LESSER_EVOLUTION_SURGE, SPELL_EVOLUTION_SURGE, SPELL_GREATER_EVOLUTION_SURGE

---

### Tier 3 Perks (3-4 points each)

11. **Evolution Pool III**
    - Cost: 3 points
    - Max Rank: 1
    - Effect: +2 evolution points
    - Prerequisite: Evolution Pool II (max)
    - Notes: Total of +7 evolution points possible

12. **Natural Armor Enhancement II**
    - Cost: 3 points per rank
    - Max Rank: 2
    - Effect: +2 natural armor bonus to eidolon per rank
    - Prerequisite: Natural Armor Enhancement I (max)
    - Notes: Significant AC improvement

13. **Enhanced Evolution: Magic**
    - Cost: 3 points
    - Max Rank: 1
    - Effect: Eidolon magic abilities (Basic/Minor/Major/Ultimate Magic) gain +1 spell DC
    - Prerequisite: Enhanced Evolution: Attacks
    - Notes: Applies to evolutions EVOLUTION_BASIC_MAGIC, EVOLUTION_MINOR_MAGIC, EVOLUTION_MAJOR_MAGIC, EVOLUTION_ULTIMATE_MAGIC

14. **Eidolon Spell Resistance**
    - Cost: 4 points
    - Max Rank: 1
    - Effect: Eidolon gains spell resistance equal to 11 + summoner level
    - Prerequisite: Eidolon Resilience II (2 ranks)
    - Notes: Supplements EVOLUTION_SPELL_RESISTANCE

15. **Life Link Enhancement**
    - Cost: 3 points
    - Max Rank: 1
    - Effect: When eidolon takes damage, you can choose to take half that damage instead (once per round)
    - Prerequisite: Bond of Life, Shield Ally Enhancement
    - Notes: Tactical ability to protect eidolon

16. **Merge Forms Enhancement**
    - Cost: 3 points
    - Max Rank: 1
    - Effect: While merged with eidolon, gain +2 to all physical stats (STR/DEX/CON)
    - Prerequisite: Eidolon Resilience II (1 rank)
    - Notes: Enhances EIDOLON_MERGE_FORMS_EFFECT

---

### Tier 4 Capstone Perks (5+ points each)

17. **Aspect Master**
    - Cost: 5 points
    - Max Rank: 1
    - Effect: +3 evolution points, eidolon attacks count as epic for DR purposes
    - Prerequisite: Evolution Pool III, Enhanced Evolution: Attacks
    - Notes: Total of +10 evolution points, upgrades EVOLUTION_MAGIC_ATTACKS

18. **Eternal Bond**
    - Cost: 5 points
    - Max Rank: 1
    - Effect: Eidolon summoning cooldown reduced by 50%, eidolon gains fast healing 3
    - Prerequisite: Rapid Summoning, Eidolon Resilience II (max)
    - Notes: Significantly reduces downtime, supplements EVOLUTION_FAST_HEALING

19. **Twin Eidolon**
    - Cost: 6 points
    - Max Rank: 1
    - Effect: Can summon a temporary duplicate of your eidolon once per day (lasts 5 rounds)
    - Prerequisite: Aspect Master
    - Notes: Creates a tactical copy with same evolutions but reduced HP (50%)

20. **Planar Unity**
    - Cost: 5 points
    - Max Rank: 1
    - Effect: +20 HP to eidolon, +4 natural armor, eidolon immune to mind-affecting
    - Prerequisite: Natural Armor Enhancement II (max), Eidolon Spell Resistance
    - Notes: Ultimate defensive enhancement

**Tree 1 Total: 45 points possible**

---

## Tree 2: Summoning Excellence (42 points total)
*Master the art of conjuration, summoning more powerful creatures with enhanced abilities*

### Tier 1 Perks (1 point each)

21. **Extended Summoning I**
    - Cost: 1 point per rank
    - Max Rank: 3
    - Effect: Summon Creature spells last +10% longer per rank
    - Prerequisite: None
    - Notes: Applies to SPELL_SUMMON_CREATURE_1 through SPELL_SUMMON_CREATURE_9

22. **Augmented Summoning I**
    - Cost: 1 point per rank
    - Max Rank: 3
    - Effect: Summoned creatures gain +1 HP per hit die and +1 to attack rolls per rank
    - Prerequisite: None
    - Notes: Enhances all mag_summons() creatures

23. **Efficient Summoning I**
    - Cost: 1 point per rank
    - Max Rank: 3
    - Effect: All summon spells are cast as if quickened.
    - Prerequisite: None

24. **Summoner's Bond**
    - Cost: 1 point
    - Max Rank: 1
    - Effect: Summoner gains +1 dodge ac and +1 to attacks when fighting with a summoned creature.
    - Prerequisite: None

---

### Tier 2 Perks (2 points each)

25. **Extended Summoning II**
    - Cost: 2 points per rank
    - Max Rank: 2
    - Effect: Additional +5% duration to summon duration per rank
    - Prerequisite: Extended Summoning I (max)
    - Notes: Long-lasting summons for extended encounters

26. **Augmented Summoning II**
    - Cost: 2 points per rank
    - Max Rank: 2
    - Effect: Summoned creatures gain +2 HP per hit die and +1 damage per rank
    - Prerequisite: Augmented Summoning I (max)
    - Notes: Significant power boost to summons

27. **Elemental Affinity**
    - Cost: 2 points
    - Max Rank: 1
    - Effect: Summoned elementals deal +10% damage and have +10 HP
    - Prerequisite: Augmented Summoning I (2 ranks)
    - Notes: Applies to air/earth/fire/water elementals, SPELL_ELEMENTAL_SWARM

28. **Beast Commander**
    - Cost: 2 points
    - Max Rank: 1
    - Effect: Summoned creatures from nature (dire animals) gain +2 AC and +10% movement
    - Prerequisite: Augmented Summoning I (2 ranks)
    - Notes: Enhances MOB_DIRE_BADGER, MOB_DIRE_BOAR, MOB_DIRE_WOLF, MOB_DIRE_SPIDER, MOB_DIRE_BEAR, MOB_DIRE_TIGER

29. **Multiple Summons I**
    - Cost: 2 points
    - Max Rank: 1
    - Effect: 20% chance to summon one additional creature when casting Summon Creature I-III. This creature doesn't count against pet limits, but only has 1/2 the hp and 1/3 the duration. If any summon I-III mob dies or is dismissed, this creature is dismissed as well. Any gear should be given back to the master.
    - Prerequisite: Extended Summoning I (2 ranks)
    - Notes: Tactical advantage for lower-level summons

30. **Master Summoner**
    - Cost: 2 points
    - Max Rank: 1
    - Effect: Can control +1 additional summoned creature
    - Prerequisite: Summoner's Bond
    - Notes: Increases follower limit for summoned creatures

---

### Tier 3 Perks (3-4 points each)

31. **Extended Summoning III**
    - Cost: 3 points
    - Max Rank: 1
    - Effect: +5% to all summon durations
    - Prerequisite: Extended Summoning II (max)
    - Notes: Total of +13 rounds possible with all ranks

32. **Augmented Summoning III**
    - Cost: 3 points
    - Max Rank: 1
    - Effect: Summoned creatures gain +3 to all physical stats (STR/DEX/CON)
    - Prerequisite: Augmented Summoning II (max)
    - Notes: Major enhancement to summon effectiveness

33. **Elemental Mastery**
    - Cost: 4 points
    - Max Rank: 1
    - Effect: Summon specific elemental type (choice of 4), lasts 50% longer, +20% damage
    - Prerequisite: Elemental Affinity
    - Notes: Player chooses fire/earth/air/water specialization

34. **Multiple Summons II**
    - Cost: 3 points
    - Max Rank: 1
    - Effect: 20% chance to summon additional creature extends to Summon Creature IV-VI. This creature doesn't count against pet limits, but only has 1/2 the hp and 1/3 the duration.  If any summon IV-VI mob dies or is dismissed, this creature is dismissed as well. Any gear should be given back to the master.
    - Prerequisite: Multiple Summons I
    - Notes: More powerful summons can duplicate

35. **Planar Binding**
    - Cost: 3 points
    - Max Rank: 1
    - Effect: Summoned outsiders (genies, elementals) gain +5 spell resistance
    - Prerequisite: Augmented Summoning II (1 rank)
    - Notes: Applies to SPELL_DJINNI_KIND, SPELL_EFREETI_KIND, SPELL_MARID_KIND, SPELL_SHAITAN_KIND

36. **Summon Resilience**
    - Cost: 3 points per rank
    - Max Rank: 2
    - Effect: Summoned creatures gain damage reduction 2/- per rank
    - Prerequisite: Augmented Summoning II (max)
    - Notes: Makes summons more durable

---

### Tier 4 Capstone Perks (5+ points each)

37. **Overwhelming Summons**
    - Cost: 5 points
    - Max Rank: 1
    - Effect: All summoned creatures gain +5 to hit, +2d6 damage, +4 AC
    - Prerequisite: Augmented Summoning III, Elemental Mastery
    - Notes: Ultimate enhancement to summon combat power

38. **Superior Summoner**
    - Cost: 5 points
    - Max Rank: 1
    - Effect: Can control +1 additional summoned creature from summon creature I-IX spells
    - Prerequisite: Master Summoner, Multiple Summons II
    - Notes: Sets pfail to 0 for all summons

39. **Planar Champion**
    - Cost: 6 points
    - Max Rank: 1
    - Effect: Summoned creatures from summon creature I-IX spells are two levels higher.
    - Prerequisite: Overwhelming Summons
    - Notes: Early access to more powerful summons

40. **Eternal Swarm**
    - Cost: 5 points
    - Max Rank: 1
    - Effect: Summon Creature spells last 50% longer, cast 50% faster
    - Prerequisite: Extended Summoning III, Superior Summoner
    - Notes: Reduces casting time and maximizes duration

**Tree 2 Total: 42 points possible**

---

## Tree 3: Arcane Channeler (45 points total)
*Enhance your spellcasting abilities, spell versatility, and magical prowess*

### Tier 1 Perks (1 point each)

41. **Spell Focus: Conjuration I**
    - Cost: 1 point per rank
    - Max Rank: 3
    - Effect: +1 DC to all conjuration spells per rank
    - Prerequisite: None
    - Notes: Primary school for summoners

42. **Charisma Enhancement I**
    - Cost: 1 point per rank
    - Max Rank: 3
    - Effect: +1 to effective Charisma for spell DC calculations per rank
    - Prerequisite: None
    - Notes: Increases spell save DCs across the board

43. **Spell Penetration I**
    - Cost: 1 point per rank
    - Max Rank: 3
    - Effect: +2 to overcome spell resistance per rank
    - Prerequisite: None
    - Notes: Essential for high-level encounters

44. **Efficient Casting I**
    - Cost: 1 point per rank
    - Max Rank: 3
    - Effect: 5% chance per rank to cast spells as quickened (sxame effect as quicken spell metamagic but without the spell level change)
    - Prerequisite: None
    - Notes: Resource management, stacks with Efficient Summoning

---

### Tier 2 Perks (2 points each)

45. **Spell Focus: Conjuration II**
    - Cost: 2 points per rank
    - Max Rank: 2
    - Effect: Additional +1 DC to conjuration spells per rank
    - Prerequisite: Spell Focus: Conjuration I (max)
    - Notes: Total of +5 DC possible

46. **Spell Focus: Abjuration**
    - Cost: 2 points
    - Max Rank: 1
    - Effect: +2 DC to abjuration spells, +1 caster level for abjuration
    - Prerequisite: Spell Focus: Conjuration I (2 ranks)
    - Notes: Enhances protective spells

47. **Charisma Enhancement II**
    - Cost: 2 points per rank
    - Max Rank: 2
    - Effect: +1 per rank to any GET_CHA_BONUS() checks
    - Prerequisite: Charisma Enhancement I (max)
    - Notes: Total of +5 effective Charisma possible

48. **Spell Penetration II**
    - Cost: 2 points
    - Max Rank: 1
    - Effect: +4 additional to overcome spell resistance
    - Prerequisite: Spell Penetration I (max)
    - Notes: Total of +10 to SR checks

49. **Extended Spell Knowledge I**
    - Cost: 2 points
    - Max Rank: 1
    - Effect: Can cast +1 bonus spell per spell circle (1st-3th level)
    - Prerequisite: Charisma Enhancement I (2 ranks)
    - Notes: Increases known spell count for summoners

50. **Empopwer Spell**
    - Cost: 2 points
    - Max Rank: 1
    - Effect: 10% chance that any spell cast is cast as empowered (as the metamagic effect without the spell level increase)
    - Prerequisite: Spell Focus: Conjuration I (max)
    - Notes: Metamagic-like ability

---

### Tier 3 Perks (3-4 points each)

51. **Spell Focus: Conjuration III**
    - Cost: 3 points
    - Max Rank: 1
    - Effect: +2 DC to conjuration spells
    - Prerequisite: Spell Focus: Conjuration II (max)
    - Notes: Total of +7 DC possible, devastating for save-or-suck spells

52. **Spell Focus: Transmutation**
    - Cost: 3 points
    - Max Rank: 1
    - Effect: +3 DC to transmutation spells, +1 caster level for transmutation
    - Prerequisite: Spell Focus: Conjuration II (1 rank)
    - Notes: Enhances buff/debuff versatility

53. **Arcane Supremacy**
    - Cost: 4 points
    - Max Rank: 1
    - Effect: +1 to all spell DCs, +2 to concentration checks
    - Prerequisite: Charisma Enhancement II (max), Spell Focus: Conjuration II (1 rank)
    - Notes: Broad enhancement to spellcasting

54. **Spell Penetration III**
    - Cost: 3 points
    - Max Rank: 1
    - Effect: +5 additional to overcome spell resistance
    - Prerequisite: Spell Penetration II
    - Notes: Total of +15 to SR checks

55. **Extended Spell Knowledge II**
    - Cost: 3 points
    - Max Rank: 1
    - Effect: Can cast +1 additional bonus spell per circle (levels 4-6)
    - Prerequisite: Extended Spell Knowledge I
    - Notes: Significant spell versatility

56. **Extend Spell**
    - Cost: 4 points
    - Max Rank: 1
    - Effect: 10% chance for any spell cast to be cast as if extended (as the metamagic effect but without changing the spell level)
    - Prerequisite: Heighten Spell, Efficient Casting I (2 ranks)
    - Notes: Powerful action economy ability

---

### Tier 4 Capstone Perks (5+ points each)

57. **Master of Conjuration**
    - Cost: 5 points
    - Max Rank: 1
    - Effect: Conjuration spells: +3 DC, +2 caster level
    - Prerequisite: Spell Focus: Conjuration III, Arcane Supremacy
    - Notes: Ultimate conjuration mastery

58. **Archmage's Insight**
    - Cost: 5 points
    - Max Rank: 1
    - Effect: +2 to all spell DCs, +3 to concentration, immune to spell failure from armor
    - Prerequisite: Arcane Supremacy, Spell Penetration III
    - Notes: Broad powerful enhancement

59. **Epic Spellcasting**
    - Cost: 6 points
    - Max Rank: 1
    - Effect: +1 caster level to all spells, +3 effective Charisma
    - Prerequisite: Master of Conjuration, Archmage's Insight
    - Notes: Overall power increase

60. **Spell Weaver**
    - Cost: 5 points
    - Max Rank: 1
    - Effect: Can cast +1 spells per circle
    - Prerequisite: Extended Spell Knowledge II, Quicken Spell
    - Notes: Ultimate versatility and resource management

**Tree 3 Total: 45 points possible**

---

## Design Notes

### Balance Considerations
- **Evolution Points**: Maximum of +10 evolution points through perks allows for 2-3 additional major evolutions
- **Summoning Duration**: Extended Summoning tree provides up to +13 rounds (substantial but not infinite)
- **Spell DCs**: Maximum DC bonuses are competitive but not overwhelming (+7 Conjuration, +2 general)
- **Resource Management**: Multiple cost reduction options reward good perk allocation

### Synergies Between Trees
1. **Eidolon + Summoning**: Players can focus on both companion and tactical summons
2. **Eidolon + Arcane**: Enhances merged form combat and eidolon magic abilities
3. **Summoning + Arcane**: Creates a master conjurer with powerful summons and spells
4. **Tri-Spec Viable**: Players can dabble in all three for versatility

### Key Code Integration Points
- Evolution system (evolutions.h, evolutions.c)
- mag_summons() function (magic.c)
- Spell DC calculations (spell_parser.c)
- Eidolon summoning cooldown (limits.c)
- Summoner spell list (isSummonerMagic function)
- Shield ally system (get_shield_ally_bonus)
- Merge forms effect (EIDOLON_MERGE_FORMS_EFFECT)

### Implementation Priority
1. **Phase 1**: Basic numerical bonuses (HP, AC, damage, DCs)
2. **Phase 2**: Duration and resource management (summoning time, spell costs)
3. **Phase 3**: Advanced mechanics (multiple summons, merge forms enhancement)
4. **Phase 4**: Capstone abilities (twin eidolon, planar champion)

### Perk Point Economy
- **Tier 1**: 16 perks × average 2 ranks = ~32 points available
- **Tier 2**: 16 perks × average 1.5 ranks = ~24 points available
- **Tier 3**: 16 perks × 1 rank = ~48 points available  
- **Tier 4**: 12 perks × 1 rank = ~66 points available
- **Total**: 132 points available, players earn ~90 points = ~68% acquisition rate

Players will need to specialize to reach tier 4 capstones in any tree.

---

## Future Expansion Ideas
- Eidolon appearance customization perks
- Planar travel enhancements
- Genie pact specializations (matching djinni/efreeti/marid/shaitan)
- Team combat bonuses (eidolon + summoned creatures working together)
- Evolution research (unlock rare evolutions through perks)
