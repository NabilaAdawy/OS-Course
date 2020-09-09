                                                   
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
char input[100];
printf("Enter desired command \n");
printf("To exit write 0 ");
for(;;){
printf("> ");
fgets(input, 100, stdin);
if(input[0] == '0') break;
system(input);

}
return 0;
}

