#ifndef MATMUL
#define MATMUL
#include <cblas.h>
#include <stdio.h>
#include <time.h>
long long multiply_matrices(int n,int* e)
{
  int i=0;
  double *A, *B, *C;
  printf("C = A * B<br />");
  printf("matrix sizes %d*%d\n",n,n);
  A = (double*) malloc(n*n*sizeof(double));
  B = (double*) malloc(n*n*sizeof(double));
  C = (double*) malloc(n*n*sizeof(double));
  if (A==NULL || B==NULL || C==NULL){
      printf("malloc error");
      if (A) free(A);
      if (B) free(B);
      if (C) free(C);
      *e=-1;
      return 0.0;
  }
  for (int i=0;i<n*n;i++){
      A[i] = (double)(((i+13)*83)%101);
      B[i] = (double)(((i+29)*11)%283);
      C[i] = 0.0;
  }
  double a  = 1.0;
  double b = 0.0;
  clock_t start = clock();
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,n,n,n,a ,A , n, B, n,0.0,C,n);
  clock_t end = clock();
  if (n>10){
      print("matrices are too large: not printing them<br />");
  }
  else 
  {
  printf("matrix A:<br />");
  for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
         printf("%f ",A[i*n+j]);
      }
      printf("<br />");
  }
  printf("matrix B:<br />");
  for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
         printf("%f ",B[i*n+j]);
      }
      printf("<br />");
  }

  printf("matrix C:<br />");
  for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
         printf("%f ",C[i*n+j]);
      }
      printf("<br />");
  }
  }
  double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  if (A) free(A);
  if (B) free(B);
  if (C) free(C);

  return cpu_time_used;
}
#endif
