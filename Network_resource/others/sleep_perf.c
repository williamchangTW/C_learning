#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    while (1)
    {
        printf("test message\n");
        sleep(10);
    }
    return 0;
}