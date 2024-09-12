#include <stdio.h>

int main() {
    int number[2];
    int result=0;;

    printf("숫자 두 개를 입력하세요\n");
    scanf_s("%d", &number[0]);
    scanf_s("%d", &number[1]);
    for(int i=number[0];i<=number[1];i++) {
        result = result+i;
    }
    printf("%d", result);
}