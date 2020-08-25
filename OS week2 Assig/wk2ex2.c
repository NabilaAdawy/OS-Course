#include <stdio.h>
#include <limits.h>
#include <string.h>
int main(void) {
  char str[100];
  fgets(str, 100, stdin);
  int i = strlen(str);
  while( i >= 0){
    printf("%c", str[i]);
    i--;
  }
  return 0;
}

