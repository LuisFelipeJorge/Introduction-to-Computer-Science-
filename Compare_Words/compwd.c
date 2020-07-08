#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100    // the string size

////////////////////////////////////////////
// Functions declarations
int stringLength(char *str); // find the length of a string
int stringSum(char *str); // find the sum of letters 
int stringRepetition(char *str, char c); // find the number of times a determined char occurs in the string
int stringFirstApparition(char *str, char c); // find the position of the first apparition of a determined char
void convertToLower(char *str); // Convert all the elements of the string to lowercase

////////////////////////////////////////////

int main(int argc, char const *argv[])
{
    int op; // operation code
    scanf("%d", &op);
    char str1[SIZE]; // first string
    char str2[SIZE]; // second string 
    scanf("%s", str1);
    scanf("%s", str2);

    //to simplify the functions I will work only with lowercase letters
    
    convertToLower(str1);
    convertToLower(str2);

    int l1,l2; // store information about str1 and str2
    int aux;
    char c;
    switch (op){
        case 1: //  Which word is bigger?

            l1 = stringLength(str1);
            l2 = stringLength(str2);
            if (l1 == l2){
                aux = 0;
            }else {
                aux = (l1 > l2)?1:2;
            } // if the first string is bigger aux = 1, otherwise aux = 2
            printf("%d\n", aux);        

            break;

        case 2: // Alphabetical order

            aux = strcmp(str1,str2);
            if (aux < 0) { // str1 came first in alphabetical order
                printf("1 \n");
            }else if (aux > 0){
                printf("2 \n");
            }else{ // aux == 0
                // equal strings
                printf("0 \n");
            }            
            break;

        case 3: //  Which word has the highest sum of the letter values ​​(A = 0 to Z = 25)
        
            l1 = stringSum(str1);
            l2 = stringSum(str2);
            if (l1 == l2){
                aux = 0;
            }else{
            aux = (l1 > l2)?1:2; // if the first string has the bigger sum aux = 1, otherwise aux = 2
            }
            printf("%d\n", aux);     

            break;

        case 4: //  Which of the words has more repetitions of a given letter
        
            scanf(" %c",&c); // we must put a space due to previous scanf \n 
                            // remains in stdin and second scanf stores that in your variable and doesn't wait for input
            c = tolower(c); // lowercase pattern

            l1 = stringRepetition(str1,c);
            l2 = stringRepetition(str2,c);
            if (l1 == l2){
                aux = 0;
            }else{       
                aux = (l1 > l2)?1:2; //if the first string has more reperitions of char c aux = 1, otherwise 2
            }
            printf("%d\n", aux);                
        
            break;
        
        case 5: //  In which of the words does a particular letter appear first 
                // (if the letter sought is the second of word 1 and the third of word 2, word 1 won the comparison)
        
            scanf(" %c", &c);
            c = tolower(c); // we will only work with lowercase
            
            l1 = stringFirstApparition(str1,c);
            l2 = stringFirstApparition(str2,c);
            if (l1 == l2){
                aux = 0;
            }else{
                aux = (l1 < l2)?1:2; // if the char appears first in str1, l1 < l2 and then print the number 1, otherwise number 2
            }    
            printf("%d\n", aux); //                         
        
            break;
    
        default:
            printf("Ivalid Input !! \n");
            break;
    }
    return 0;
}


////////////////////////////////////////////
// Functions definitions

int stringLength(char *str){
    int i = 0; // work as the index 
    int lenght = 0; // variable to count or number of repetitions within the loop
    while (str[i] != '\0'){   // \0 stands for the end of line
        lenght ++;
        i++;
    }
    return lenght;
}

////////////////////////////////////////////

int stringSum(char *str){
    int i = 0; 
    // as the chars inside the ascii table are adjacents
    // we do not need to convert 'A' = 0 and so on
    // it does not affect the comparison to find the highest value
    
    int sum = 0;
    while (str[i] != '\0'){
        // the lowercase letters starts with 'a' = 97
        sum += (str[i] - 97);
        i++;
    }
    return sum;   
}

////////////////////////////////////////////

int stringRepetition(char *str, char c){
    int i = 0; 
    int repetitions = 0; // count the number of timer c is present inside the string str
    while (str[i] != '\0'){
        if (str[i] == c) repetitions++;
        i++;       
    }
    return repetitions;
}

////////////////////////////////////////////

int stringFirstApparition(char *str, char c){
    int i = 0; // store the position that 'c' appears for the first time
    while ( (str[i] != '\0')&&(str[i] != c) ){
        i++;
    }

    if(str[i] == '\0') return SIZE; // the char don't appear in the string

    i++;
    return i ;
}

////////////////////////////////////////////

void convertToLower(char *str){
    int i = 0;
    while (str[i] != '\0'){
        str[i] = tolower(str[i]);
        i++;
    }   
}