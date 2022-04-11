#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/sem.h>

int main() {
    int *array;
    int shmid;
    int new = 1;
    long i;

    char pathname[] = "09-2a.c";
    key_t key;

    int semid;
    struct sembuf mybuf;

    key = ftok(pathname, 0);
    if (key < 0) {
        printf("A: Can\'t generate key\n");
        exit(-1);
    }

    shmid = shmget(key, 3*sizeof(int), 0666|IPC_CREAT|IPC_EXCL);
    if (shmid < 0) {
        if (errno != EEXIST) {
            printf("A: Can\'t create shared memory\n");
            exit(-1);
        } else {
            shmid = shmget(key, 3*sizeof(int), 0);
            if (shmid < 0) {
                printf("A: can\'t find shared memory\n");
                exit(-1);
            }
            new = 0;
        }
    }

    array = (int *)shmat(shmid, NULL, 0);
    if (array == (int *)(-1)) {
        printf("A: Can\'t attach shared memory\n");
        exit(-1);
    }

    semid = semget(key, 1, 0666);
    if (semid < 0) {
        semid = semget(key, 1, 0666 | IPC_CREAT);
        if (semid < 0) {
            printf("A: Can\'t create semaphore set\n");
            exit(-1);
        }

        mybuf.sem_num = 0;
        mybuf.sem_op = 1;
        mybuf.sem_flg = 0;

        if (semop(semid, &mybuf, 1) < 0) {
            printf("A: Can\'t wait for condition\n");
            exit(-1);
        }
    }

    if (new) {
        array[0] = 1;
        array[1] = 0;
        array[2] = 1;

        printf("A: Program 1 was spawn %d times, program 2 - %d times, total - %d times\n",
                 array[0], array[1], array[2]);
    } else {
        mybuf.sem_num = 0;
        mybuf.sem_op = -1;
        mybuf.sem_flg = 0;

        if (semop(semid, &mybuf, 1) < 0) {
            printf("A: Can\'t wait for condition\n");
            exit(-1);
        }

        array[0] += 1;
        for(i = 0; i<2000000000L; i++);
        array[2] += 1;

        printf("A: Program 1 was spawn %d times, program 2 - %d times, total - %d times\n",
                 array[0], array[1], array[2]);

        mybuf.sem_num = 0;
        mybuf.sem_op = 1;
        mybuf.sem_flg = 0;

        if (semop(semid, &mybuf, 1) < 0) {
            printf("A: Can\'t wait for condition\n");
            exit(-1);
        }
    }

    if (shmdt(array) < 0) {
        printf("A: Can\'t detach shared memory\n");
        exit(-1);
    }

    return 0;
}