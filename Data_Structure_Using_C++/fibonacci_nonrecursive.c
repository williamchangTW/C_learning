/* Using non-recursive to present fibonacci */
#include <stdio.h>

int Fibonacci(int n)
{
    // get the privious two result
    int prev1, prev2;
    // a number to count
    int i, temp;
    
    if (n == 0)
        return n;
    if (n == 1)
        return n;
    prev1 = 0;
    prev2 = 1;
    for (i = 0; i < n - 1; i++)
    {
        temp = prev2 + prev1;
        prev1 = prev2;
        prev2 = temp;
    }
    return temp;
}

int main(int argc, char * argv[])
{
    while (1)
    {
        int key, res;
        printf("please type a number to fibonacci\n");
        scanf("%d", &key);
        printf("This is your input: %d\n", key);
        res = Fibonacci(key);
        printf("%d\n", res);
    }
    return 0;
}