#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <time.h>
// #include <math.h>

int first = 1,second = 25000;

int main() 
{
    // clock_t start = clock();

    if(fork() == 0) {
        for(int x = 1 ; x <= 25000; x++) {
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
            
            return 0;
    }
       
    if(fork() == 0) {
        for(int x = 25001 ; x <= 50000; x++) {
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
            
            return 0;
    }

    if(fork() == 0) {
        for(int x = 50001 ; x <= 75000; x++) {
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
            
            return 0;
    }

    
    if(fork() == 0) {

        for(int x = 75001 ; x <= 100000; x++) {
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

        return 0;
    }

    printf("finish\n");    
    return 0;
    
    // clock_t end = clock();

    // printf("Time : %lf \n",(double) (end -start) / CLOCKS_PER_SEC);

    
}