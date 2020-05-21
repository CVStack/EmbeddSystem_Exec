#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main() 
{
    int rfd;
    char buf[256];

    rfd = open("test.txt",O_RDONLY);

    lseek(rfd, 23, SEEK_CUR);

    read(rfd,buf,17);
    buf[17] = '\0';

    printf("%s\n",buf);
}