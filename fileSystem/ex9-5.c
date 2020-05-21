#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>

extern int errno;

int main() 
{

    int per;

    if(access("unix.bak", F_OK) == -1 && errno == ENOENT) { //해당 파일이 존재하는지
        printf("unix.bak is not exist file\n");
    }

    per = access("unix.txt", R_OK); //해당 파일이 읽기 가능한지 확인

    if(per == 0)
        printf("unix.txt is able to read\n");
    else if(per == -1 && errno == EACCES) // 접근 불가
        printf("unix.txt is not able to read\n");
}