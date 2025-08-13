# Mario/Less

## Problem to Solve

In a file called ```mario.c``` in a folder called ```mario-less```, implement a program in C that recreates that pyramid, using hashes (```#```) for bricks, as in the below:
```
       #
      ##
     ###
    ####
   #####
  ######
 #######
########
```
But prompt the user for an ```int``` for the pyramid’s actual height, so that the program can also output shorter pyramids like the below:
```
  #
 ##
###
```
Re-prompt the user, again and again as needed, if their input is not greater than 0 or not an ```int``` altogether.

---
Based on: [mario (less comfortable) - CS50 Walkthroughs 2019](https://www.youtube.com/watch?v=NAs4FIWkJ4s "https://www.youtube.com/watch?v=NAs4FIWkJ4s")

__Note__: this walkthrough specifies your program should prompt the user for a pyramid’s height and re-prompt if the user inputs a value less than 1 or greater than 8. The specification only requires you to re-prompt the user if they input a value less than 1.
