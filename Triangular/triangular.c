#include <stdio.h>
#include <stdbool.h>
#include <math.h>

///////////////////////////////////////////////
// functions declarations

bool isTriangular(int tn);
bool isSquare (float tn);
int nextTriangular(int tn);

///////////////////////////////////////////////

int main(int argc, char const *argv[]) {
  int x, y;
  scanf("%d",&x );
  if (isTriangular(x)) {
    printf("YES\n");
    y = nextTriangular(x);
    printf("%d\n", y);

    if(isSquare(x + y)) printf("YES\n");
    else printf("NO\n");

  }else{
    printf("NO\n");
  }

  return 0;
}

/*
  We need first to remember what is the formula that defines a triangular number:
  Tn = n*(n + 1)/2 where Tn is the n-th triangular term.
  we can rewrite the equation as follows
  n² + n - 2*Tn = 0 (*)
  Then we have a second degree equation as a*n² + b*n + c = 0
  where a = b = 1 and c = -2*Tn
  delta is given by the formula d = (b*b) - 4*a*c
  Therefore we have d = 1 - 4*1*(-2*Tn) = 1 + 8*Tn
  Tn will be a triangular  number if, and only if, 1+8*Tn is a natural and perfect square
  we can check this condition with the function floor()
  double floor (double x);
  that returns the largest integer value less than or equal to x
  floor(2.3) = 2
  floor(-3.8) = -4

*/

///////////////////////////////////////////////
// functions definitions

bool isTriangular(int tn){
  float num;
  num = (float)(1 + 8*tn);
  if (isSquare(num)) {
    return true;
  }else{
    return false;
  }
}

///////////////////////////////////////////////

bool isSquare (float x){
  if (x < 0) {
    return false;
  }else{
    float f,g;
    f = sqrt(x);
    g = floor(f);
    if (g == f) {
      //in this case we have a perfect square
      return true;
    }else{
      return false;
    }
  }
}

///////////////////////////////////////////////

int nextTriangular(int tn){
  // we can assume that tn is already a triangular number
  float n1,n2; // the roots of (*)
  int next = 0; // the next triangular number 
  n1 = (-1 + sqrt(1+8*tn))/2;
  n2 = (-1 - sqrt(1+8*tn))/2;
  if(n1 > 0 ){
    next = (int)(((n1+1)*(n1+1 + 1))/2);
  }else if(n2 > 0){
    next = (int)(((n2+1)*(n2+1 + 1))/2);
  }
  return next;

}
