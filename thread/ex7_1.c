#include <stdio.h>
#include <pthread.h>

void* threadfunc(void * vargp) {

    sleep(1);
    printf("Hello, world\n");
    return NULL;
}

int main() {

    pthread_t tid;
    pthread_create(&tid,NULL,threadfunc,NULL); //pthread_t, pthread_t_attr, thread_function, thread_args
    printf("main\n");

    pthread_join(tid,NULL); //main thread는 tid의 스레드를 기다린후 실행
    printf("main2\n");
    sleep(2);
    return 0;
}