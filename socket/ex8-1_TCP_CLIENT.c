#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/un.h>

#define PORTNUM 9000

int main()
{
    char buf[256];
    struct sockaddr_in sin, cli;

    int sd;

    if((sd = socket(AF_INET, SOCK_STREAM, 0)) == - 1) { //인터 네트워크, TCP, 프로토콜

        perror("socket");
        exit(1);
    }

    memset((char *) &sin, '\0', sizeof(sin)); // '\0'으로 초기화
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM); //host to network --> byte ordering 
    sin.sin_addr.s_addr = inet_addr("172.17.0.2"); // string -> ip, open to anyway

    if(connect(sd,(struct sockaddr *) &sin, sizeof(struct sockaddr))) { // server에서 accpet하고 send함
        perror("connect");
        exit(1);
    } 

    if(recv(sd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        exit(1);
    }

    close(sd);
    printf("From Server : %s\n",buf);

    return 0;
}