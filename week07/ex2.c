#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int N;
  printf("Enter the size of the array: ");
  scanf("%d", &N);
  int *array = malloc(N*sizeof(int));
  array[0] = 0;
  for (int i=1; i < N; i++){
    array[i] = array[i-1] + 1;
  }
  for(int i =0; i < N; i++){
    printf("Array[%d] = %d \n", i, array[i]);
  }
  free(array);
  return 0;
}
