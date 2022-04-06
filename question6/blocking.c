#include <stdio.h>
#include <math.h>

#define XSIZE 200
#define YSIZE 200

int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];
  // int cache[1<<11] = {0};
  // long unsigned int addr, tag, index, offset;
  // double misses = 0, accesses = 0;

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
  int p, q, jj, kk;
  int B = 10;
  for(jj = 0; jj < XSIZE; jj = jj+B) {
    for(kk = 0; kk < YSIZE; kk = kk+B) {
      for(i = 0; i < XSIZE; i = i+1) {
        // Check for blocking factor greater than array size
        p = ((jj + B) < YSIZE) ? jj + B : YSIZE;

        for(j = jj; j < p; j = j+1) {
          r=0;
          // Check for blocking factor greater than array size
          q = ((kk + B) < XSIZE) ? kk + B : XSIZE;

          for(k = kk; k < q; k = k+1) {
            r = r + y[i][k] * z[k][j];

            // addr = (long unsigned int) &y[i][k];
            // offset = addr & 0x00000000001f;
            // index  = (addr & 0x00000000ffe0) >> 5;
            // tag    = (addr & 0xffffffff0000) >> 16;
            //
            // if (cache[index] != tag) misses++;
            // cache[index] = tag;
            // accesses++;
            //
            // addr = (long unsigned int) &z[k][j];
            // offset = addr & 0x00000000001f;
            // index  = (addr & 0x00000000ffe0) >> 5;
            // tag    = (addr & 0xffffffff0000) >> 16;
            //
            // if (cache[index] != tag) misses++;
            // cache[index] = tag;
            // accesses++;
          }

          x[i][j] = x[i][j] + r;

          // addr = (long unsigned int) &x[i][j];
          // offset = addr & 0x00000000001f;
          // index  = (addr & 0x00000000ffe0) >> 5;
          // tag    = (addr & 0xffffffff0000) >> 16;
          //
          // if (cache[index] != tag) misses++;
          // cache[index] = tag;
          // accesses++;
          //
          // addr = (long unsigned int) &x[i][j];
          // offset = addr & 0x00000000001f;
          // index  = (addr & 0x00000000ffe0) >> 5;
          // tag    = (addr & 0xffffffff0000) >> 16;
          //
          // if (cache[index] != tag) misses++;
          // cache[index] = tag;
          // accesses++;

        }
      }
    }
  }

  // printf("B: %d\tMisses: %.2lf\tAccesses: %.2lf\tMiss Rate: %.3lf%%\n", B, misses, accesses, misses/accesses*100);

  /* Print the Matrix*/
  // for (int row = 0; row < 8; row++) {
  //   for (int col = 0; col < 8; col++)
  //     printf("%4d ", x[row][col]);
  //   putchar(10);
  // }
}
