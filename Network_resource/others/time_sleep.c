#include <stdio.h>
#include <time.h>
#include <unistd.h>
/*
int main()
{
    time_t start, end;
    start = time(NULL);
    sleep(1);
    end = time(NULL);
    printf("TIME elapse: %ld\n", (end - start));
}
*/

int main(int argc, char *argv[])
{
    int i;
    uint64_t start, end, tmp, avg = 0;
    struct timespec ts;
    //convert to nanosecond
    for (i = 0; i < 1000; i++)
    {
        tmp = 0;
        timespec_get(&ts, TIME_UTC);
        start = ts.tv_sec * (uint64_t)1000000000 + ts.tv_nsec;
        sleep(1);
        timespec_get(&ts, TIME_UTC);
        end = ts.tv_sec * (uint64_t)1000000000 + ts.tv_nsec;
        tmp = (end - start);
        printf("%lld\n", tmp);
        avg += tmp;
    }
    avg /= 1000;
    printf("avg: %lld\n", avg);
}