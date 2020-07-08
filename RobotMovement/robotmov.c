#include <stdio.h>
#include <stdlib.h>
#define MAX 200 // the maximum number of movements

////////////////////////////////
// Functions Declarations
int robotMovement(char *string); //return as output a number that represents the direction which the robot's face is pointing to
void robotFace(int mov);
////////////////////////////////

int main(int argc, char const *argv[])
{   
    char str[MAX]; // creating a string of 200 chars 
    scanf(" %s",str);
    int moves; // total number of movements 
    moves = robotMovement(str);

    robotFace(moves);    
    return 0;
}

////////////////////////////////
// Functions definitions

int robotMovement(char *string){
    // return the total number of movements made by the robot
    // R --> +1 and L --> -1
    int sum = 0;
    int i = 0;
    while (string[i] != '\0'){
        if (string[i] == 'R'){
            sum = sum + 1;
        }else if (string[i] == 'L'){
            sum = sum - 1;
        }
        i++;
    }
    return sum;           
}

////////////////////////////////

void robotFace(int mov){
    // after we count the total number number of movements we have to make some assumptions
    // the starting position is north, with a sum of zero, east 1, south 2 and west 3, and so on.
    // With this definition, we can see that if the total number of movements is a multiple of four, 
    // the robot's face is pointing north; if not, but it is a multiple of two, it is pointing south; 
    // if total - 1 is also a multiple of 4, then it points east; otherwise, west.
    if ((mov % 4) == 0){
        printf("North \n");
    }else if ((mov % 2) == 0){
        printf("South \n");
    }else if(((mov - 1) % 4) == 0){
        printf("East \n");
    }else{
        printf("West \n");
    }    
}