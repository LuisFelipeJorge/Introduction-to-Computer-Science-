#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////
// Functions declarations
int** createMatrix(int width, int height);
void printMatrix(int** matrix, int width, int height);
int** padding(int** matrix, int width, int height, int paddingNumber);

/////////////////////////////////////////////////////

int main(int argc, char const *argv[]){
  int width;    // number of columns 
  int height;   // number of rows
  int paddingNumber;  // gets the padding number to be added 
  int **image = NULL;

  // Read the inpute
  scanf("%d %d", &width, &height);
  image = createMatrix(width, height);
  scanf("%d", &paddingNumber);

  // Padding 
  int **paddingImage = NULL;
  paddingImage = padding(image, width, height, paddingNumber);

  // Printing the Result
  printMatrix(paddingImage, (width+2*paddingNumber), (height+2*paddingNumber));
  printf("\n");
  printMatrix(image, width, height);
  
  // Free
  int i;
  for ( i = 0; i < height; i++) {
    free(image[i]);    
  }
  for ( i = 0; i < (height+2*paddingNumber); i++){
    free(paddingImage[i]);
  }
  
  free(image);
  free(paddingImage);

  return 0;
}

/////////////////////////////////////////////////////
// Functions definitions

int** createMatrix(int width, int height){
  int** matrix;
  matrix = (int**)malloc(sizeof(int*)*height);
  int i, j, aux;
  for ( i = 0; i < height; i++) {
    matrix[i] = (int*)malloc(sizeof(int)*width);
    for ( j = 0; j < width; j++) {
      scanf("%d", &aux);
      matrix[i][j] = aux;
    }    
  }
  return matrix;
}

/////////////////////////////////////////////////////

void printMatrix(int** matrix, int width, int height){
  int i,j;
  for ( i = 0; i < height; i++) {
    for ( j = 0; j < width; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  return;
}

/////////////////////////////////////////////////////

int** padding(int** matrix, int width, int height, int paddingNumber){
  int **paddingMatrix = NULL;
  int i;
  int j;

  // the new dimensions of the padding matrix are the same as the originals dimensions
  // plus 2 times the padding number.
  paddingMatrix = (int**)malloc((height+2*paddingNumber)*sizeof(int*));
  for ( i = 0; i < (height+2*paddingNumber); i++) {
    paddingMatrix[i] = (int*)calloc((width+2*paddingNumber), sizeof(int)); // allocate the spaces and initializes the matrix with the value zero
    if((i < height+paddingNumber) && (i >= paddingNumber)){
      for ( j = 0; j < width; j++) {
        paddingMatrix[i+paddingNumber][j+paddingNumber] = matrix[i][j]; 
      }    
    }
  }

  return paddingMatrix;
}