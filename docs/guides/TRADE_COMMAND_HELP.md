# Trade Command Help

Suggested keywords: `trade`, `trading`, `player trade`, `materials trade`, `motes trade`

Minimum level: `0`

## Trade

The `trade` command sends a secure two-player trade request. Once the other player accepts, both players can offer carried items, gold, crafting materials, and crafting motes. Both players can review the full trade before accepting, and the trade only completes after both players accept.

## Syntax

```text
trade <player>
trade show
trade accept [player]
trade add item <item>
trade add gold <amount>
trade add material <amount> <material>
trade add mote <amount> <mote>
trade remove item <item>
trade remove gold <amount>
trade remove material <amount> <material>
trade remove mote <amount> <mote>
trade cancel
```

## Starting A Trade

To begin trading, both players must be in the same room.

```text
trade Tanis
```

This sends Tanis a trade request. Tanis can accept it with:

```text
trade accept
```

After the request is accepted, both players can add things to their side of the trade and use `trade show` to review both offers.

Players who do not want incoming trade requests can toggle them off with:

```text
rejecttrades
```

## Adding To The Trade

Add an item from your inventory:

```text
trade add item longsword
```

Add gold:

```text
trade add gold 500
```

Add crafting materials:

```text
trade add material 25 steel
trade add material 10 alchemical-silver
```

Add crafting motes:

```text
trade add mote 3 air mote
trade add mote 1 fire-mote
```

Material and mote names may use spaces or dashes.

## Removing From The Trade

You can remove anything you offered before the trade completes.

```text
trade remove item longsword
trade remove gold 100
trade remove material 5 steel
trade remove mote 1 air mote
```

## Reviewing And Accepting

Use `trade show` to view your offer, the other player's offer, and each player's accept status.

```text
trade show
```

When the trade looks correct:

```text
trade accept
```

Both players must accept. If either player adds or removes anything after an acceptance, both accept states are cleared and both players must accept again.

## Canceling

Either player can cancel a pending trade request or active trade at any time:

```text
trade cancel
```

Pending requests and active trades also cancel automatically if either player moves out of the room, quits, loses link, or dies. Offered items remain in their original owner's inventory when a trade is canceled.

## Important Notes

- Items added to a trade remain in your inventory until the trade completes. The trade records the offered item and verifies that you still have it before finalizing.
- Trade requests cannot be sent to players with `rejecttrades` enabled.
- Gold, materials, and motes are checked when added and checked again when the trade completes.
- If either player no longer has an offered item, required gold, materials, or motes when both players accept, the trade does not complete and both players must accept again after fixing the offer.
- The trade will not complete if either player cannot carry the incoming items or would exceed the maximum amount of carried gold.
- Items that cannot be dropped cannot be added to a trade.
