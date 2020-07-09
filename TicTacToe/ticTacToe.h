#include <stdio.h>
#include <stdlib.h>
// matrix dimension
#define D 3

//////////////////////////////////////////////////////////////////
// functions declarations

char** createMatrix();
void printMatrix(char**);
void freeMatrix(char**);
void turn(char**, int);
int isFinished(char**, char);
int isTied(char**);

//////////////////////////////////////////////////////////////////