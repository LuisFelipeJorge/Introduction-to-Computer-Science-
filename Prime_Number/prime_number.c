#include <stdio.h>

////////////////////////////////
// functions definitions

void primeNumberDecomposition(int x);

////////////////////////////////

int main(int argc, char const *argv[]){
    int x; // the input 
    scanf("%d", &x);
    primeNumberDecomposition(x);
    return 0;
}

////////////////////////////////
// functions definitios

void primeNumberDecomposition(int x){
    int i = x; // copy of the input number
    int q; // quotient values 
    int mul; // multiplicity of the quotients 
    q = 2; // first prime number
    while (i > 1){   
        mul = 0; // for each quotient we restart the count 
        while ((i%q) == 0){
            mul++;
            i /= q;
        }
        if (mul != 0) printf("%d %d \n", q, mul);// this means that the current quotient has a multiplicity        
        q++; // go to the next quotient
    }
    // for example, when the algorithm uses numbers like 4, which are not prime, 
    // they will be multiples of an earlier quotient; therefore, in these cases,
    // the program will not go into the inner loop.
}