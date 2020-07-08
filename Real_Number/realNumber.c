#include <stdio.h> // Standard C header
#include <math.h> // Contains round()

//////////////////////////////////////////////////

int main(int argc, char const *argv[]) {
  double x;
  scanf("%lf", &x);

  int aprox; // integer aproximation
  aprox = (int) round(x);

  int i; // integer part
  i = (int) floor(x);

  double dec ; // decimal part
  dec = (double)(x - i);

  printf("%d\n", i );
  printf("%.4lf\n", dec );
  printf("%d\n", aprox );

  return 0;
}

//////////////////////////////////////////////////

/*
  double round  (double x)
    This function returns the nearest integer value of the float/double/long double argument passed to this function.
    If decimal value is from “.1 to .5”, it returns integer value less than the argument.
    If decimal value is from “.6 to .9”, it returns the integer value greater than the argument.

  double floor (double x)
   returns the largest integer value less than or equal to x.
*/

//////////////////////////////////////////////////
