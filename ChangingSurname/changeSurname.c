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

///////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[]){
  int nNames = 0;       // Counts the number of names in the input
  name_t *names = NULL; // Stores the input stream
  int i,j;

  // Read :
  names = readStream(stdin, &nNames);   // Read the stream from the user with stdin
  // printStream(names, nNames);        // Check the read

  // Change the surnames
  int left = 0;
  int right = nNames-1;
  char *temp0 = NULL; // get the last word(surname) of the first names, starting from the left
  char *temp1 = NULL; // get the last word(surname) of the last names, starting from the right

  while (left <= right) { // change the surnames till the left reference is no longer greater than the right one
    int aux0 = names[left].nWords-1; // get the index of the last word
    int aux1 = names[right].nWords-1;// do the same 
    // reallocate the memory and copy the last word of each name 
    temp0 = (char*)realloc(temp0, sizeof(char)*strlen(names[left].name[aux0]));
    strcpy(temp0, names[left].name[aux0]);
    temp1 = (char*)realloc(temp1, sizeof(char)*strlen(names[right].name[aux1]));   
    strcpy(temp1, names[right].name[aux1]);

    // swap the surnames 
    names[left].name[aux0] = (char*)realloc(names[left].name[aux0], sizeof(char)*strlen(temp1));
    strcpy(names[left].name[aux0], temp1);
    names[right].name[aux1] = (char*)realloc(names[right].name[aux1], sizeof(char)*strlen(temp0));
    strcpy(names[right].name[aux1], temp0);

    // Update the loop parameters
    left += 1;  // walk to the right
    right -= 1; // walk to the left
  }

  // Result
  printStream(names, nNames);

  // Free the space
  free(temp0);
  free(temp1);
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
  int nLetters = 0;       // count the number of letters in the stream and hel to allocate the memory
  char input;             // auxiliary variable to get the input char

  do{ 
    nNames += 1;
    names = (name_t*)realloc(names,nNames*sizeof(name_t)); // (re)allocate the memory space for the struct
    names[nNames-1].name = NULL;
    nWords = 0; // reset the counter at each new name/ after the \n
    do{
      nWords += 1;
      names[nNames-1].name = (char**)realloc(names[nNames-1].name, nWords*sizeof(char*));
      names[nNames-1].name[nWords-1] = NULL;
      nLetters = 0;     // Reset the counter at each ne word/ after the ' ' space
      do{
        input = fgetc(stream); // get the a char from the input
        if (input != '\r'){   // Ignores the \r char , to avoid problems of OS on runcodes
          nLetters += 1;
          names[nNames-1].name[nWords-1] = (char*)realloc(names[nNames-1].name[nWords-1], nLetters*sizeof(char));
          names[nNames-1].name[nWords-1][nLetters-1] = input;   // writr on our struct
        }
        
      } while ((input != ' ') && (input != '\n') && (input != '$')); // Inner loop that will read till a space                                                            
      //  Over write the \0 (EOF) over the last input (' ' or '\n' or '$')
      names[nNames-1].name[nWords-1][nLetters-1] = '\0'; 
    } while ((input != '\n') && (input != '$'));  // loop to get the names from the stream, as we have one name per line, we must divide the stream with the character '\ n' 
    // Save the number of words in each name
    names[nNames-1].nWords = nWords;    
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