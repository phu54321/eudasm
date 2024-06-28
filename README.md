eudasm
======

Simple build system for starcraft map.


You can create BrainFuck interpreter with EUD triggers of starcraft, so EUD triggers are turing-complete. In fact, you can create programs with EUD. This is called trigger programming. Trigger programming was tedious and hard to do. Code below creates a simple loop in EUD.

```py
from trgformat import *
import struct

locoffset = 0x00000000 # offset of MRGN section

# STR data

# trigger A
trigA = Trigger(
    players = [],
    conditions = [],
    actions = [
        SetMemory(0x0058D740, SetTo, 0x00000000),
        SetMemory(locoffset + 8 + 320 + 32 * 0 + 16, Add, 1),
        SetMemory(locoffset + 8 + 320 + 32 * 0 + 20, Add, 1),
        SetDeaths(Player1, Add, 1, 2),
        PreserveTrigger()
    ]
)

# trigger b B
trigB = Trigger(
    players = [],
    conditions = [
        Deaths(Player1, Exactly, 320, 2)
    ],
    actions = [
        SetMemory(locoffset + 2408 + 4, SetTo, 0xFFAE5D73),
        SetMemory(0x51A28C + 4, SetTo, 0x51A28C),
        SetMemory(0x51A28C + 8, SetTo, 0xFFAE5D73),
    ]
)

trigAHeader = struct.pack('<LL', locoffset + 2408, locoffset + 2408)
trigBHeader = struct.pack('<LL', locoffset, locoffset)

data = b''.join([trigAHeader, bytes(trigA), trigBHeader, bytes(trigB)])

open('str_payload.trg', 'wb').write(data)



# MRGN trigger
trigA = Trigger(
    players = [],
    conditions = [],
    actions = [
        # PRT initalization
        # 376, 408, 2752 is prt
        SetMemory(8 + 320 + 32 * 1 + 16, Add, 0),
        SetMemory(8 + 320 + 32 * 2 + 16, Add, 0),
        SetMemory(2408 + 8 + 320 + 32 * 0 + 16, Add, 0),

        # ORT initalization
        # 0, 4, 2408, 2412 is ort
        SetMemory(0, Add, 0),
        SetMemory(4, Add, 0),
        SetMemory(2408, Add, 0),
        SetMemory(2412, Add, 0)
    ]
)

trigAHeader = struct.pack('<LL', 0, 0)
data = b''.join([trigAHeader, bytes(trigA)])
open('mrgn_payload.trg', 'wb').write(data)


# TRIG trigger
stroffset = 2164
triggers = []

# copy player trigger.
locoffset = 0x58DC60

for i in range(31, 1, -1):
    triggers.append(Trigger(
        players = [Player1],
        conditions = [
            Memory(0x5993D4, AtLeast, 1<<i),
            Deaths(Player1, Exactly, 0, 1)
        ],
        actions = [
            SetMemory(0x5993D4, Subtract, 1<<i),

            SetMemory(locoffset + 4, Add, 1<<i),

            SetMemory(locoffset + 8 + 320 + 32 * 0 + 16, Add, 1<<(i-2)),
            SetMemory(locoffset + 8 + 320 + 32 * 1 + 16, Add, 1<<(i-2)),
            SetMemory(locoffset + 8 + 320 + 32 * 2 + 16, Add, 1<<(i-2)),
            SetMemory(locoffset + 8 + 320 + 32 * 3 + 16, Add, 1<<(i-2)),
            SetMemory(locoffset + 8 + 320 + 32 * 4 + 16, Add, 1<<(i-2)),
            SetMemory(locoffset + 8 + 320 + 32 * 5 + 16, Add, 1<<(i-2)),
            SetMemory(locoffset + 8 + 320 + 32 * 6 + 16, Add, 1<<(i-2)),

            SetMemory(locoffset + 8 + 320 + 32 * 0 + 20, Add, 1<<(i-2)),
            SetMemory(locoffset + 8 + 320 + 32 * 1 + 20, Add, 1<<(i-2)),
            SetMemory(locoffset + 8 + 320 + 32 * 2 + 20, Add, 1<<(i-2)),
            SetMemory(locoffset + 8 + 320 + 32 * 3 + 20, Add, 1<<i),
            SetMemory(locoffset + 8 + 320 + 32 * 4 + 20, Add, 1<<i),
            SetMemory(locoffset + 8 + 320 + 32 * 5 + 20, Add, 1<<i),
            SetMemory(locoffset + 8 + 320 + 32 * 6 + 20, Add, 1<<i),

            SetDeaths(Player1, Add, 2<<i, 0)
        ]
    ))

for i in range(31, 1, -1):
    triggers.append(Trigger(
        players = [Player1],
        conditions = [
            Deaths(Player1, AtLeast, 1<<i, 0),
            Deaths(Player1, Exactly, 0, 1)
        ],
        actions = [
            SetDeaths(Player1, Subtract, 1<<i, 0),
            SetMemory(0x5993D4, Add, 1<<i)
        ]
    ))

triggers.append(Trigger(
    players = [Player1],
    conditions = [],
    actions = [
        SetDeaths(Player1, SetTo, 1, 1),
        SetMemory(0x51A28C + 8, SetTo, locoffset),

        SetMemory(locoffset + 4, Add, stroffset),

        SetMemory(locoffset + 8 + 320 + 32 * 0 + 16, Add, stroffset // 4),
        SetMemory(locoffset + 8 + 320 + 32 * 1 + 16, Add, stroffset // 4),
        SetMemory(locoffset + 8 + 320 + 32 * 2 + 16, Add, stroffset // 4),
        SetMemory(locoffset + 8 + 320 + 32 * 3 + 16, Add, stroffset // 4),
        SetMemory(locoffset + 8 + 320 + 32 * 4 + 16, Add, stroffset // 4),
        SetMemory(locoffset + 8 + 320 + 32 * 5 + 16, Add, stroffset // 4),
        SetMemory(locoffset + 8 + 320 + 32 * 6 + 16, Add, stroffset // 4),

        SetMemory(locoffset + 8 + 320 + 32 * 0 + 20, Add, stroffset // 4),
        SetMemory(locoffset + 8 + 320 + 32 * 1 + 20, Add, stroffset // 4),
        SetMemory(locoffset + 8 + 320 + 32 * 2 + 20, Add, stroffset // 4),
        SetMemory(locoffset + 8 + 320 + 32 * 3 + 20, Add, stroffset),
        SetMemory(locoffset + 8 + 320 + 32 * 4 + 20, Add, stroffset),
        SetMemory(locoffset + 8 + 320 + 32 * 5 + 20, Add, stroffset),
        SetMemory(locoffset + 8 + 320 + 32 * 6 + 20, Add, stroffset)
    ]
))

WriteTrg('out.trg', triggers)
```


This is not the thing normal people are willing to do, so I created somewhat easy development tool for trigger programming. It is called eudasm, EUD Assembler. Code below is a reimplementation of the above code with eudasm.


```txt
Trigger: @trigA
    next trigB

    Actions:
        SetDeaths(&0x0058D740, SetTo, 0x00000000, 0) @trig1_act1
        SetDeaths(&(trig1_act1 + 16), Add, 1, 0)
        SetDeaths(&(trig1_act1 + 20), Add, 1, 0)
        SetDeaths("Player 1", Add, 1, "Terran Vulture")
        PreserveTrigger()



Trigger: @trigB //code:trigB = 2408
    next trigA

    Conditions:
        Deaths("Player 1", Exactly, 320, "Terran Vulture")

    Actions:
        SetDeaths(&(trigB + 4), SetTo, 0xFFAE5D73, 0)
        SetDeaths(&(0x51A28C + 4), SetTo, 0x51A28C, 0)
        SetDeaths(&(0x51A28C + 8), SetTo, 0xFFAE5D73, 0)
```


Much easier and understandable. eudasm is the lowest level trigger programming tool with understandable syntax.

But coding with eudasm again got too hard and tedious. Since eudasm didn't have any concept of variable and function, (just like the real assembly) you have to create some of the most basic stuff yourself.

Now, eudasm aims to be a collection of programs
 - eudasm  : Basic assembler. Do hard things here
 - eudc    : Basic c-like syntax compiler.
 - eudbin  : Takes in binary files and gives it a label, so that it can be used with eudlink.
 - eudlink : Links several files and inserts it to the map.
