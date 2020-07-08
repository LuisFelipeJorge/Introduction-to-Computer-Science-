## Description
You must simulate the AI ​​of a player by choosing which attack is best against a given opponent. For that, it is necessary to know what is the relationship between the various types existing in the game, what is the damage and the type of each player's attack, and the type of the enemy.

The relationships between types are given by an MxM matrix, where M is the number of types in the game, and will be provided to the user at the beginning of the program. Each element of this matrix is ​​a float that indicates by what value the attack of one type (row) must be multiplied when used on another type (column).

Each attack has two pieces of information: the first is its attack power (integer), and the second its type (type index in the table).
You should read the data for each attack until you find the value -1 when reading the first attribute *, totaling N attacks.

Finally, the last entry is the enemy type. This is the type the attack will be used on!
Your objective is to find out which attack is best to be used on the enemy of the type provided as input and then print the following message:
"The best attack has index X and damage Y \ n", X being the index (from 0 to N) of the attack, and Y the damage given by such an attack (print only the first 2 decimal places of the damage).
* Do not read the second attribute if you find -1.

### Input example

```
3
1 2 1
2 1 0.5
1 1 2
2 0
2 1
2 2
-1
2
```

### Output 
```
The best attack has index 2 and damage 4.00
```