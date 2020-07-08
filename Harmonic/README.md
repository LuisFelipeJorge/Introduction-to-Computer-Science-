## Description

Implement a C program with 3 basic functions:

1. ```int readInt ()```: Read an integer from the keyboard and return the value;
2. ```double readDouble ()```: Read a real from the keyboard and return the value;
3. ```double printDouble (double val)```: Write the value of the val parameter on the screen.

Then, in its **main** function, re-implement the program that calculates the amortized harmonic method, according to the formula used in this discipline. Your program should read in the standard text input an integer N (the reading of this value must be done by int n = readInt ()), which represents the number of jobs performed. Then, read N decimal numbers, representing a student's grade (the reading should use its readDouble () function). Print on the screen (using the printDouble function (double val)) the value of the amortized harmonic average of the works performed by the student. This average can be represented by the formula below:

**HM = N1 / (T1 + 1 + 1T2 + 1 +. . . + 1TN + 1−1)**

Write the average value to 2 decimal places.