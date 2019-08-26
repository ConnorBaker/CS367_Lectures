#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 900

void transpose_a(int src[SIZE][SIZE], int dst[SIZE][SIZE]);
void transpose_b(int src[SIZE][SIZE], int dst[SIZE][SIZE]);

int main() {
  int ary1[SIZE][SIZE];
  int ary2[SIZE][SIZE];
  int i, j;

  srand(time(NULL));

  for(i = 0; i < SIZE; i++) {
    for(j = 0; j < SIZE; j++) {
      ary1[i][j] = rand()%255;
    }
  }
 
  for(i = 0; i < 500; i++) {
    transpose_a(ary1, ary2);
  }

  for(i = 0; i < 500; i++) {
    transpose_b(ary1, ary2);
  }

  return 0;
}

void transpose_a(int src[SIZE][SIZE], int dst[SIZE][SIZE]) {
  int i, j;
  for(i = 0; i < SIZE; i++) {
    for(j = 0; j < SIZE; j++) {
      dst[i][j] = src[j][i];
    }
  }
}

void transpose_b(int src[SIZE][SIZE], int dst[SIZE][SIZE]) {
  int i, j;
  for(j = 0; j < SIZE; j++) {
    for(i = 0; i < SIZE; i++) {
      dst[i][j] = src[j][i];
    }
  }
}
