#include <stdio.h>

int factorial(int inputNumber);

void main() {
    int inputNumber;
    printf("계산할 팩토리얼 값 입력 : ");
    scanf_s("%d", &inputNumber);

    printf("%d! = %d", inputNumber, factorial(inputNumber));
}
int factorial(int inputNumber) {
    if( inputNumber==1 || inputNumber ==0 ) {
        return 1;
    }
    return inputNumber*factorial(inputNumber-1);
}
