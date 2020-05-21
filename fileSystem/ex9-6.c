#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

extern int errno;

int main() 
{

    struct stat buf;
    stat("unix.txt",&buf);
    printf("before Mode : %o\n", (unsigned int)buf.st_mode);
    chmod("unix.txt", 0711);
    stat("unix.txt",&buf);
    printf("after Mode : %o\n", (unsigned int)buf.st_mode);

}