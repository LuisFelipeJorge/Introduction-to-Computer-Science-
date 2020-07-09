#include "ticTacToe.h"

//////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[]){
  char** M = NULL; // a 2D-array of chars
  M = createMatrix();
  printMatrix(M);
  int endGame = 0; // tell when the game is over
  int player = 1; // player = 1 => 'X' or player = 2 => 'O'
  
  while (endGame == 0) {
    // play the game
    turn(M, player);
    // change the player after his turn ends
    if (player == 1){
      endGame =  isFinished(M, 'X'); // check if the game is finished
      player = 2;
    }else{
      endGame =  isFinished(M, 'O');
      player = 1;
    }    

    if (endGame == 0){
      endGame = isTied(M);
    }
    printMatrix(M);
  }

  if (endGame != 3){ // There is a winner
    printf("The Winner is player %d !! \n", endGame);
  } else{
    printf("The game is tied!!\n");
  }

  freeMatrix(M);
  return 0;
}

//////////////////////////////////////////////////////////////////