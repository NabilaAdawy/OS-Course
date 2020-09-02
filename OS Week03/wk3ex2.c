#include <stdio.h>
#include <stdlib.h>

void sp (int *A, int *B){
  int temp;
  temp = *A;
  *A = *B;
  *B = temp;
}

void bubble_sort(int arr[],int l){
    for(int i=0; i < l-1; i++){
        for(int j=0; j < l-i-1; j++){
         if(arr[j] > arr[j+1])
                sp(&arr[j], &arr[j+1]);
        }
    }
}
void printArr(int arr[], int l){
    for(int i=0; i < l ; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main()
{
    int l;
    printf("Enter the array size:");
    scanf("%d", &l);
    int array[l];
    printf("Enter the array elements:");
    for(int i =0; i < l; i++){
        scanf("%d", &array[i]);
    }

    bubble_sort(array,l);
    printArr(array,l);
}


