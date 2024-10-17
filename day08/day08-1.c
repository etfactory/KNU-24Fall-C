#include <stdio.h>
#include <stdlib.h>

int main() {
    char *inputString = (char *)malloc(sizeof(char));
    //포인터 p와 q 문자열 시작위치로
    char *p = inputString;
    char *q = inputString;
    char temp;

    printf("문자열을 입력하세요:");
    scanf_s("%s", inputString);

    //p포인터를 문자열 끝으로
    while(*p) {
        p++;
    }
    p--;

    //문자열 뒤집기
    while (q<p) {
        temp = *q;
        *q = *p;
        *p = temp;
        q++;
        p--;
    }

    printf("뒤집어진 문자열:%s\n", inputString);

    free(inputString);

    return 0;
}
