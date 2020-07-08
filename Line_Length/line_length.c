#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//////////////////////////////////////////////////////////

//Let's define a structure as a Cartesian point
typedef struct point_t{
  double x; //X-axis coordinate
  double y; // Y-axis coordinate
}point_t;

//////////////////////////////////////////////////////////
// functions declarations 

double distance(point_t *p, int n); // functions to calculate the distance between two points

//////////////////////////////////////////////////////////

int main(int argc, char const *argv[]) {
  int n; // number of points.
  scanf("%d",&n );
  point_t *p = (point_t*)malloc(n*sizeof(point_t)); // Array of points
  if (p == NULL){
    free(p);
    printf("\nProblems with memory allocation\n");
    exit(EXIT_FAILURE); 
  }

  int i;
  for ( i = 0; i < n; i++) {
    scanf("%lf%lf", &p[i].x, &p[i].y);
    //printf("X : %lf Y : %lf\n", p[i].x, p[i].y);
  }

  double length;
  length = distance(p,n);
  printf("%.4lf\n", length );

  free(p);
  return 0;
}

//////////////////////////////////////////////////////////
//functions definitions

double distance(point_t *p, int n){

  if (n <= 1) {
    return 0.0; // we need at least two points to have a value for the length
  }
    double hd, vd;
    //hd : Horizontal Distance
    //vd : Vertical Distance
    double l = 0.0; // length
    // To calculate the entire length, just add the distance between the points, two by two.
    int i;
    for ( i = 0; i < (n-1); i++) {
      hd = (p[i+1].x - p[i].x);
      vd = (p[i+1].y - p[i].y);
      l += sqrt(hd*hd + vd*vd);
    }
  return l;
}
