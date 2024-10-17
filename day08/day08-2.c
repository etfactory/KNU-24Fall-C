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

//2차원 배열을 1차원 배열처럼 처리할 수 있기에 포인터 사용
void movePointer(void* array){
    int* pnt = array;
    int index = 0;
    int tmp = 0;
    for (int i = 0; i < SIZE * SIZE; i++) {
        // pnt와 배열의 시작 주소 사이의 차이
        index = pnt - (int*)array;
        // index / SIZE는 row 위치를, index % SIZE는 column의 위치를 나타내줌
        printf("현재 위치: (%d, %d), 배열의 값: %d\n", index / SIZE, index % SIZE, *pnt);
        // if문에 *pnt 그대로 쓰면 0으로 출력되어서 tmp에 저장
        tmp = *pnt;
        pnt += *pnt;
        // 이동할 수 없을 때를 체크
        if (pnt >= (int*)array + SIZE * SIZE) {
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