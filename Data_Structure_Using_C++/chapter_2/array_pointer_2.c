/* chap 2.2 of pratice 2 */
#include <stdio.h>
// A[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}

int main (int argc, char *argv[])
{
    int A[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int x, k; // x is the element what we wanted
    printf("%d \n", (1/2));
    while (1)
    {
        int flag = 0; // reset flag
        int i = 0;
        int j = 10; // array A has 10 elemnts
        printf("Pleas enter key: \n");
        // error check
        if (scanf("%d", &x) != 1)
        {
            printf("Invalid Input \n");
            flag = 1;
            break;
        }
        do
        {
            k = (i + j) / 2;
            if (A[k] == x)
            {
                printf("No. %d \n", k);
                printf("Content: %d \n", A[k]);
                flag = 1;
                break;
            }
            else if (A[k] < x)
                i = k + 1; // shift right by 1
            else if (A[k] > x)
                j = k - 1; // shift left by 1
        } while (i <= j && flag != 1); // if i > j means the array can not found this element
        if (flag == 0)
            printf("The key %d not found! \n", x);
    }
}