#include <stdio.h>

int swap (int *A, int *B){
  int temp;
  temp = *A;
  *A = *B;
  *B = temp;
  printf("\nAfter swapping, firstNumber = %d\n", *A);
  printf("After swapping, secondNumber = %d", *B);
  return 0;
}

int main(void) {
  int A, B;
  printf("Enter fisrt number: ");
  scanf("%d", &A);
  printf("Enter second number: ");
  scanf("%d", &B);
  swap(&A, &B);
  return 0;
}
