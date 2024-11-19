#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

pthread_mutex_t mutex; // Mutex for reader count update
pthread_mutex_t wrt;   // Mutex for writer's access to shared data
int rc = 0;            // Reader count
int data = 0;          // Shared data

void *writer(void *wno) {
    while (1) {
        // Writer tries to write
        pthread_mutex_lock(&wrt);  // Only one writer can write at a time

        // Writing section
        data++;
        printf("Writer %d modified data to %d\n", (*((int *)wno)), data);

        // Writer done writing
        pthread_mutex_unlock(&wrt);  // Release the lock so others can access
        
        sleep(1); // Simulating writer's time
    }
}

void *reader(void *rno) {
    while (1) {
        // Reader tries to read
        pthread_mutex_lock(&mutex);  // Lock the reader count update
        rc++;
        if (rc == 1) {               // If it's the first reader
            pthread_mutex_lock(&wrt); // Block the writer
        }
        pthread_mutex_unlock(&mutex);  // Unlock the reader count update

        // Reading section
        printf("Reader %d: read data as %d\n", *((int *)rno), data);

        // Reader done reading
        pthread_mutex_lock(&mutex);  // Lock the reader count update
        rc--;
        if (rc == 0) {               // If it's the last reader
            pthread_mutex_unlock(&wrt); // Allow writers
        }
        pthread_mutex_unlock(&mutex);  // Unlock the reader count update
        
        sleep(1); // Simulating reader's time
    }
}

int main() {
    pthread_t read[3], write[3];
    pthread_mutex_init(&mutex, NULL);  // Initialize the reader count mutex
    pthread_mutex_init(&wrt, NULL);    // Initialize the writer mutex

    int a[3] = {1, 2, 3};  // Reader and writer IDs

    // Creating reader threads
    for (int i = 0; i < 3; i++) {
        pthread_create(&read[i], NULL, reader, (void *)&a[i]);
    }

    // Creating writer threads
    for (int i = 0; i < 3; i++) {
        pthread_create(&write[i], NULL, writer, (void *)&a[i]);
    }

    // Waiting for all threads to finish (infinite in this case)
    for (int i = 0; i < 3; i++) {
        pthread_join(read[i], NULL);
        pthread_join(write[i], NULL);
    }

    pthread_mutex_destroy(&mutex);  // Destroy the mutex
    pthread_mutex_destroy(&wrt);    // Destroy the writer mutex

    return 0;
}


//output:

// Reader 1: read data as 0
// Reader 3: read data as 0
// Writer 2 modified data to 1
// Writer 1 modified data to 2
// Writer 3 modified data to 3
// Reader 2: read data as 3
// Reader 3: read data as 3
// Reader 1: read data as 3
// Writer 2 modified data to 4
// Writer 1 modified data to 5
