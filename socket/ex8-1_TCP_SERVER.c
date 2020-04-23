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

    int sd, ns, clientlen = sizeof(cli);

    if((sd = socket(AF_INET, SOCK_STREAM, 0)) == - 1) { //인터 네트워크, TCP, 프로토콜

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
    
    if(listen(sd,5)) {

        perror("listen");
        exit(1);
    }

    if((ns = accept(sd,(struct sockaddr *) &cli, &clientlen)) == -1) { //client가 들어올때 accept return 됨

        perror("accept");
        exit(1);
    }

    sprintf(buf, "Your IP Address is %s",inet_ntoa(cli.sin_addr)); //str에 문자열을 씀.
    if(send(ns, buf, strlen(buf) + 1, 0) == -1) {

        perror("send");
        exit(1);
    }

    close(ns);
    close(sd);

    return 0;
}