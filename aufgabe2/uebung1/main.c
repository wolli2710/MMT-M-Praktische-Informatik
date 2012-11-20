#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <emmintrin.h>

#define SM (CLS / sizeof(double))
#define N 1000

int main(){ 
  srand(time(NULL));

  struct timeval start,end;

  int measure1, measure2, measure3;
  int i,i2,j,j2,k,k2;

  static double res[N][N] __attribute__ ((aligned (64)));
  static double mul2[N][N] __attribute__ ((aligned (64)));
  static double mul1[N][N] __attribute__ ((aligned (64)));

  double *restrict rmul1;
  double *restrict rmul2;
  double *restrict rres;

  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      mul1[i][j] = 0;
      mul2[i][j] = rand()%10;
      res[i][j] = 0;
    }
  }

  gettimeofday(&start, 0);
  for (i = 0; i < N; ++i)
    for (j = 0; j < N; ++j)
      for (k = 0; k < N; ++k)
        res[i][j] += mul1[i][k] * mul2[k][j];
  gettimeofday(&end, 0);
  measure1 = (end.tv_sec - start.tv_sec) * 1000.0;
  measure1 += (end.tv_usec-start.tv_usec) / 1000.0;

  gettimeofday(&start, 0);
  double tmp[N][N];
  for (i = 0; i < N; ++i)
    for (j = 0; j < N; ++j)
      tmp[i][j] = mul2[j][i];
  for (i = 0; i < N; ++i)
    for (j = 0; j < N; ++j)
      for (k = 0; k < N; ++k)
        res[i][j] += mul1[i][k] * tmp[j][k];
  gettimeofday(&end, 0);
  measure2 = (end.tv_sec - start.tv_sec) * 1000.0;
  measure2 += (end.tv_usec-start.tv_usec) / 1000.0;

  gettimeofday(&start, 0);
  for (i = 0; i < N; i += SM)
    for (j = 0; j < N; j += SM)
      for (k = 0; k < N; k += SM)
        for (i2 = 0, rres = &res[i][j],
            rmul1 = &mul1[i][k]; i2 < SM;
            ++i2, rres += N, rmul1 += N)
          for (k2 = 0, rmul2 = &mul2[k][j];
              k2 < SM; ++k2, rmul2 += N)
            for (j2 = 0; j2 < SM; ++j2)
            rres[j2] += rmul1[k2] * rmul2[j2];
  gettimeofday(&end, 0);
  measure3 = (end.tv_sec - start.tv_sec) * 1000.0;
  measure3 += (end.tv_usec-start.tv_usec) / 1000.0;

  printf("Code1: %d \n", measure1);
  printf("Code2: %d \n", measure2);
  printf("Code3: %d \n", measure3);

  return 0;
}