#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * args[])
{
    int status;
    pid_t pid;

    switch(pid = fork()) {

        case 0 :
            printf("CHILD PROCESS\n");
            if(execlp("./ex6-5","ex6-5",args[1],(char *)NULL) == -1) { // execlp(path,program_name,arguments,..)ex6-5 로 바꿔서 자식 프로세스 실행, parameter 의 끝 = NULL
                perror("execlp");
                exit(1);
            }
            sleep(2000);
            exit(2);
            break;
    
        default :
            wait(&status); //child의 process를 가디림.
            printf("PARENT PROCESS\n");
            break;

    }
}