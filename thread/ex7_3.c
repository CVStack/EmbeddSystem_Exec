#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define Max_thread 20

void* threadfunc(void * data) {

    int * count = (int *) data;

    pthread_t thread_id = pthread_self();
    for(int x = 0 ; x < 10000; x++)
        *count = *count + 1;

    return (void *) thread_id;
}

int main() {

    pthread_t thread_arr[Max_thread];
    int count = 0;
    for(int x = 0 ; x < Max_thread ; x++)
        pthread_create(&thread_arr[x],NULL,(void *)threadfunc,&count); 
    for(int x = 0 ; x < Max_thread ; x++)
        pthread_join(thread_arr[x],NULL);
    
    printf("Main Thread : %d\n",count); //각 스레드가 업데이트된 count를 사용하지 않기 때문에 정상적인 결과값이 안나옴.
    return 0;
}