/* char 2.2 of pratice 1 (a)(b) */
#include <stdio.h>

int main(int argc, char *argv[])
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int *ptr = a;
    //ptr is a LVALUE and it point to a memeory address
    printf("ptr+2: %p \n", ptr+2);
    // *(ptr+2) and a[2] is the same things
    printf("*(ptr+2): %d \n", *(ptr+2));
    printf("a[2]: %d \n", a[2]);
}