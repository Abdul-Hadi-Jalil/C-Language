#include <stdio.h>
#include <pthread.h>

int counter = 0;

#define NUM_OF_THREADS 10
#define MAX_COUNT 1000000

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *increment_counter(void *arg)
{
    for (int i = 0; i < MAX_COUNT / NUM_OF_THREADS; i++)
    {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t threads[NUM_OF_THREADS];

    for (int i = 0; i < NUM_OF_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }

    for (int i = 0; i < NUM_OF_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("counter value is: %d\n", counter);
    pthread_mutex_destroy(&mutex);

    return 0;
}