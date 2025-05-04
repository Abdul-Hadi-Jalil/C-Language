// Create a program that spawns 5 threads, each printing "Hello from thread X" (where X is the thread number).

#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

void *thread_function(void *arg)
{
    int thread_num = (int)(intptr_t)arg;
    printf("Hello from thread # %d \n", thread_num);
    return NULL;
}

int main()
{
    pthread_t thread1, thread2, thread3, thread4, thread5;

    pthread_create(&thread1, NULL, thread_function, (void *)(intptr_t)1);
    pthread_create(&thread2, NULL, thread_function, (void *)(intptr_t)2);
    pthread_create(&thread3, NULL, thread_function, (void *)(intptr_t)3);
    pthread_create(&thread4, NULL, thread_function, (void *)(intptr_t)4);
    pthread_create(&thread5, NULL, thread_function, (void *)(intptr_t)5);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);

    getchar();
    return 0;
}