//implementation of Shortest Job first with Arrival Time 
#include<stdio.h> 

int matrix[10][6]; 
void sorting_AT(int s, int matrix[][6]);
void swap(int *a, int *b);
void sorting_SJF(int s, int matrix[][6]);
void find_WT(int matrix[][6], int s);
void find_TAT(int matrix[][6], int s);
void find_AWT(int matrix[][6], int s);

int main() 
{ 
  int s;
  
 printf("Enter number of Process: "); 
  scanf("%d", &s); 
  int matrix[s][6];
  
  printf("Enter the process ID \n"); 
  for(int i=0; i< s; i++) 
  { 
     
    printf("Enter Process[%d] Id: ", i+1); 
    scanf("%d", &matrix[i][0]); 
  }
   for(int i=0; i< s; i++) 
  { 
    printf("Enter Burst Time for process[%d] : ", i+1); 
    scanf("%d", &matrix[i][1]); 
  }
   for(int i=0; i< s; i++) 
  {
    printf("Enter Arrival Time for process[%d] : ", i+1 ); 
    scanf("%d", &matrix[i][2]); 
  } 
  
  sorting_AT(s, matrix); 
  sorting_SJF(s, matrix);
  find_AWT(matrix, s); 

}

void sorting_AT(int s, int matrix[][6]) 
{ 
  for(int i=0; i< s; i++) 
  { 
    for(int j=0; j< s-i-1; j++) 
    { 
      if(matrix[j][1] > matrix[j+1][1]) 
      { 
        for(int k=0; k< 5; k++) 
        { 
          swap(&matrix[j][k], &matrix[j+1][k]); 
        } 
      } 
    } 
  } 
} 
void swap(int *a, int *b) 
{ 
  int temp = *a; 
  *a = *b; 
  *b = temp; 
}

void sorting_SJF(int s, int matrix[][6]) 
{ 
  for(int i=0; i< s; i++) 
  { 
    for(int j=0; j< s-i-1; j++) 
    { 
      if(matrix[j][2] > matrix[j+1][2]) 
      { 
        for(int k=0; k< 5; k++) 
        { 
          swap(&matrix[j][k], &matrix[j+1][k]); 
        } 
      } 
    } 
  } 
}

void find_WT(int matrix[][6], int s) 
{ 
  int service_time[s]; 
  service_time[0] = 0; 
  matrix[0][3] = 0; 

  for (int i = 1; i < s ; i++) 
  { 
    service_time[i] = service_time[i-1] + matrix[i-1][1]; 

    // waiting time for current process = sum - at[i] 
    matrix[i][3] = service_time[i] - matrix[i][2]; 

    if (matrix[i][3] < 0) 
      matrix[i][3] = 0; 
  } 
} 

void find_TAT(int matrix[][6], int s) 
{ 
  for (int i = 0; i < s ; i++) 
    matrix[i][4] = matrix[i][1] + matrix[i][3]; 
} 


// Function to calculate average waiting and turn-around times. 
void find_AWT(int matrix[][6], int s) 
{ 
  // Function to find waiting time of all matrix
  find_WT(matrix, s); 

  // Function to find turn around time for all mat 
  find_TAT(matrix, s); 

  // Display matrix along with all details 
  printf("PID\t\t BT\t\t AT\t\t WT\t\t TAT\t\tCT\n"); 
  int total_wt = 0, total_tat = 0; 
  for (int i = 0 ; i < s ; i++) 
  { 
    total_wt = total_wt + matrix[i][3]; 
    total_tat = total_tat + matrix[i][4]; 
    int compl_time = matrix[i][4] + matrix[i][2]; 
    printf(  "%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t%d\n", matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3], matrix[i][4], compl_time); 
  } 

  printf("Average waiting time = %f\n", (float)total_wt / (float)s); 
  printf("Average turn around time = %f\n",(float)total_tat / (float)s); 
} 

