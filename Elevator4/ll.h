#ifndef LL_H
#define LL_H

typedef struct node 
{
    int data;
    struct node * next;
} Node;

void append(Node **, int);
void print(Node *);
void reverse(Node **);

#endif