#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

extern int errno;

int main() 
{

    struct stat buf;
    stat("unix.txt",&buf);
    printf("before Link Count : %o\n", (unsigned int)buf.st_nlink);
    
    link("unix.txt","unix.ln");
    symlink("unix.txt","unix2.sym");

    stat("unix.txt",&buf); //하드 링크 생성
    printf("after Link Count : %o\n", (unsigned int)buf.st_nlink);

}