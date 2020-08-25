#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
  int a;
  float b;
  double c;
  a = INT_MAX;
  b = FLT_MAX;
  c = DBL_MAX;
  printf("%lu, %d\n ,%lu, %f\n, %lu,  %g\n",sizeof(a),a,sizeof(b),b ,sizeof(c),c);  
  return 0;
}
