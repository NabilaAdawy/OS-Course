#include <stdio.h>
#include <unistd.h>

int main() {
  int n = fork();
  sleep(1);
  if (n != 0){
    printf("Hello from parent [%d - %d]\n", getpid(), n);
    }
    else{
    printf("Hello from child [%d - %d]\n", getpid(), n);
    }
    return 0;
}
