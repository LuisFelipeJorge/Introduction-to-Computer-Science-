#include <stdio.h>

///////////////////////////////////
// Simple Calculator
int main(int argc, char const *argv[]) {
  double a,b;
  char op;
  scanf("%lf %c %lf", &a, &op, &b);
  //printf(" a = %lf, b = %lf e op = %c\n",a,b,op );

  switch (op) {
    case '+':
      printf("%lf\n", a + b );
      break;
    case '-':
      printf("%lf\n",a - b );
      break;
    case '*':
      printf("%lf\n",a * b );
      break;
    case '/':
      printf("%lf\n",a / b );
      break;
    case '%':
      printf("%lf\n",((a/b)*100) );
      break;
  }
  return 0;
}

///////////////////////////////////
