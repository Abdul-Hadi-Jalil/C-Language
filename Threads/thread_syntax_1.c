#include <pthread.h>
#include <stdio.h>

// Thread function prototype
void *thread_function(void *arg);

int main()
{
    pthread_t thread_id;

    // Create a thread
    pthread_create(&thread_id, NULL, thread_function, NULL);

    // Wait for the thread to finish
    pthread_join(thread_id, NULL);

    return 0;
}

// Thread function definition
void *thread_function(void *arg)
{
    printf("Inside thread\n");
    pthread_exit(NULL);
}