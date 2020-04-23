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
    int sd, clientlen = sizeof(cli);

    if((sd = socket(AF_INET, SOCK_DGRAM, 0)) == - 1) { //인터 네트워크, UDP, 프로토콜
        perror("socket");
        exit(1);
    }

    memset((char *) &sin, '\0', sizeof(sin)); // '\0'으로 초기화
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM); //host to network --> byte ordering 
    sin.sin_addr.s_addr = inet_addr("0.0.0.0"); // string -> ip, open to anyway

    if(bind(sd, (struct sockaddr *)&sin, sizeof(sin))) { //socket에 port와 addr bind 시킴

        perror("bind");
        exit(1);
    } 
    
    while(1) {

        if((recvfrom(sd, buf, 255, 0, (struct sockaddr *) &cli, &clientlen)) == -1) {
            perror("recvfrom");
            exit(1);                    
        }

        printf("** From Client : %s\n",buf);
        strcpy(buf, "Hello client");
        if(sendto(sd, buf, strlen(buf) + 1, 0, (struct sockaddr * )&cli, sizeof(cli)) == -1) {

            perror("sendto");
            exit(1);
        }
    }
    return 0;
}