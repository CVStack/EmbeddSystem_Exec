#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "prime.c"

extern int checkprime(int num);

int main(void){
    pid_t pid;

    if((pid=fork()) == 0){ // child process
        for(int i=0;i<=25000;i++){
            if(checkprime(i)) printf("%d ",i);
        }
        return 0;
    }

    if((pid=fork()) == 0){ // child process
        for(int i=25001;i<=50000;i++){
            if(checkprime(i)) printf("%d ",i);
        }
        return 0;
    }

    if((pid=fork()) == 0){ // child process
        for(int i=50001;i<=75000;i++){
            if(checkprime(i)) printf("%d ",i);
        }
        return 0;
    }

    for(int i=75001;i<=100000;i++){
        if(checkprime(i)) printf("%d ",i);
    }

    return 0;
}