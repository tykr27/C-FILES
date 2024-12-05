#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 10
#define MAX_CONCURRENT 3 // Maximum threads that can access the resource at the same time

sem_t counting_semaphore;

void *thread_function(void *arg) {
    int thread_id = *((int *)arg);
    
    // Wait (P operation)
    sem_wait(&counting_semaphore);
    
    printf("Thread %d: Entered critical section.\n", thread_id);
    sleep(1); // Simulate some work in the critical section
    printf("Thread %d: Exiting critical section.\n", thread_id);
    
    // Signal (V operation)
    sem_post(&counting_semaphore);
    
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    
    // Initialize the counting semaphore
    sem_init(&counting_semaphore, 0, MAX_CONCURRENT);
    
    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Destroy the semaphore
    sem_destroy(&counting_semaphore);
    
    return 0;
}

