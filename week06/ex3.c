
#include<stdio.h> 
#include<stdbool.h>

void sorting_AT(int s, int matrix[][6]);
void swap(int *a, int *b);
void find_WTRR(int matrix[][6], int s, int quantum);
void find_TAT(int matrix[][6], int s);
void find_avgTime(int matrix[][6], int s,  int quantum);
int main() 
{ 
int quantum; 
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
  printf("Enter Quantum: ");
  scanf("%d", &quantum);
  
  sorting_AT(s,matrix);
  find_avgTime(matrix, s, quantum); 
  return 0; 
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
// Function to find the waiting time for all processes
void find_WTRR(int matrix[][6], int n, int quantum) 
{ 
  int rem_bt[n]; 
  for (int i = 0 ; i < n ; i++) 
    rem_bt[i] = matrix[i][1]; 

  int t = 0; 

  while (1) 
  { 
    bool done = true; 
    for (int i = 0 ; i < n; i++) 
    { 
 
      if (rem_bt[i] > 0) 
      { 
        done = false;  

        if (rem_bt[i] > quantum) 
        { 
          t += quantum; 
          rem_bt[i] -= quantum; 
        } 
        else
        { 
       
          t = t + rem_bt[i]; 

          matrix[i][3] = t - matrix[i][1]; 

          rem_bt[i] = 0; 
        } 
      } 
    } 

    if (done == true) 
    break; 
  } 
} 


void find_TAT(int matrix[][6], int s) 
{ 
  for (int i = 0; i < s ; i++) 
    matrix[i][4] = matrix[i][1] + matrix[i][3]; 
} 

// Function to calculate average time 
void find_avgTime(int matrix[][6], int s,  int quantum) 
{ 
  int total_wt = 0, total_tat = 0; 

  find_WTRR(matrix, s, quantum); 
  find_TAT(matrix, s); 

  printf("PID\t\t BT\t\t AT\t\t WT\t\t TAT\t\t CT\n"); 

  for (int i=0; i< s; i++) 
  { 
    total_wt = total_wt + matrix[i][3]; 
    total_tat = total_tat + matrix[i][4]; 
    int compl_time = matrix[i][4] + matrix[i][2]; 
    printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t%d\n",  matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3], matrix[i][4], compl_time); 
  } 

  printf("Average waiting time = %f\n", (float)total_wt / (float)s); 
  printf("Average turn around time =%f\n ", (float)total_tat / (float)s); 
} 

