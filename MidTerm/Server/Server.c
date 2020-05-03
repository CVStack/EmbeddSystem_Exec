#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include <errno.h>
#include "Server.h"

pthread_mutex_t m_lock; //한번에 한개의 스레드만 실행할때 사용

Node * head = NULL;
Node * tail = NULL;

void* sender(void * n) {

    int ns = *((int *)n);    
    char buf[256];
    int messageSize;

    while(1) {

        if((messageSize = recv(ns, buf, strlen(buf) + 1, 0)) == -1) {
            perror("recv");
            exit(1);
        }
        else if (messageSize == 0) {
            pthread_mutex_lock(&m_lock); //임계영역 list를 보호 --> 한번에 다수의 스레드가 삭제를 하게되면 List가 꼬일 수 있음.
            delete(&head,&tail,ns);
            pthread_mutex_unlock(&m_lock);
            return NULL;
        }
        else {
            buf[messageSize] = 0;
            fputs(buf,stdout);
            for(Node * temp = head; temp != NULL ; temp = temp->next){
                if(send(temp->ns, buf, messageSize, 0) == -1) { //send하는 도중에 해당 socket이 닫히면?
                    if(errno == ECONNRESET) { //peer(상대) 시스템에서 connection이 reset(close)됨. --> 계속 진행
                        continue;
                    }
                    perror("send");
                    exit(1);
                }
            }
        }
    }
    
}

int main (int argc, char **argv)
{
    if(argc != 2) {
        printf ("Usa%s <IP> <port> <name>\n", argv[0]);
		exit(1);
    }

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
    sin.sin_port = htons(atoi(argv[1])); //host to network --> byte ordering 
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
        if((*ns = accept(sd,(struct sockaddr *) &cli, &clientlen)) == -1) { //client가 들어올때 accept return 됨, client connect시 진입 시점
            perror("accept");
            exit(1);
        } //client accpet가 끝나면 반복
        insert(&head,&tail,*ns);
        pthread_create(&tid, NULL, sender, ns);
    }

    return 0;
}