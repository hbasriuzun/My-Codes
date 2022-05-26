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

    return 0;
}
