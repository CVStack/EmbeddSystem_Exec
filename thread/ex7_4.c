#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define Max_thread 20
pthread_mutex_t m_lock; //한번에 한개의 스레드만 실행할때 사용

void* threadfunc(void * data) {

    int * count = (int *) data;

    pthread_t thread_id = pthread_self();
    for(int x = 0 ; x < 10000; x++) {
        pthread_mutex_lock(&m_lock);
        *count = *count + 1;
        pthread_mutex_unlock(&m_lock);        
    }
        

    return (void *) thread_id;
}

int main() {

    pthread_t thread_arr[Max_thread];
    int count = 0;

    if(pthread_mutex_init(&m_lock,NULL) != 0) {

        perror("Mutex Init failure");
        return -1;
    }

    for(int x = 0 ; x < Max_thread ; x++)
        pthread_create(&thread_arr[x],NULL,(void *)threadfunc,&count); 
    for(int x = 0 ; x < Max_thread ; x++)
        pthread_join(thread_arr[x],NULL);
    
    pthread_mutex_destroy(&m_lock);
    printf("Main Thread : %d\n",count); //한번에 하나의 스레드를 실행하기 때문에 정상적인 결과가 나옴.
    return 0;
}