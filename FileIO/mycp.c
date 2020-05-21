#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{

    int rfd, wfd, n;
    char buf[10];

    rfd = open(argv[1], O_RDONLY); //읽기전용으로 파일 open

    if(rfd == -1) {
        perror(argv[1]); //read 파일 open 실패시
        exit(1);
    }
    wfd = open(argv[2], O_WRONLY | O_CREAT); //쓰기전용으로 파일을 열면서, 해당 파일이 없으면 새로 만듬
    if(wfd == -1) {
        perror(argv[2]); //write 파일 open 실패시
        exit(1);
    }

    while((n = read(rfd, buf, 9)) > 0) { //read 파일로부터 9바이트를 읽어옴 (9바이트 이하일경우 대비)
        if(write(wfd, buf, n) != n) // 읽어온 바이트 만큼 안쓰여지면 error
            perror("write");
    }

}