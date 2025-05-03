// Create a program that spawns 5 threads, each printing "Hello from thread X" (where X is the thread number).

#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    int thread_num = *(int *)arg;
    printf("Hello from thread # %d", thread_num);
}

int main()
{
    pthread_t thread1, thread2, thread3, thread4, thread5;

    pthread_create(&thread1, NULL, thread_function, (void *)1);
    pthread_create(&thread2, NULL, thread_function, (void *)2);
    pthread_create(&thread3, NULL, thread_function, (void *)3);
    pthread_create(&thread4, NULL, thread_function, (void *)4);
    pthread_create(&thread5, NULL, thread_function, (void *)5);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);

    return 0;
}