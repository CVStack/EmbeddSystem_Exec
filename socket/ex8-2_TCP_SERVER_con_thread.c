#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <pthread.h>

#define PORTNUM 9000

pthread_mutex_t m_lock; //한번에 한개의 스레드만 실행할때 사용

void* sender(void * n) {

    int ns = *((int *)n);    
    char buf[256];

    strcpy(buf, "Welcome to NetWork Server!");
    if(send(ns, buf, strlen(buf) + 1, 0) == -1) {
        perror("send");
        exit(1);
    }

    if(recv(ns, buf, strlen(buf) + 1, 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("From client : %s\n",buf);
}

int main()
{
    struct sockaddr_in sin, cli;

    int sd,clientlen = sizeof(cli);
    int * ns;
    pthread_t tid;

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
    
    if(listen(sd,5)) { //client가 server에 접속하면 listen부터 시행

        perror("listen");
        exit(1);
    }


    while(1) {
        ns = (int *) malloc(sizeof(int));
        printf("client listen comming\n");
        if((*ns = accept(sd,(struct sockaddr *) &cli, &clientlen)) == -1) { //client가 들어올때 accept return 됨
            perror("accept");
            exit(1);
        } //client accpet가 끝나면 반복
        pthread_create(&tid, NULL, sender, ns);
    }

    return 0;
}