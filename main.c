#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *firstThread(void *vargp)
{
    printf("First!\n");
    pthread_exit(NULL);
    return NULL;
}

void *secondThread(void *vargp)
{
    printf("Second!\n");
    pthread_exit(NULL);
    return NULL;
}

void *mainThread(void *vargp)
{
    pthread_t tid1;
    pthread_create(&tid1, NULL, firstThread, NULL);
    pthread_join(tid1, NULL);

    pthread_t tid2;
    pthread_create(&tid2, NULL, secondThread, NULL);
    pthread_join(tid2, NULL);

    printf("Main!\n");
    return NULL;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, mainThread, NULL);
    pthread_exit(NULL);
    return 0;
}
