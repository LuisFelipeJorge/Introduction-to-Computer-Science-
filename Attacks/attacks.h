// Headers files 
#include <stdio.h>
#include <stdlib.h>

// define a struct to hold the data type

typedef struct attack_t{
    int attackPower, type;
    struct attack_t* next;
}attack_t;

//////////////////////////////////////////////////////////////////////////////////////////////////////
// functions declarations

float** create2Darray(int); // function to create the matrix/ 2D array.
void printMatrix(float **, int); // function to print the elements of a matrix.
void inputOnMatrix(float **, int); // function to input elements inside the matrix
void freeMatrix(float**, int); // free the space of the matrix
attack_t* createElement(int, int); // create an element of the data struct
void insertAtBegining(attack_t**, int, int); // implement the logic of a linked list to save de values
void printList(attack_t*); // auxiliary function to help the development process
void cleanList(attack_t**); // free the space for the list 
void findGreaterAttack(float**, attack_t*, int); // discover the greater attack
