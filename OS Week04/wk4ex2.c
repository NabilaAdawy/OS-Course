#include <stdio.h>
#include <unistd.h>

int main() {
  for(int i=0; i < 5; i++){
    fork();
  }
  sleep(5);
  return 0;
}
/* the results will be 2^5 = 32 process, 
because each fork splits into 2 processes which resembles a binary tree */
