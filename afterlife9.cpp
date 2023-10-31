/*
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

int shared = 1; // Shared variable
sem_t semaphore; // Semaphore variable

void *thread1_function(void *arg);
void *thread2_function(void *arg);

int main() {
    // Initialize the semaphore
    sem_init(&semaphore, 0, 1);

    // Create two threads
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread1_function, NULL);
    pthread_create(&thread2, NULL, thread2_function, NULL);

    // Wait for the threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print the final value of the shared variable
    printf("Final value of shared is %d\n", shared);

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}

void *thread1_function(void *arg) {
    int localValue;
    sem_wait(&semaphore); // Wait for access to the shared resource

    localValue = shared; // Read the shared variable
    printf("Thread 1 reads the value as %d\n", localValue);

    localValue++; // Increment the local value
    printf("Thread 1 increments the local value to %d\n", localValue);

    sleep(1); // Simulate some work

    shared = localValue; // Update the shared variable
    printf("Value of shared variable updated by Thread 1 is %d\n", shared);

    sem_post(&semaphore); // Release access to the shared resource

    return NULL;
}

void *thread2_function(void *arg) {
    int localValue;
    sem_wait(&semaphore); // Wait for access to the shared resource

    localValue = shared; // Read the shared variable
    printf("Thread 2 reads the value as %d\n", localValue);

    localValue--; // Decrement the local value
    printf("Thread 2 decrements the local value to %d\n", localValue);

    sleep(1); // Simulate some work

    shared = localValue; // Update the shared variable
    printf("Value of shared variable updated by Thread 2 is %d\n", shared);

    sem_post(&semaphore); // Release access to the shared resource

    return NULL;
}
*/

/*
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

int shared = 1; // Shared variable
sem_t s;        // Semaphore variable

// Function declarations
void *fun1(void *arg);
void *fun2(void *arg);

int main() {
    sem_init(&s, 0, 1); // Initialize the semaphore

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared is %d\n", shared);

    sem_destroy(&s); // Destroy the semaphore
    return 0;
}

void *fun1(void *arg) {
    int x;
    sem_wait(&s);     // Wait operation on the semaphore
    x = shared;       // Thread1 reads the value of shared variable
    printf("Thread1 reads the value as %d\n", x);
    x++;              // Thread1 increments its value
    printf("Local update by Thread1: %d\n", x);
    sleep(1);          // Simulate some work
    shared = x;       // Thread1 updates the value of the shared variable
    printf("Value of shared variable updated by Thread1 is: %d\n", shared);
    sem_post(&s);     // Signal that the critical section is over
    return NULL;
}

void *fun2(void *arg) {
    int y;
    sem_wait(&s);     // Wait operation on the semaphore
    y = shared;       // Thread2 reads the value of shared variable
    printf("Thread2 reads the value as %d\n", y);
    y--;              // Thread2 decrements its value
    printf("Local update by Thread2: %d\n", y);
    sleep(1);          // Simulate some work
    shared = y;       // Thread2 updates the value of the shared variable
    printf("Value of shared variable updated by Thread2 is: %d\n", shared);
    sem_post(&s);     // Signal that the critical section is over
    return NULL;
}
*/