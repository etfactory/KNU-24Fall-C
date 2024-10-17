#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            array[i][j] = rand()%20+1;
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

//void형 포인터 왜 써야 하는지 진짜 모르겠는데요?
void movePointer(void* array){
    int* ptr = (int*)array;
    int nextIndex = 0;
    for(int i=0;i<SIZE*SIZE;i++){
        nextIndex = i + *(ptr+i) - 1;
        printf("현재 위치 : (%d, %d), 배열의 값 : %d\n", i/SIZE, i%SIZE, *(ptr+i));
        if(nextIndex >= SIZE*SIZE){
            printf("더 이상 이동할 수 없습니다.\n");
            printf("종료 위치 : (%d, %d), 배열의 값 : %d\n", i/SIZE, i%SIZE, *(ptr+i));
            break;
        }
        i = nextIndex;
    }
}

int main(){
    int array[SIZE][SIZE];

    fillRandom(array);
    printArray(array);
    movePointer(array);

    return 0;
}