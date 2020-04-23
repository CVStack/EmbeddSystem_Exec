#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * args[])
{
   int n = atoi(args[1]);
//    printf("%s\n",args[1]);

   for(int x = 1  ; x <= 9 ; x++) {

       printf("%d * %d = %d\n",x,n,x*n);
   }

    return 0;
}