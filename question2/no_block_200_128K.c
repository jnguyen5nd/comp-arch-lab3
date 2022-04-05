#include <stdio.h>
#include <math.h>

#define XSIZE 200
#define YSIZE 200

int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];
  int cache[1<<11] = {0};
  long unsigned int addr, tag, index, offset;
  double misses = 0, accesses = 0;

  int i, j, k;

  int r;

  /* Initialize x matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      x[i][j] = 0;
    }
  }

  /* Initialize y matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      y[i][j] = i + j;
    }
  }

  /* Initialize z matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
    	z[i][j] = i + j;
    }
  }

  /* Do matrix multiply */
  for(i=0; i<XSIZE; i=i+1) {
    for(j=0; j<YSIZE; j=j+1) {
      r = 0;
      for(k=0; k<XSIZE; k=k+1) {
        r = r + y[i][k] * z[k][j];

        addr = (long unsigned int) &y[i][k];
        offset = addr & 0x00000000003f;
        index  = (addr & 0x00000001ffc0) >> 6;
        tag    = (addr & 0xfffffffe0000) >> 17;

        if (cache[index] != tag) misses++;
        cache[index] = tag;
        accesses++;

        addr = (long unsigned int) &z[k][j];
        offset = addr & 0x00000000003f;
        index  = (addr & 0x00000001ffc0) >> 6;
        tag    = (addr & 0xfffffffe0000) >> 17;

        if (cache[index] != tag) misses++;
        cache[index] = tag;
        accesses++;

      }
      x[i][j] = r;

      addr = (long unsigned int) &x[i][j];
      offset = addr & 0x00000000003f;
      index  = (addr & 0x00000001ffc0) >> 6;
      tag    = (addr & 0xfffffffe0000) >> 17;

      if (cache[index] != tag) misses++;
      cache[index] = tag;
      accesses++;

    }
  }

  printf("Misses: %.2lf\tAccesses: %.2lf\tMiss Rate: %.3lf%%\n", misses, accesses, misses/accesses*100);
}
