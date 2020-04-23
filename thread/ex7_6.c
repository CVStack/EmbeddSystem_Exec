#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t m_lock; //한번에 한개의 스레드만 실행할때 사용

void* threadfunc(void * data) {

    // pthread_mutex_lock(&m_lock);
    int  num = *((int *) data);
    printf("thread : %d %ud\n", num, (int)pthread_self()); //thread는 data, code 영역을 공유하기 때문에 lock이 필요
    pthread_mutex_unlock(&m_lock);
}

int main(int argnum, char ** args) {

    pthread_t tid;
    if(pthread_mutex_init(&m_lock,NULL) != 0) {

        perror("Mutex Init failure");
        return -1;
    }

    int last = atoi(args[1]);
    printf("last : %d\n",last);

    for(int x = 0 ; x < last ; x++) {
        pthread_mutex_lock(&m_lock);
        pthread_create(&tid, NULL, threadfunc, (void *) &x);
        sleep(1);
        // pthread_join(tid,NULL); 
    }

    printf("finish\n");
    return 0; 
}