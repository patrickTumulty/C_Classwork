#include <stdio.h>
#include <stdlib.h>

void ascend(int *selectedFloors, int totalFloors);
void quicksort(int number[11],int first,int last);
int getArrayLength(int * array);

int main(){
    int totalFloors = 50;
    int* selectedFloors = (int*)malloc(sizeof(int) * 11); // allocate memory to heap
    int fauxBool = 1;
    int counter = 0;
    int UIP = 0;

    while (fauxBool == 1){
        printf("\nWhat floor would you like to visit?\n");
        scanf("%d", &UIP);
        if (UIP <= totalFloors && UIP > 0){
            selectedFloors[counter] = UIP;
            printf("\nFloor %d\n", UIP);
            counter++;
        }
        else if (UIP > totalFloors || UIP < 0){
            printf("\nUnvalid floor number\n");
        }        
        while(1){
            printf("\nWould you like to enter another floor?\nEnter 1 for yes. Enter 0 for no.\n");
            scanf("%d", &UIP);
            if (UIP == 0){
                fauxBool = 0;
                selectedFloors[counter] = -1; // special use case that indicate the end of the array
                break;
            }
            else if (UIP == 1){
                break;
            }
            else if (UIP != 0 || UIP != 1){
                printf("\nInput not recognized.\n");
            }
        }
        if (counter == 9){
            printf("\nYou've Reached the Max Number of Selected Floors.\n");
            selectedFloors[counter] = -1;
            fauxBool = 0;
        }
    }
    int len = getArrayLength(selectedFloors); // get length of the array 
    quicksort(selectedFloors, 0, len - 1); // sort floors selected
    ascend(selectedFloors, totalFloors);  
    return 0;
}

void ascend(int *selectedFloors, int totalFloors){
    int fauxBool = 1;
    int floorCounter = 0;
    int sfc = 0;
    while (fauxBool == 1){
        if (selectedFloors[sfc] > floorCounter && selectedFloors[sfc] <= totalFloors && selectedFloors[sfc] >= 1){
            floorCounter++;
            if (selectedFloors[sfc] != floorCounter){
                printf("Floor %d\n", floorCounter);
            }
        }
        else if (selectedFloors[sfc] < floorCounter && selectedFloors[sfc] <= totalFloors && selectedFloors[sfc] >= 1){
            floorCounter--;
            if (selectedFloors[sfc] != floorCounter){
                printf("Floor %d\n", floorCounter);
            } 
        }
        else if (selectedFloors[sfc] == floorCounter){
            printf("*** You've Reached Floor %d ***\n", floorCounter);
            sfc++;
        }
        else if (selectedFloors[sfc] == -1){
            if (floorCounter == 1){
                printf("__Ground Floor__\n");
                fauxBool = 0;
            }
            else if (floorCounter != 1){
                printf("Floor %d\n", floorCounter);
            }
            floorCounter--; 
        }
    }
}

void quicksort(int number[11],int first,int last){
    // this code was found online at https://beginnersbook.com/2015/02/quicksort-program-in-c/
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
}

int getArrayLength(int * array){
    int i = 0;
    while(1){
        if (array[i] != -1){
            i++;
        }
        else if (array[i] == -1){
            break;
        }
    }
    return i;
}