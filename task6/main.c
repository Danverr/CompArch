#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int a = 0;

void *mythread(void *dummy) {
    pthread_t mythid;
    mythid = pthread_self();

    a = a + 1;
    printf("Thread %u, Calculation result = %d\n", mythid, a);
    return NULL;
}

int main() {
    pthread_t thid1, thid2, mythid;

    // Thread 1
    int result1 = pthread_create(&thid1, (pthread_attr_t*)NULL, mythread, NULL);
    if (result1 != 0) {
        printf ("Error on thread create, return value = %d\n", result1);
        exit(-1);
    }
    printf("Thread created, thid1 = %u\n", thid1);

    // Thread 2
    int result2 = pthread_create(&thid2, (pthread_attr_t*)NULL, mythread, NULL);
    if (result2 != 0) {
        printf ("Error on thread create, return value = %d\n", result2);
        exit(-1);
    }
    printf("Thread created, thid2 = %u\n", thid2);

    // Current thread (self)
    mythid = pthread_self();
    a = a + 1;
    printf("Thread %u, Calculation result = %d\n", mythid, a);

    // Joining threads
    pthread_join(thid1, (void **)NULL);
    pthread_join(thid2, (void **)NULL);

    return 0;
}
