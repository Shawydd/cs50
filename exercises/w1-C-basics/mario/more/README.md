# Mario/More

## Problem to Solve

In a file called ```mario.c``` in a folder called ```mario-more```, implement a program in C that recreates that pyramid, using hashes (```#```) for bricks, as in the below:
```
   #  #
  ##  ##
 ###  ###
####  ####
```
And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive ```int``` between, say, 1 and 8, inclusive.

If the user doesn’t input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate:
```
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```
Notice that width of the “gap” between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramids’ heights.

---
Based on: [mario (more comfortable) - CS50 Walkthroughs 2019](https://www.youtube.com/watch?v=FzN9RAjYG_Q "https://www.youtube.com/watch?v=FzN9RAjYG_Q")
