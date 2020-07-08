#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////

double harmonicMean(int n, double a[]);
int readInt(void);
double readDouble(void);
void printDouble(double val);

////////////////////////////////////////////////////////

int main(int argc, char const *argv[]){
    int n;
    n = readInt();
    double a[n];
    int i;
    for ( i = 0; i < n; i++){
        double aux;
        aux = readDouble();
        a[i] = aux;
    }

    double m = harmonicMean(n,a);
    printDouble(m);
    
    return 0;
}

////////////////////////////////////////////////////////

double harmonicMean(int n, double a[]){
    double sum = 0.0;
    double hmean;
    int i;

    for (i = 0; i < n; i++){
        sum += 1/(1 + a[i]);
    }

    hmean = ((n/(sum))-1);
    return hmean;       
}

////////////////////////////////////////////////////////

int readInt(){
    char string[256];
    fgets (string, 256, stdin); // read the input as a string and then convert it to the correct type
    int aux; // auxiliary variable to help pass the input value
    aux = atoi(string); 
    return aux;
}

////////////////////////////////////////////////////////

double readDouble(){
char string[256];
    fgets (string, 256, stdin);
    double aux; // auxiliary variable to help pass the input value
    aux = atof(string);
    return aux;
}

////////////////////////////////////////////////////////

void printDouble(double val){
    double aux = val;
    printf("%.2lf \n",aux );
}