#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct name_t {
  char** name;    // An array of strings or a 2D-array of chars
  int nWords;     // store the number of words within the string
}name_t;

///////////////////////////////////////////////////////////////////////////
// functions declarations
name_t* readStream(FILE* stream, int *pnames);
void printStream(name_t* names, int nNames);

///////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[]){

  int nNames = 0;       // Counts the number of names in the input
  name_t *names = NULL; // Stores the input stream
  int i,j;

  // Read :
  names = readStream(stdin, &nNames);   // Read the stream from the user with stdin

  // Add the surnames :
  char* surname = NULL;
  int surnameIndex0, surnameIndex1, newSize;

  for ( i = 0; i < nNames; i++) {
    if (((i%2)==0) && i < nNames-1) { // Check if the index is an even number AND that there is a string on the next odd index
      surnameIndex0 = names[i].nWords-1;
      surname = names[i].name[surnameIndex0]; 
      newSize = strlen(surname);    // Get the size needed to add the surname
      names[i+1].nWords += 1;       // As the program will add a surname, the number of words of the next names must be updated
      surnameIndex1 = names[i+1].nWords-1;
      names[i+1].name = (char**)realloc(names[i+1].name, sizeof(char*)*names[i+1].nWords);  // Reallocating space to add the surname
      // Check the allocation process
      if (names[i+1].name != NULL) {
        names[i+1].name[surnameIndex1] = (char*)malloc(newSize*sizeof(char));                 // Allocating space to the nem name
        // Check the allocation process
        if (names[i+1].name[surnameIndex1] != NULL){
          strcpy(names[i+1].name[surnameIndex1], surname); // copy the surname to the new index
        }else{
          printf("Error in (re)allocating the memory");
          exit(EXIT_FAILURE);
        }
      } else{
        printf("Error in (re)allocating the memory");
        exit(EXIT_FAILURE);
      }    
    }    
  } 

  // Result :
  printStream(names, nNames);

  // Free the space
  for ( i = 0; i < nNames; i++){
    for ( j = 0; j < names[i].nWords; j++){
      free(names[i].name[j]);
    }
    free(names[i].name);
  }
  free(names);   
    
  return 0;
}

///////////////////////////////////////////////////////////////////////////
// functions definitions

name_t* readStream(FILE* stream, int *pnames){
  // stream represents the input, and pnames is pointer to help pas this value by reference
  name_t *names = NULL;
  int nNames = 0;         // number of names/strings
  int nWords = 0;         // count the number of words within each name
  int nLetters = 0;       // count the number of letters in the stream and help to allocate the memory
  char input;             // auxiliary variable to get the input char

  do{ 
    nNames += 1;
    names = (name_t*)realloc(names,nNames*sizeof(name_t)); // (re)allocate the memory space for the struct

    // Check the allocation process
    if (names != NULL){
      names[nNames-1].name = NULL;
      nWords = 0; // reset the counter at each new name/ after the \n
      do{
        nWords += 1;
        names[nNames-1].name = (char**)realloc(names[nNames-1].name, nWords*sizeof(char*));
        // Check the allocation process
        if (names[nNames-1].name != NULL){        
          names[nNames-1].name[nWords-1] = NULL;
          nLetters = 0;     // Reset the counter at each ne word/ after the ' ' space
          do{
            input = fgetc(stream); // get the a char from the input
            if (input != '\r'){   // Ignores the \r char , to avoid problems of OS on runcodes
              nLetters += 1;
              names[nNames-1].name[nWords-1] = (char*)realloc(names[nNames-1].name[nWords-1], nLetters*sizeof(char));
              // Check the allocation process
              if (names[nNames-1].name[nWords-1] != NULL){
                names[nNames-1].name[nWords-1][nLetters-1] = input;   // writr on our struct
              }else{
                printf("Error in (re)allocating the memory");
                exit(EXIT_FAILURE);
              }                            
            }
            
          } while ((input != ' ') && (input != '\n') && (input != '$')); // Inner loop that will read till a space                                                            
          //  Over write the \0 (EOF) over the last input (' ' or '\n' or '$')
          names[nNames-1].name[nWords-1][nLetters-1] = '\0'; 
        }else{
          printf("Error in (re)allocating the memory");
          exit(EXIT_FAILURE);
        }
      } while ((input != '\n') && (input != '$'));  // loop to get the names from the stream, as we have one name per line, we must divide the stream with the character '\ n' 
      // Save the number of words in each name
      names[nNames-1].nWords = nWords;    
    } else{
      printf("Error in (re)allocating the memory");
      exit(EXIT_FAILURE);
    }
  } while (input != '$');   // External loop, to read all the input stream till the program find the '$'
  
  *pnames = nNames;
  return names;
}

///////////////////////////////////////////////////////////////////////////

void printStream(name_t* names, int nNames){
  int i, j;
  for ( i = 0; i < nNames; i++){
    for ( j = 0; j < names[i].nWords; j++){
      printf("%s ", names[i].name[j]);
    }
    printf("\n");
  }
  return;
}