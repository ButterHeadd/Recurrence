(This was the document I updated while making this version of the game. While accurate to this game, it is now outdated for the current build which aims to have more. I'm remaking it from scratch, reusing this code while adding some I feel is necessary.)

Important Details:

Done on Programiz, C++.
Can't be a game that requires constant movement, Programiz just can't handle that.
Game Idea:
RPG. Stats and leveling up. 
Text based, type “attack” to attack, “run” to attempt to get away, etc.
Add a small story, dialogue based. since there's no save feature, mAyBe don't make it too long and complex. (could create acts, where you can jump forward when starting again, getting the average stat points for the act).
Allow players to allocate stat points before starting + after leveling up, and choose a name for the player at the start.
Implement a tutorial

Necessary Additions / Changes:

Add magic, magic points and a single spell: healing.
Add combos that are tied to speed stat
Way to set my usual stats and name, so I don’t need to keep adding it at the beginning.
Make the text look less clustered.
Add the story, progression, etc. (Maybe add things like need a certain level, and amount of enemies defeated),.

Advanced things to add later:
https://youtu.be/T31MoLJws4U?si=iSlHmL88UCPVQwJK
-Learn this. Really useful for this.
Use SFML
Change the Draw function to a class, and implement SFML.
When using SFML, allow commands to be placed in the console but use windows to display things.
Make use of different files. 
.h files:
RNG.h
Health bar. (Could make it as simple as [x], 10 X's and whenever the player loses 10% of health, one x disappears).
Implement magic system where only 4 can be chosen.
Shop + Currency system. Make it so that magic spells needs to be purchased.
Item system (healing items, equipment, etc)
Jobs (different jobs have different equipment, specialitys, etc)
Way to get stats back, and load into whichever act you were at. Can use file writing for a save file.
World map (like how chatgpt did with snake)
Bestiary / Item List. Use 2 arrays for each thing, one that has everything and the other that only has what the player has unlocked and seen.
Skill tree, every time you level up a class, you get a single ability which goes towards the skill tree. Some nodes are locked behind class level restrictions.
Companions? (I don't know, I want a solo protagonist)
Flying enemies

Gameplay Mechanics:

Displayed:

Always-

Health / Max Health
MP
Level
Experience / Max Experience

In Menu-

All stats.
Total enemies killed.
Time played.

Actions:

In Battle-

Attack: Attacks an enemy.
Run: Run from a fight, 50% chance of working.
Scan: Display enemy stats, still takes a turn.
Outside of Battle-
Menu: Check stats, amount of enemies killed, etc.
Close: Closes menu.
Battle: Fight an enemy.

Stats:

Non-Determined Stats-

Level: gauge of how strong you are. gives you star points which you can use to level up player-determined stats.
Experience: needed to level up. Max exp changes with level, and once reached resets to 0 and gives a level up.
Max Experience: how much experience is needed to level up. Changes with level.
Health: Amount of hits you can take before dying.
Stat points: What is used to raise stats, 1 point = 1 stat raise. 30 given at the start of the game, 10 given each level up.

Player-Determined Stats-

Max Health: How high your health can be.
Strength: How much damage you do against enemies.
Speed: Determines if you hit before or after the enemy.
Magic: Determines the potency of magic.

Enemy Stats:

Exp Gain: how much exp the player is given.

Enemy’s:

Same kinds of stats as the player, except for experience. 
USE CLASS TO CODE ENEMY TYPES.
They have randomised stats, the minimum and max is determined by their level and species. 
Species determined base stats + how stats are increased by level up.
Each species will have a different function applied to it, and one main function which chooses which enemy to spawn.
For now, just make 3 types- one that specializes in speed, one that specializes in strength, and one that specializes in health.
Maybe code in a boss, as well?
For now, enemies scale with the player. Either one level below, same level, or one higher.

Enemy Types:

Zombie:

High strength, medium health, low speed.
Base stats-
Strength: 12
Max Health: 8
Speed: 5
Exp gain: 4-7

Level up amount-

Strength: 4
Max Health: 2
Speed: 1
Exp gain: 3

Haunted Armour:

High health, medium speed, low strength.
Base stats-
Strength: 5
Max Health: 12
Speed: 8
Exp gain: 4-7

Level up stats-

Strength: 2
Max Health: 4
Speed: 1
Exp gain: 3

Arachnid:

High speed, medium strength, low health.
Base stats-
Strength: 8
Max Health: 5
Speed: 12
Exp gain: 4-7

Level up stats-

Strength: 2
Max Health: 1
Speed: 4
Exp gain: 3

Story:

You are a set of haunted armour, however you retained your sentence for some reason, but not your memories.
World details

Act 1
