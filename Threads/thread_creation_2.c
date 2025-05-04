#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

void *thread_function(void *arg)
{
    int thread_num = (int)(intptr_t)arg;
    int square = thread_num * thread_num;
    return (void *)(intptr_t)square;
}

int main()
{
    pthread_t threads[5];
    int results[5] = {0};

    // Create threads
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&threads[i], NULL, thread_function, (void *)(intptr_t)(i + 1));
    }

    // Wait for threads and collect results
    for (int i = 0; i < 5; i++)
    {
        void *retval;
        pthread_join(threads[i], &retval);
        results[i] = (int)(intptr_t)retval;
    }

    // Print results
    for (int i = 0; i < 5; i++)
    {
        printf("Square of %d is %d\n", i + 1, results[i]);
    }

    return 0;
}