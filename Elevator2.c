#include <stdio.h>

void ascend(int *selectedFloors, int totalFloors);

int main(){
    int totalFloors = 50;
    int selectedFloors[11];
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
        printf("\nWould you like to enter another floor?\nEnter 1 for yes. Enter 0 for no.\n");
        scanf("%d", &UIP);
        if (UIP == 0){
            fauxBool = 0;
            selectedFloors[counter] = -1; // special use case that indicate the end of the array
        }
        if (counter == 9){
            printf("\nYou've Reached the Max Number of Selected Floors.\n");
            selectedFloors[counter] = -1;
            fauxBool = 0;
        }
    }

    ascend(selectedFloors, totalFloors);
    
    return 1;
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