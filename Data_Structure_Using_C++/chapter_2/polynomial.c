/* Using to print the polynomial and store into array */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 20 
/*
void createArray(int exp, int coe)
{
    //int poly1[(2 * coe) + 1] = {};
    int i = 0;
    int poly2[exp + 2] = {};
    
    poly2[0] = exp;
    for (i = 0; i < exp; i ++)
    {
        scanf("%d", &poly2[i]);   
    }
    //printPoly( (2 * coe) + 1, poly1, exp);
    printPoly( exp + 2, poly2, exp);
}
*/


void printPoly(int power, int array[MAXSIZE])
{
    int i;
    printf("Given polynomial is: \n");
    for (i = 1; i <= power; i++)
    {
        /*
        if (power < 0)
        {
            break;
        }
        */
        /* display polynomial */
        /* print the coefficient if value is positive and skip the first one */
        if (array[i] >= 0 & i != 0)
            printf(" + ");
        /* print the coefficient if value is negative */
        else if (array[i] < 0)
            printf(" - ");
        /* first one */
        else
            printf(" ");
        // abs() is for remaining the pure number
        printf("%dx^%d ", abs(array[i]), power--);
    }
}

void printArray(int power, int array[MAXSIZE])
{
    int i;
    for (i = 0; i <= power; i++)
        printf("%d", array[i]);
}

int main(int argc, char **argv)
{
    /* allow to user interactive */
    int poly1[MAXSIZE];
    //int poly2[MAXSIZE];
    int i, n = 0, power = 0, cons = 0;
    
    printf("Enter the order of the polynomial\n");
    scanf("%d", & power);
    printf("Enter %d coefficients\n", power);
    // 1. p = {coefficients total number, exponent, coefficient, ...}
    // start from i = 1, i = 0 reserve for coefficients and constant
    for (i = 1; i <= power; i++)
    {
        scanf("%d", &poly1[i]);
        if (poly1[i] != 0)
        {
            n ++;
        }
    }
    poly1[0] = n;
    printf("Enter constant, if not type no\n");
    if (scanf("%d", &cons) == 1)
    {
        printf("Constant is: %d\n", cons);
        poly1[0] = power + 1;
    } else {
        printf("Constant not exist.\n");
        poly1[0] = power;
    }
    printPoly(power, poly1);
    printArray(power, poly1);
    // 2. p = {the biggest exponent, coefficient, coefficient, ...}
    
    return 0;
}