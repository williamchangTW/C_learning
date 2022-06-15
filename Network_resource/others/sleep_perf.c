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


int sigwrap_select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout)
{
    while (1)
    {
        int Result = select(nfds, readfds, writefds, exceptfds, timeout);

        if (Result != -1)
            return Result;
    }
}

void select_sleep(time_t sec,suseconds_t usec)
{
    struct timeval tv;

    tv.tv_sec = sec;
    tv.tv_usec = usec;

    while(sigwrap_select(0, NULL, NULL, NULL, &tv) < 0);
}

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
    //return;
}

static void *SimuTimerTask(void *arg)
{
    UNUSED(arg);
    SimuLED();
    sleep(1);
    //return;
}

int main(int argc, char *argv[])
{
    int i;
    for (i = 0; i <= 10000; i++)
    {
        OS_CREATE_THREAD(SimuHealth, NULL, 0);
        OS_CREATE_THREAD(SimuTimerTask, NULL, 0);
        sleep(1);
    }
    return 0;
}