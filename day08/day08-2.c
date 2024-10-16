#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            array[i][j] = rand()%20;
        }
    }
}

void printArray(int array[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
}

void movePointer(void* array){
    int* p = array;
    int index = 0;
    int tmp = 0;
    for (int i = 0; i < SIZE * SIZE; i++) {
        index = p - (int*)array;
        printf("현재 위치: (%d, %d), 배열의 값: %d\n", index / SIZE, index % SIZE, *p);
        tmp = *p;
        p += *p;
        if (p >= (int*)array + SIZE * SIZE) {
            printf("더 이상 이동할 수 없습니다.\n");
            printf("종료 위치: (%d, %d), 배열의 값: %d", index / SIZE, index % SIZE, tmp);
            break;
        }
    }
}

int main(){
    int array[SIZE][SIZE];
    fillRandom(array);
    printArray(array);
    movePointer(array);
    return 0;
}