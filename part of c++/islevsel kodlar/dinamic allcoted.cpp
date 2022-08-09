#include <iostream>
#include <stdlib.h>
#include <new>

typedef struct node
{
    int number;
    struct node *next;
}node;


int main(int argc, char const *argv[])
{
    int* n = new node[1];
    int* p = (int*)malloc(sizeof(node));
    if (p != NULL)
    {
        free(p);
        return 1;
    }
    

    return 0;
}
