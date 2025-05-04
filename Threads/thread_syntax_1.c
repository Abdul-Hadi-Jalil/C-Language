#include <pthread.h>
#include <stdio.h>

int a;
int b;
int result;

// Thread function definition
void *mul(void *arg)
{
    result = a * b;
    printf("Inside thread\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread_id;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    // Create a thread
    pthread_create(&thread_id, NULL, mul, NULL);

    // Wait for the thread to finish
    pthread_join(thread_id, NULL);

    printf("%d \n", result);

    return 0;
}
