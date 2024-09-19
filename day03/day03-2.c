#include <stdio.h>

int factorial(int inputNumber);

void main() {
    int inputNumber; int result=0;
    printf("계산할 팩토리얼 값 입력 : ");
    scanf_s("%d", &inputNumber);

    printf("%d! = %d", inputNumber, factorial(inputNumber));
}
int factorial(int inputNumber) {
    if(inputNumber==1) {
        return 1;
    } else {
        return inputNumber*factorial(inputNumber-1);
    }
}