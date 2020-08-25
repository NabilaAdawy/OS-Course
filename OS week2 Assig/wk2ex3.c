#include <stdio.h>

int main(int argc ,char* argv[]) {
  int hight;
  char s[100];
  sscanf(argv[1] ,"%d", &hight);
  int width = 2*hight -1;
  int n =0;
  for(int i=0; i < hight; i++){
    for (int j=0; j < width; j++){
      if(j < width/2 -n || j > width/2 -n){
        printf(" ");
      }else {
        for(int k=0; k < hight - (width/2-2*n) ;k++){
        printf("*");
        }
      }
    }
      n++;
      printf("\n");
    }

  return 0;
}

