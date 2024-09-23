#include <stdio.h>

void swap(int* firstNum, int* secondNum) {
    int temp = *firstNum;
    *firstNum = *secondNum;
    *secondNum = temp;
}

void main() {
    int firstNum = 100, secondNum = 200;
    printf("Before // firstNum : %d, secondNum : %d\n", firstNum, secondNum);
    swap(&firstNum, &secondNum);
    printf("After // firstNum : %d, secondNum : %d\n", firstNum, secondNum);
}