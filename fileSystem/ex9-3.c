#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() 
{

    struct stat buf;
    int kind;

    stat("unix.txt",&buf); //buf에 정보 담아옴

    printf("Mode = %o (16진수 : %x)\n",(unsigned int) buf.st_mode,(unsigned int) buf.st_mode);

    kind = buf.st_mode & S_IFMT; //File 종류만 추출

    printf("Kind = %x\n",kind);

    switch(kind) {

        case S_IFIFO:
            printf("unix.txt : FIFO\n");
            break;
        case S_IFDIR:
            printf("unix.txt : Directory\n");
            break;
        case S_IFREG:
            printf("unix.txt : Regular File\n");
            break;
    }
}