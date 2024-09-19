#include <stdio.h>

/*
 * 소수인지 아닌지 판별하는 함수
 * 소수이면 1을 반환하고, 아니면 0을 반환한다.
 *
 * 소수: 1과 자기 자신만으로 나누어 떨어지는 수
 *      양의 약수가 두 개인 수
 * -> 숫자가 1 이하 => 소수가 아님
 * -> 2부터 n/2까지 나누어 떨어지는 수가 있다 => 소수가 아님
 */

int checkPrimeNumber(int inputNumber);

void main() {
    int inputNumber;
    printf("소수인지 확인할 수를 입력하세요: ");
    scanf_s("%d", &inputNumber);
    if(checkPrimeNumber(inputNumber) == 1) {
        printf("해당 수는 소수입니다.");
    } else {
        printf("해당 수는 소수가 아닙니다.");
    }
}

int checkPrimeNumber(int inputNumber) {
    if (inputNumber <= 1) {
        return 0;
    } //1은 소수가 아닙니다.
    for (int i = 2; i <= inputNumber / 2; i++) {
        if (inputNumber % i == 0) {
            return 0;
        }
    } //inputNumber / 2로 지정한 이유는 2로 나눠진다면 소수가 아니기 때문.
    return 1;
}