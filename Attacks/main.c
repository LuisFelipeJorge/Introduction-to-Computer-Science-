#include "attacks.h"

int main(int argc, char const *argv[])
{
    int m; // receive the dimension MxM of the matrix

    float **matrixp ; // pointer to the matrix 

    scanf("%d", &m);
    matrixp = create2Darray(m);
    
    inputOnMatrix(matrixp, m);

    int attackPower, playerType;
    scanf("%d", &attackPower);
    scanf("%d", &playerType);
   
    attack_t* head = NULL;

    head = createElement(attackPower, playerType);

    while(1){
        scanf("%d", &attackPower);
        if (attackPower == -1){
            break;
        }        
        scanf("%d", &playerType);
        insertAtBegining(&head, attackPower, playerType);
    }

    int enemyType;
    scanf("%d", &enemyType);

    findGreaterAttack(matrixp, head, enemyType);

    cleanList(&head);

    freeMatrix(matrixp, m);

    return 0;
}