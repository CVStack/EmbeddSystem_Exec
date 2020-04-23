#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int myvar = 0;
    if(fork())
        myvar = 1;
    else if(fork())
        myvar = 2;
    else
        myvar = 3;

    printf("I'm %d: myvar is %d\n", (int)getpid(), myvar);
    return 0;
}