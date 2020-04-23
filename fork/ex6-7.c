#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <time.h>
// #include <math.h>

int main() 
{
    // clock_t start = clock();

    for(int x = 1 ; x <= 100000; x++) {
        int y;
        for(y = 2 ; y < x ; y++) {
            if(x % y == 0) {

                // printf("%d not prime",x);
                break;
            }
        }
        
        if(x == y)
            printf("%d\n",x);        
    }    

    // clock_t end = clock();

    // printf("Time : %lf \n",(double) (end -start) / CLOCKS_PER_SEC);
}