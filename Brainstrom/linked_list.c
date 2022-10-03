/**
 * @file linked_list.c
 * @author William Chang(william80121@hotmail.com.tw)
 * @brief designed the linked list as a software tool by myself.
 * @version 0.1
 * @date 2022-09-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

/* add a flag to detect the user press Ctrl + C */
static volatile int runningFlag = 1;

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* check the head of linked list has element */
int checkEmpty(void)
{
    if (head == NULL)
        return 1;
    return 0;
}

/* counting number */
int countLList(void)
{
    int count = 0;
    struct Node *temp = head;
    while ((*temp).next !
}


void insertQueue(int index, int data)
{
    /* create a empty node to contain the new element */
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    (*temp).data = data;
    (*temp).next = head;
    head = temp;
    return;
}

void deleteQueue()
{
    while (head != NULL)
    {
        /* create a temp space to free node safely */
        struct Node *free_node = NULL;
        free_node = (*head).next; /* store the memory address to temp node */
        free(head); /* free the memory space */
        head = free_node; /* store the memory address back to head pointer */
    }
    return;
}

void deleteByIndex(int index)
{
    if (checkEmpty())
    {
        printf("Linked list is empty\n");
        return;
    }
    /* assume the first element is not NULL */
    while (((*(*head).next).next != NULL) && )
    {
        struct Node *temp_node = NULL;
        (*temp_node).next = (*(*head).next).next;
        free((*head).next);
        (*head).next = (*temp_node).next;
    }
    return;
}

/* insert the element to linked list by index */
void insertByIndex(int index, int data)
{
    int i = 0;
    /* check index is match */
    struct Node *current = head;
    if (checkEmpty())
        return;
    for (i = 0; i < index; i++)
    {
        if ((*current).next != NULL)
            current = (*current).next;        
    }
    (*current).data = data;
    return;
}

/* print all the elements from linked list */
void printLinkedList(void)
{
    
    while (head != NULL)
    {
        /* print everything that include in linked list */
        printf("**************** *****************\n");
        printf("The index is %d\n", (*head).index);
        printf("The data is %d\n", (*head).data);
        head = (*head).next;
    }
    return;
}

void printHelp(void)
{
    printf("Usage: \n");
    printf("-i: insert the element to linked list.\n    -i {index_num} to insert element by index if it hase(from 1 ~ n, n = total number)\n");
    printf("-r: replace the element by index\n    -r {index_num} to replace\n");
    printf("-d: delete the element from linked list.\n   -d {index_num} to delete slement by index(from 1 ~ n, n = total number)\n");
    printf("-n: print the total number of linked list number\n");
    printf("-l: print the linked list\n");
    printf("-h: print help\n");
    return;
}

void interruptCatcher(int dummy)
{
    runningFlag = 0;
}

int main(int argc, char** argv)
{
    printf("Hello World\n");

    /* interrupt handler */
    signal(SIGINT, interruptCatcher);
    
    insertQueue(1, 10);
    insertQueue(2, 30);
    insertQueue(3, 29);
    insertQueue(4, 28);
    insertQueue(5, 27);
    printLinkedList();
    /*
    while (runningFlag)
    {
        if (argv != NULL)
            switch (**argv)
            {
                case '-i':
                    insertQeue();
                    break;
                case '-i':
                    insertByIndex(**argv);
                    break;
                case '-d':
                    deleteQueue();
                    break;
                case '-l':
                    printLinkedList();
                default:
                    printf("Unknown command: %s\n", *argv);
                    break;
            }
        else
            printf("Need to input the command\n");

    }
    */
    return 0;
}