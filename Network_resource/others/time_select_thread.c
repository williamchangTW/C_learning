#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#define UNUSED(x) (void)(x)

#define OS_CREATE_THREAD(Thread, Arg, pErr)                     \
do                                                              \
{                                                               \
    pthread_t   thread_id;                                      \
    pthread_attr_t  threadAttr;                                 \
    pthread_attr_init( &threadAttr );                           \
    pthread_attr_setdetachstate( &threadAttr, PTHREAD_CREATE_DETACHED );\
    if (0 != pthread_create (&thread_id, &threadAttr, Thread, Arg))    \
    {                                                           \
        printf("Error creating thread\n");                     \
    }                                                           \
    pthread_attr_destroy(&threadAttr);          \
} while (0)

void SimuLED()
{
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    printf("Turn On LED\n");
    select(0, NULL, NULL, NULL, &timeout);
    printf("Turn off LED\n");
    return;
}

static void *SimuHealth(void *arg)
{
    UNUSED(arg);
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    SimuLED();
    select(0, NULL, NULL, NULL, &timeout);
    return NULL;
}

static void *SimuTimerTask(void *arg)
{
    UNUSED(arg);
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    SimuLED();
    select(0, NULL, NULL, NULL, &timeout);
    return NULL;
}

int main(int argc, char *argv[])
{
    int i;
    uint64_t start, end, tmp, avg = 0;
    struct timespec ts;
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    for (i = 0; i <= 1000; i++)
    {
        tmp = 0;
        timespec_get(&ts, TIME_UTC);
        start = ts.tv_sec * (uint64_t)1000000000 + ts.tv_nsec;
        OS_CREATE_THREAD(SimuHealth, NULL, 0);
        OS_CREATE_THREAD(SimuTimerTask, NULL, 0);
        select(0, NULL, NULL, NULL, &timeout);
        timespec_get(&ts, TIME_UTC);
        end = ts.tv_sec * (uint64_t)1000000000 + ts.tv_nsec;
        tmp = (end - start);
        printf("%lld\n", tmp);
        avg += tmp;
    }
    avg /= 1000;
    printf("avg: %lld\n", avg);
    return 0;
}