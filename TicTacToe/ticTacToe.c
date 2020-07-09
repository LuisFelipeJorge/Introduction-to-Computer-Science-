#include "ticTacToe.h"

//////////////////////////////////////////////////////////////////
// functions definitions

char** createMatrix(){
  char** matrix = NULL;
  int i, j;
  matrix = (char**)malloc(D*sizeof(char*)); // allocate the space for the rows
  if (matrix != NULL){
    for ( i = 0; i < D; i++){
    matrix[i] = (char*)malloc(D*sizeof(char)); // allocate space for the columns
      if (matrix[i] != NULL){
        for ( j = 0; j < D; j++){
          matrix[i][j] = '.';
        }  
      }else{
        printf("Error in Allocating the memory !!");
        exit(EXIT_FAILURE);        
      }       
    }      
  }else{
    printf("Error in Allocating the memory !!");
    exit(EXIT_FAILURE);
  }
  return matrix;
}

//////////////////////////////////////////////////////////////////

void printMatrix(char** matrix){
  int i, j;
  printf("#####################\n");
  printf("#####################\n");
  printf("      0    1    2\n");
  for ( i = 0; i < D; i++){
    printf("## %d", i);
    for ( j = 0; j < D; j++){
      printf("  %c  ", matrix[i][j]);
    }
    printf("##");
    printf("\n\n");    
  }  
  printf("#####################\n");
  printf("#####################\n");
}

//////////////////////////////////////////////////////////////////

void freeMatrix(char** matrix){
  int i;
  for ( i = 0; i < D; i++){
    free(matrix[i]);
  }
  free(matrix);  
}

//////////////////////////////////////////////////////////////////

void turn(char** matrix, int currentPlayer){
  int row, column;
  // coordinates within the matrix
  scanf("%d %d", &row, &column);
  // check if the position from the input is available
  if (matrix[row][column] == '.'){
    if (currentPlayer == 1){
      matrix[row][column] = 'X';
    }else{
      matrix[row][column] = 'O';
    }  
  }
  // if the input is not valid the player lost his turn 
}

//////////////////////////////////////////////////////////////////

int isFinished(char** matrix, char symbol){
  int i, j;

  // checks if the player won the game by filling in a row
  for ( i = 0; i < D; i++){
    for ( j = 0; j < D; j++){
      if (matrix[i][j] != symbol) break; // this break statement, stops the most inner loop, and then the program goes to the next row

      if(j == D - 1){
        if (symbol == 'X')return 1; // player 1 is the winner 
        else return 2; // player 2 is the winner 
      }
    }
  }

  // checks if the player won the game by filling in a column
  for ( i = 0; i < D; i++){
    for ( j = 0; j < D; j++){
      if (matrix[j][i] != symbol) break; // this break statement, stops the most inner loop, and then the program goes to the next column

      if(j == D - 1){
        if (symbol == 'X')return 1; // player 1 is the winner 
        else return 2; // player 2 is the winner 
      }
    }
  }

  // checks if the player won the game by filling in the main diagonal
  for ( i = 0; i < D; i++){
    if (matrix[i][i] != symbol) break;
    if (i == D - 1){
        if (symbol == 'X')return 1; // player 1 is the winner 
        else return 2; // player 2 is the winner       
    }   
  }
  
  // checks if the player won the game by filling in the main antidiagonal
  for ( i = 0; i < D; i++){
    if (matrix[i][D-1-i] != symbol) break;
    if (i == D - 1){
        if (symbol == 'X')return 1; // player 1 is the winner 
        else return 2; // player 2 is the winner       
    }       
  }

  // After all the verifications above, if there is no winner
  return 0;
}

//////////////////////////////////////////////////////////////////

int isTied(char** matrix){
  // there is no more positions availables
  int i, j;
  for ( i = 0; i < D; i++){
    for ( j = 0; j < D; j++){
      if (matrix[i][j] == '.') return 0; // is not tied 
    }    
  }
  // there is no more '.' within the matrix
  return 3; // there is no winner, the mage is tied 
  
}