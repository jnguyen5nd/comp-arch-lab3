#include <stdio.h>
#include <math.h>

#define XSIZE 200
#define YSIZE 200

int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];

  int i, j, k;

  int r;

  /* Initialize x matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      x[i][j] = 0;
      if (i < 3 || i >= 197) {
        if (j < 3 || j >= 197) printf("X[%3d][%3d]: %p  ", i, j, &x[i][j]);
        else if (j == 4) printf("\t...\t");
      }
    }
    if (i < 3 || i >= 197) putchar(10);
    if (i == 4) printf("...\n");
  }
  putchar(10);


  /* Initialize y matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      y[i][j] = i + j;
      if (i < 3 || i >= 197) {
        if (j < 3 || j >= 197) printf("Y[%3d][%3d]: %p  ", i, j, &y[i][j]);
        else if (j == 4) printf("\t...\t");
      }
    }
    if (i < 3 || i >= 197) putchar(10);
    if (i == 4) printf("...\n");
  }
  putchar(10);


  /* Initialize z matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
    	z[i][j] = i + j;
      if (i < 3 || i >= 197) {
        if (j < 3 || j >= 197) printf("Z[%3d][%3d]: %p  ", i, j, &z[i][j]);
        else if (j == 4) printf("\t...\t");
      }
    }
    if (i < 3 || i >= 197) putchar(10);
    if (i == 4) printf("...\n");
  }

  /* Do matrix multiply */
  for(i=0; i<XSIZE; i=i+1) {
    for(j=0; j<YSIZE; j=j+1) {
      r = 0;
      for(k=0; k<XSIZE; k=k+1) {
        r = r + y[i][k] * z[k][j];
      }
      x[i][j] = r;
    }
  }
}
