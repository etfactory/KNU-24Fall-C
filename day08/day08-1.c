#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {
    char *inputString = (char *)malloc(sizeof(char));
    //포인터 p와 q 문자열 시작위치로
    char *p = inputString;
    char *q = inputString;
    char temp;

    printf("문자열을 입력하세요:");
    gets(inputString);

    //p포인터를 문자열 끝으로
    while(*p) {
        p++;
    }
    p--;

    //문자열 뒤집기
    while (q<p) {
        //q포인터가 알파벳이 아닌 경우 q포인터를 증가시킴
        while(q<p&&!isalpha(*q)) {
            q++;
        }
        //p포인터가 알파벳이 아닌 경우 p포인터를 감소시킴
        while(q<p&&!isalpha(*p)) {
            p--;
        }

        //q포인터가 p포인터보다 작은 경우 두 포인터가 가리키는 문자를 교환
        if(q<p) {
            temp = *q;
            *q = *p;
            *p = temp;
            q++;
            p--;
        }
    }

    printf("뒤집어진 문자열:%s\n", inputString);

    free(inputString);

    return 0;
}
