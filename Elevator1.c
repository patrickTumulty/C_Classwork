#include <stdio.h>

void assessInput(int num, int totalFloors);
void ascend(int num);

int main(){
    int floorNumber = 50;
    int floorInput = 0;
    printf("What floor would you like to visit? : ");
    scanf("%d", &floorInput);
    assessInput(floorInput, floorNumber);
    return 0;
}

void assessInput(int num, int totalFloors){
    if (num == 0){
        printf("Ground Floor.");
    }
    else if (num > 0 && num < totalFloors){
        ascend(num);
    }
    else if (num == totalFloors){
        ascend(num);
    }
    else if (num < 0 || num > totalFloors){
        printf("Out of bounds.");
    }
    printf("\n");
}

void ascend(int num){
    for (int i = 0; i < num; i ++){
        if (i == 0){
            printf("Ground Floor\n");
        }
        else{
            printf("Floor %d\n", i);
        }
        
    }
    printf("** Floor %d **\n", num);
}