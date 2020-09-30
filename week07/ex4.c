#include <stdio.h>
#include <stdlib.h>
#include <string.h>			
#define min(a, b) ( ((a) < (b)) ? (a) : (b) )


void* new_realloc(void *ptr, size_t sNew, size_t sOld){
    if (sNew == 0){
      free(ptr);
      return NULL;
    }
    if(ptr == NULL){
      return malloc(sNew);
    }
    int *array = malloc(sNew); 
    size_t sMin = min(sNew, sOld);
    memcpy(array, ptr, sMin);
    return array;

}
void print_array(int *arr, int size)
{
	if(arr == NULL)
		return;
	printf("{ ");
	int i=0;
	for(i=0; i<size-1; i++)
		printf("%d, ", arr[i]);
	printf("%d }\n", arr[i]);
}


int main(void) {
  int size , old_size;
  printf("Enter the  size of the array: ");
  scanf("%d", &size);
	printf("Creating an array of %d integers \n", size);
	int *arr = (int*)new_realloc(NULL, size*sizeof(int), 0);
	for(int i=0; i<size; i++)
		arr[i] = i;
	printf("Array content:\n ");
	print_array(arr, size);


	old_size = size;
  printf("Enter the new size of the array to be increased : ");
  scanf("%d", &size);
	printf("\nResizing to be %d integers  \n", size);
	arr = (int*)new_realloc(arr, size*sizeof(int), old_size*sizeof(int));
	printf("New array contents:\n ");
	print_array(arr, size);

	old_size = size;
  printf("Enter the new size of the array to be decreased : ");
  scanf("%d", &size);
	printf("\nResizing to be %d integers \n", size);
	arr = (int*)new_realloc(arr, size*sizeof(int), old_size*sizeof(int));
	printf("New array contents:\n ");
	print_array(arr, size);

	// Free the array
	printf("\nFreeing the array\n");
	arr = (int*)new_realloc(arr, 0, 0);
	printf("Pointer after freeing: %p\n", arr);

	return 0;
}
