#include <stdio.h>

////////////////////////////////////////////////
// functions declarations
int checkLeapYear(int year);
void isLeapYear(int bool);

////////////////////////////////////////////////

int main(int argc, char const *argv[]){
  int year;
  printf("Input year: ");
  scanf("%d", &year);
  
  isLeapYear(checkLeapYear(year));
  return 0;
}

////////////////////////////////////////////////
// functions definitions 

int checkLeapYear(int year){
  // leap year (number is evenly divisible by 4)
  //  AND not evenly divisible by 100
  if ((year % 4) == 0 && (year % 100) != 0 ){  
    return 1;   // Is a leap year   
  }
  // leap year ( number divisible by 100 and 400)  
  else if ((year % 4) == 0 && (year % 100) == 0 && (year % 400) == 0){
    return 1;   // Is a leap year       
  } else {
    return 0; // Is not a leap year 
  }
}

////////////////////////////////////////////////

void isLeapYear(int bool){
  if (bool == 1) printf("Is a leap year\n");
  if (bool == 0) printf("Is NOT a leap year\n");  
}