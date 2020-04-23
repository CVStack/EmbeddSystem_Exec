#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* threadfunc(void * data) {

    int  num = *((int *) data);

    pthread_t thread_id = pthread_self();
    for(int x = 1 ; x < 10; x++) {
        // pthread_mutex_lock(&m_lock);
        printf("%d * %d = %d\n", num, x, num * x);
        // pthread_mutex_unlock(&m_lock);        
    }
        

    return (void *) thread_id;
}

int main() {

    pthread_t tid;

    for(int x = 2 ; x < 10 ; x++) {
        pthread_create(&tid, NULL, threadfunc, (void *) &x);
        pthread_join(tid,NULL);
    }
    return 0;
}