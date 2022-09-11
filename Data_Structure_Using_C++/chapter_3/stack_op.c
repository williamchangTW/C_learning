/* stack operation: pop, push, print */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACK_SIZE 4

void stack_push()
{
    printf("This is PUSH\n");
    printf("Please enter a number to push:\n");
    
}

void stack_pop()
{
    printf("This is POP\n");
}

void stack_print()
{
    printf("This is PRINT\n");
}

void switch_op(int op)
{
    switch (op)
    {
        case 1:
            stack_push();
            break;
        case 2:
            stack_pop();
            break;
        case 3:
            stack_print();
            break;
        default:
            break;
    }
    return;
}

int main(int argc, char* argv[])
{
    int TOP = STACK_SIZE - 1;
    while (true)
    {
        int op, err_check = 0;
        printf("Choose your operation: \n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. print\n");
        if (scanf("%d", &op) == EOF)
        {
            getchar(); //discard if the input is not integer
            continue;
        }
        printf("Your choise is %d\n", op);
        if (op > 3)
            printf("Wrong operation!\n");
        else
            switch_op(op);
    }
}