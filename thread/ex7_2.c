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

    pthread_detach(tid); //현재 thread에서 tid 스레드를 분리함.
    printf("main2\n");
    sleep(2);
    return 0;
}