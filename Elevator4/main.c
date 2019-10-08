#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

void add_new_floor(Node * head, int floor);
void ascend_ll(Node * head);


int main(){
    int totalFloors = 50;
    Node * head = (Node *)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;

    int fauxBool = 1;
    int counter = 0;
    int UIP = 0;

    while (fauxBool == 1)
    {
        printf("\nWhat floor would you like to visit?\n");
        scanf("%d", &UIP);
        if (UIP <= totalFloors && UIP > 0)
        {
            add_new_floor(head, UIP);
            printf("\nFloor %d\n", UIP);
            counter++;
        }
        else if (UIP > totalFloors || UIP < 0)
        {
            printf("\nInvalid floor number\n");
        }        
        while(1)
        {
            printf("\nWould you like to enter another floor?\nEnter 1 for yes. Enter 0 for no.\n");
            scanf("%d", &UIP);
            if (UIP == 0)
            {
                fauxBool = 0;
                break;
            }
            else if (UIP == 1)
            {
                break;
            }
            else if (UIP != 0 || UIP != 1)
            {
                printf("\nInput not recognized.\n");
            }
        }
    }
    ascend_ll(head);
    return 0;
}


void add_new_floor(Node * head, int floor)
{
    append(&head, floor);
}

void ascend_ll(Node * head)
{
    int floorCounter = 0;
    while (head->next != NULL)
    {
        head = head->next;
        while(head->data != floorCounter)
        {
            if (floorCounter == 0)
            {
                printf("__Ground_Floor__ \n");
                floorCounter++;
            }
            else if (floorCounter < head->data)
            {
                printf("Floor %d \n", floorCounter);
                floorCounter++;
            }
            else if (floorCounter > head->data)
            {
                printf("Floor %d \n", floorCounter);
                floorCounter--;
            }
        }
        printf("------->");
    }
    while (floorCounter != 0)
    {
        floorCounter--;
        printf("Floor %d \n", floorCounter);
    }
    printf("Done! \n");
}