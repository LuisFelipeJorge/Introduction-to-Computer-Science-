## Description

You are programming the movement of the new robot that you designed and, at the moment, you are trying to make it understand correctly the "turn right" and "turn left" commands. To test it, you will provide it with a string containing a maximum of 200 commands that can alternate between 'R' (right) and 'L' (left).

The robot will initially be facing north. When a 'R' command is given to him, the robot will turn to the right and then face east. If one more command is read, it will turn to the right again, this time with the face facing south. So, if an 'L' command is read, the robot will turn in the opposite direction and turn its face east again.
Your program should be able to inform which direction the robot face should point after a sequence of commands and display, in the standard output, which direction is followed by a line break (\ n). 

### Input

```
Case 1) RRRRLLLLLRRLLL
Case 2) RRRLLRLRLLLLLRLRRRLRRLRLRLRLRLRLLLRRRRRLRLLLLLLLR
```

### Output

```
1) South
2) East
```
