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

    int sd,n;

    if((sd = socket(AF_INET, SOCK_DGRAM, 0)) == - 1) { //인터 네트워크, TCP, 프로토콜

        perror("socket");
        exit(1);
    }

    memset((char *) &sin, '\0', sizeof(sin)); // '\0'으로 초기화
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM); //host to network --> byte ordering 
    sin.sin_addr.s_addr = inet_addr("ip"); // string -> ip, open to anyway

    strcpy(buf, "I am a client. ");

    if(sendto(sd,buf, strlen(buf) + 1, 0, (struct sockaddr *) &sin, sizeof(sin)) == -1) {

        perror("sendto");
        exit(1);
    }

    n = recvfrom(sd,buf,255,0,NULL,NULL);
    buf[n] = '\0';
    printf("** From Server : %s\n", buf);


    return 0;
}