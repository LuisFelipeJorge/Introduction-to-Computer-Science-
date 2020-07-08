// Import the header file

#include "attacks.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
// functions definitions

float** create2Darray(int dimension){
    // In this function we will use pointers of pointers to create a matrix
    float **arr;
    arr = (float**)malloc(sizeof(float*)*dimension); 
    int i;
    for ( i = 0; i < dimension; i++){
        arr[i] = (float*)malloc(sizeof(float)*dimension);
    }    
    return arr;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void printMatrix(float ** matrix, int dimension){
    int i,j;
    for ( i = 0; i < dimension; i++){
        for ( j = 0; j < dimension; j++){
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void inputOnMatrix(float **matrix, int dimension){
    int i,j;
    float aux; // auxiliary variable to get the inputs
    for ( i = 0; i < dimension; i++){
        for ( j = 0; j < dimension; j++){
            scanf("%f", &aux);
            matrix[i][j] = aux;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void freeMatrix(float **matrix, int dimension){
    int i;
    for ( i = 0; i < dimension; i++){
        free(matrix[i]);
    }    
    free(matrix);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

attack_t* createElement(int attack, int type){
  attack_t* element = (attack_t*)malloc(sizeof(attack_t)); // allocating the space in the memory
  element->attackPower = attack;
  element->type = type;
  element->next = NULL;
  return element;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void insertAtBegining(attack_t** head_node, int new_attack, int new_type){
  // First, we need to dynamically allocate memory for the new element
  attack_t* temp = (attack_t*)malloc(sizeof(attack_t)); // temporary variable to help insert the new node
  temp->attackPower = new_attack; // putting the data inside the key
  temp->type = new_type;
  temp->next = (*head_node); // the new node will point to the reference of the head, this mean to the rest of the list
  (*head_node) = temp;// the new node becomes the head of the list
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void printList(attack_t* head_node) {
  if (head_node == NULL) {
    printf("The list is empty\n" );
  }else{
    while (head_node != NULL) {
      printf("%d %d \n",head_node->attackPower, head_node->type ); // printing the element
      head_node = head_node->next; //walking in the list, at each loop the reference changes to the next element
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void cleanList(attack_t** head_node) {
  attack_t* aux; // auxiliar variable to help in the process
  aux = (*head_node); // store the reference of the head_node
  attack_t* next;// contains the reference to the next elements of the list
  while (aux != NULL) {
    // when aux == NULL, we are in the last element of the lista
    next = aux->next; // save the address of the others elements of the list
    free(aux); // releasing the memory in the adress aux
    aux = next; // walking through the list
  }
  (*head_node) = NULL;// returning to an empty list
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void findGreaterAttack(float **matrix, attack_t* head_node, int enemyType){
    float greaterAttack = 0.0;
    float currentAttack = 0.0;
    int index = 0;

    if (head_node == NULL) {
        printf("The list is empty\n" );
    }else{

        while (head_node != NULL) {

            int player_type = head_node->type;  // row index
            int power = head_node->attackPower;
            currentAttack = power*matrix[player_type][enemyType];

            if (currentAttack >= greaterAttack){
                greaterAttack = currentAttack;
                index = player_type;             
            }        
            head_node = head_node->next; //walking in the list, at each loop the reference changes to the next element
        }
    }

    printf("The best attack has index %d and damage %.2f\n", index, greaterAttack);
    return;
}