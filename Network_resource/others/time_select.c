#include <stdio.h>
#include <time.h>
#include <unistd.h>

/* orig code for sleep once
int main(int argc, char *argv[])
{
    time_t start, end;
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    start = time(NULL);
    select(0, NULL, NULL, NULL, &timeout);
    end = time(NULL);
    printf("TIME elapse: %ld\n", (end - start));
}
*/
/*
struct timespec {
    time_t tv_sec;
    long   tv_nsec;
};
*/

int main(int argc, char *argv[])
{
    int i;
    uint64_t start, end, tmp, avg = 0;
    struct timespec ts;
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    // convert to nanosecond
    for (i = 0; i < 1000; i++)
    {
        tmp = 0;
        timespec_get(&ts, TIME_UTC);
        start = ts.tv_sec * (uint64_t)1000000000 + ts.tv_nsec;
        select(0, NULL, NULL, NULL, &timeout);
        timespec_get(&ts, TIME_UTC);
        end = ts.tv_sec * (uint64_t)1000000000 + ts.tv_nsec;
        tmp = (end - start);
        printf("%lld\n", tmp);
        avg += tmp;
        //printf("all: %lld\n", avg);
    }
    avg /= 1000;
    printf("avg: %lld\n", avg);
}