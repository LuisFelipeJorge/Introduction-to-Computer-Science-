#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

////////////////////////////////////////////////////////////////////////////////////////////
// functions declarations
char * readStream(FILE* stream);
char** partitionString(char * str, int *psize);
void sortString(char **str, int n);
void convertToLower(char *str);

////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[]){
    char* string;
    char** partition;
    int q;

    string = readStream(stdin);
    scanf("%d", &q);

    int size = 0;
    int *p = &size;

    partition = partitionString(string, p); 

    int i;
    if ( q == 1) {

        for ( i = 0; i < size; i++){
            printf("%s\n", partition[i]);
        }       

    } else if ( q == 2 ){

        for ( i = 0; i < size; i++){
            convertToLower(partition[i]);
        }
        sortString(partition, size);
        for ( i = 0; i < size; i++){
            printf("%s\n" , partition[i]);
        }

    }   

    free(string);
    free(partition);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////
// functions definitions

char * readStream(FILE* stream){
    char *str1 = NULL; 
    char *str2 = NULL;      // pointers to save the reference for the beginning of the stream

    char input;             // auxiliary variable to get the input stream
    int count = 0;          //variable to indicate the reading position and also the size of the space to be (re)allocated

    do{   
        input = fgetc(stream);

        count += 1;
        str2 = (char*)realloc(str1,count*sizeof(char));

        if (str2 != NULL ){ // this checks if the allocation process went wrong 
            str1 = str2;                    // pass the reference to the new memory block
            str1[count - 1] = input;        // stores the input char within the array
        }else {
            free(str1);
            printf("Error (re)allocating memory !!");
            exit(1);
        }        
        
    } while (str1[count-1] != '\n' && !feof(stream));

    str2 = (char*)realloc(str1,(count+1)*sizeof(char));
    if (str2 != NULL){
        str1 = str2;
        str1[count - 1] = '\0';     // overwriting the \n at the end of the stream
    }else {
        free(str1);
        printf("Error (re)allocating memory !!");
        exit(1);
    }    
    
    return str1; 
}

////////////////////////////////////////////////////////////////////////////////////////////

char** partitionString(char * str, int *psize){

    char ** rstr1 = NULL;            // return string, an array of strings or a 2D-array
    char ** rstr2 = NULL;
    char * pstr = strtok(str, " "); // separate the string into tokens using spaces as delimiters
    int count = 0;

    while (pstr != NULL){

        count += 1;
        rstr2 = (char**)realloc(rstr1, count*sizeof(char*));
        if (rstr2 != NULL){
            rstr1 = rstr2;
            rstr1[count - 1 ] = pstr;
            // strcpy(rstr[count - 1], pstr);
            pstr = strtok(NULL, " ");
        } else {
            printf("Error in (re)allocating memory !!");
            exit(-1); // fail in allocating the memory
        }   
    }

    *psize = count;
    
    return rstr1;    
}

////////////////////////////////////////////////////////////////////////////////////////////

void sortString(char **str, int n){
    // bubble sort
    int i,j;
    char* temp = NULL;
    for ( i = n-1; i > 0; i--){
        for ( j = 0; j < n-1; j++){
            if (strcmp(str[j], str[j+1]) > 0){
                temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp; 
            } 
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

void convertToLower(char *str){
    int i = 0;
    while (str[i] != '\0'){
        str[i] = tolower(str[i]);
        i++;
    }   
}

