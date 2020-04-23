#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t p;
    printf("MY PID : %d\n",(int)getpid());

    switch(p = fork()) {

        case 0 :
            printf("MYPID : %d, My PARENT PID : %d\n",(int)getpid(),(int)getppid());
            break;
        default:
            printf("MYPID : %d, My PARENT PID : %d MY CHILD PID : %d\n",(int)getpid(),(int)getppid(),p);
            break;
        
    }
    return 0;
}