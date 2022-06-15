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
    printf("Turn On LED\n");
    sleep(1);
    printf("Turn off LED\n");
    return;
}

static void *SimuHealth(void *arg)
{
    UNUSED(arg);
    SimuLED();
    sleep(1);
    return NULL;
}

static void *SimuTimerTask(void *arg)
{
    UNUSED(arg);
    SimuLED();
    sleep(1);
    return NULL;
}

int main(int argc, char *argv[])
{
    int i;
    uint64_t start, end, tmp, avg = 0;
    struct timespec ts;
    for (i = 0; i <= 1000; i++)
    {
        tmp = 0;
        timespec_get(&ts, TIME_UTC);
        start = ts.tv_sec * (uint64_t)1000000000 + ts.tv_nsec;
        OS_CREATE_THREAD(SimuHealth, NULL, 0);
        OS_CREATE_THREAD(SimuTimerTask, NULL, 0);
        sleep(1);
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