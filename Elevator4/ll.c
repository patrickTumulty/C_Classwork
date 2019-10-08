#include "ll.h"
#include <stdio.h>
#include <stdlib.h>

void append(Node ** head, int data)
{
    Node * new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    Node * last = *head;

    if (last == NULL)
    {
        *head = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void print(Node * head)
{
    while (head->next != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

void reverse(Node ** head)
{
    Node *prev = NULL;
    Node *curr = *head;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = *head;
        prev = curr;
        curr = next;
    }
    *head = prev;
}