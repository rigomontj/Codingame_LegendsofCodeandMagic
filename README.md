This is my take on Codingame's competitive programming challenge : Legends of Code and Magic

The goal is to program the most efficient AI possible at
playing a Heathstone clone ([Game](http://www.ign.com/wikis/hearthstone-heroes-of-warcraft/Rules))

Your AI gets matched up against other programmer's AIs and you get points for winning matches.

I programmed it in C because I wanted to apply
what I learnt during my piscine 42 ([what is this ?](https://www.42.us.org/program/intensive-basic-training/))

The strategy I programmed into my AI is very similar to that of an aggressive deck human hearthstone player:
It maximizes its own damage output per turn through evaluation of board state and hand possibiltiies.
It favors low cost cards and direct damage during draft phase.
It gets rid of difficult opponent creatures that block my damage through exceptions
(one of which being the Lethal creature ability)
It wins the match in the least turns possible.
