//run using gcc -o p3 p3.c -lpthread
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/sem.h>
#define PERMS 0660

int semId;
int initSem(int semId, int semNum, int initValue) 
{
    return semctl(semId, semNum, SETVAL, initValue);
}

int P(int semId, int semNum) 
{
    struct sembuf operationList[1];
    operationList[0].sem_num = semNum;
    operationList[0].sem_op = -1;
    operationList[0].sem_flg = 0;
    return semop(semId, operationList, 1);
}

int V(int semId, int semNum) 
{
    struct sembuf operationList[1];
    operationList[0].sem_num = semNum;
    operationList[0].sem_op = 1;
    operationList[0].sem_flg = 0;
    return semop(semId, operationList, 1);
}

void* funcA(void* nothing) 
{
    printf("Thread A try to lock 0...\n");
    P(semId, 0);
    printf("Thread A locked 0.\n");
    usleep(50*1000);
    printf("Thread A try to lock 1...\n");
    P(semId, 1);
    printf("Thread A locked 1.\n");
    V(semId, 0);
    V(semId, 1);
    return NULL;
}

void* funcB(void* nothing) 
{
    printf("Thread B try to lock 1...\n");
    P(semId, 1);
    printf("Thread B locked 1.\n");
    usleep(5*1000);
    printf("Thread B try to lock 0...\n");
    P(semId, 0);
    printf("Thread B locked 0.\n");
    V(semId, 0);
    V(semId, 1);
    return NULL;
}

int main(int argc, char* argv[]) 
{
    int i;
    semId = semget(ftok(argv[0], 'A'), 2, IPC_CREAT | PERMS);
    initSem(semId, 0, 1);
    initSem(semId, 1, 1);
    pthread_t thread[2];
    pthread_create(&thread[0], NULL, funcA, NULL);
    pthread_create(&thread[1], NULL, funcB, NULL);
    for (i = 0 ; i < 2 ; i++) 
    {
        pthread_join(thread[i], NULL);
    }
    printf("This is not printed in case of deadlock\n");
    semctl(semId, 0, IPC_RMID, 0);
    semctl(semId, 1, IPC_RMID, 0);
    return 0;
}