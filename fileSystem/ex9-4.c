#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() 
{

    struct stat buf;
    int kind;

    stat("hanbit",&buf); //buf에 정보 담아옴

    printf("Mode = %o (16진수 : %x)\n",(unsigned int) buf.st_mode,(unsigned int) buf.st_mode);

    kind = buf.st_mode & S_IFMT; //File 종류만 추출

    printf("Kind = %x\n",kind);

    if(S_ISFIFO(buf.st_mode))
        printf("unix.txt : FIFO\n");
    if(S_ISDIR(buf.st_mode))
        printf("unix.txt : Directory\n");
    if(S_ISREG(buf.st_mode))
        printf("unix.txt : Regular\n");
}