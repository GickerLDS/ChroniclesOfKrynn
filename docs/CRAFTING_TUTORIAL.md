# Crafting Tutorial

This guide walks through the core crafting loop in order: surveying, harvesting materials and motes, refining, and then creating and resizing items. It is based on the in-game crafting system plus the official wiki page at https://krynn.d20mud.com/wiki/crafting/.

## 1) Surveying (find harvestable resources)

Surveying gives you a random number of survey rooms, based on your surveying skill.

Commands:

```
survey
```

Notes:
- Surveying only works in valid harvesting sectors.
- Surveying grants a number of "survey rooms" which decrease each time you move room to room
- You must have survey rooms in order to harvest

## 2) Harvesting materials and motes

Harvesting requires survey rooms and extracts materials from the current room. You can also find crafting motes during harvesting.

Commands:

```
harvest
```

Requirements:
- You must have survey rooms available.
- The room must have harvestable materials.
- You must have the correct harvesting tool equipped for the material type.

Results:
- Materials are added to your crafting materials inventory.
- Motes can drop randomly; the type is random, and the amount scales with material grade.
- Use `materials` to view your current crafting materials.

Wiki references:
- Harvesting materials: https://krynn.d20mud.com/wiki/harvesting-crafting-materials/
- Crafting motes: https://krynn.d20mud.com/wiki/crafting-motes/

## 3) Refining materials

Some materials must be refined from raw materials using a refining station. Refining uses recipes and consumes ingredients.

Core flow:

```
refine add <refine_type>
refine show
refine begin
refine remove
```

Notes:
- Use `refine add` to pick a recipe and allocate required materials.
- You must be in a room with the correct refining station to begin. Stations are found in
	starting cities like Palanthas and Sanction.
- `refine show` displays allocated materials, result, and DC.
- `refine remove` cancels and returns allocated materials.

Wiki reference:
- Refining materials: https://krynn.d20mud.com/wiki/refining-materials/

## 4) Crafting items (variants, materials, bonuses, motes)

Crafting items is a multi-step setup followed by a start. You configure item type, specific type, variant, text, and then assign materials, bonuses, and motes as needed.

Typical setup flow:

```
craft itemtype <weapon|armor|misc|instrument>
craft specifictype <type>
craft variant <variant_name>
craft keywords <keyword string>
craft shortdesc <short description>
craft roomdesc <room description>
craft extradesc <extra description>
```

Add materials:

```
craft materials add <material>
craft materials remove <material>
```

Add bonuses and motes:

```
craft bonuses <slot> <bonus location> <bonus type> <modifier> <specific>
craft motes add <enhancement|quality|effectiveness|breakability|bonus_slot>
craft motes remove <enhancement|quality|effectiveness|breakability|bonus_slot>
```

Mote reference:

```
motes
```

Enhancement or instrument-specific settings:

```
craft enhancement <amount>
craft instrument <quality|effectiveness|breakability> <amount>
```

Review and start:

```
craft show
craft check
craft start
```

Explanation of the example:
We set the item to a weapon, chose the specific type (long sword) and the variant (broad sword), then provided the keyword and description text the game uses to display the item. We added the required materials (steel and low grade hide), set a +2 enhancement bonus, added motes for the enhancement, and added two bonus slots: +2 Strength (universal) and +4 Constitution (enhancement). We then assigned motes to both bonus slots so the bonuses can be applied. Finally, we reviewed the project, checked for missing requirements, and started the craft.

Notes:
- Variants control the material profile and descriptive requirements for the recipe.
- Motes are required for most bonus and enhancement effects.
- Some commands only apply to certain item types (for example, enhancement on weapons/armor).
- Crafting stations are required for many crafting and refining tasks and can be found in
	starting cities such as Palanthas and Sanction.

Complete example (weapon craft):

```
craft itemtype weapon
craft specifictype long sword
craft variant broad sword
craft keywords broad sword silver steel
craft shortdesc a silver steel broad sword
craft roomdesc A silver steel broad sword lies here.
craft materials add steel
craft materials add low grade hide
craft enhancement 2
craft motes add enhancement
craft bonuses 1 strength universal 2
craft bonuses 2 constitution enhancement 4
craft motes add 1
craft motes add 2
craft show
craft check
craft start
```

Wiki reference:
- Creating equipment: https://krynn.d20mud.com/wiki/creating-equipment/

## 5) Resizing crafted (and many existing) items

Resizing uses materials based on the object and target size. You must set the object and size, then allocate materials and begin.

Commands:

```
resize <object> <new_size>
resize add
resize show
resize begin
resize remove
```

Notes:
- `resize add` consumes materials based on object weight and size change.
- `resize begin` runs the resize skill check.
- `resize remove` cancels and refunds materials.

Wiki reference:
- Resizing gear: https://krynn.d20mud.com/wiki/resizing-gear/

## 6) Crafting talents

Crafting and harvesting skills level up as you work, and each skill rank can award crafting
talent points. Talents can improve speed, yield, and overall results.

Commands:

```
craft score
talents
```

Details:
- Use `craft score` to see your current crafting and harvesting skill ranks and progress.
- Skills gain experience when you successfully survey, harvest, refine, or craft items.
- When a skill rank increases, you earn talent points.
- Use `talents` to view available talent trees and spend points.
- Some talents improve harvest yields, refining efficiency, crafting speed, or crafting success.

## 7) Supply orders

Supply orders are structured crafting jobs that reward experience and currency. They are a good
way to level crafting skills.

Common flow:

```
supplyorder list
supplyorder select <id>
supplyorder show
supplyorder start
supplyorder material add <material>
supplyorder complete
```

Wiki reference:
- Supply orders: https://krynn.d20mud.com/wiki/crafting/

## 8) Crafting golems

Golem crafting is a specialized crafting path that creates controllable golem followers. You set
type and size, then start construction. Golems can be recalled, upgraded, and shut down later.

Common flow:

```
craft golem type <wood|stone|iron>
craft golem size <small|medium|large|huge>
craft golem show
craft golem start
```

Notes:
- Golem crafting requires the appropriate construct feats for each golem type.
- You can recall, upgrade, or shut down a golem with the related subcommands.

## Helpful tips

- Use `craft show` at any time to review your current craft project.
- If you get stuck, `craft reset` (or `refine remove` / `resize remove`) clears the project and refunds materials when appropriate.
- Check your harvesting and crafting tools: `craft tools` and `craft equipment`.
- Crafting and harvesting tools are purchased in crafting halls; use `craft tools` to see what
	you have equipped.

## Extra learning

The main crafting overview and related topics are on the wiki:
- https://krynn.d20mud.com/wiki/crafting/
- https://krynn.d20mud.com/wiki/harvesting-crafting-materials/
- https://krynn.d20mud.com/wiki/crafting-motes/
- https://krynn.d20mud.com/wiki/refining-materials/
- https://krynn.d20mud.com/wiki/creating-equipment/
- https://krynn.d20mud.com/wiki/resizing-gear/
