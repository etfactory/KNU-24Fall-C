#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {
    double x = 0; //x 좌표
    double y = 0; //y 좌표

    int count = 0, circle = 0;
    //1,000,000,000번 수행
    int maxCount = 1000000000;

    srand(time(NULL));

    int percent = 0;
    double pi = 0;

    while(count<maxCount) {
        x = (double)rand()/RAND_MAX;
        y = (double)rand()/RAND_MAX;

        if(sqrt(x*x+y*y)<=1) {    //원 내부에 있는지 확인 (원의 방정식) x^2 + y^2 = r^2
            circle++;               //원 내부에 있으면 circle 변수 증가
        }

        count++;

        percent = count / (maxCount / 100);
        pi = (double)circle/count*4;

        if(count%(maxCount/100)==0) {   //1%마다 출력
            //고정폭 맞추고 싶어서 10%미만일 때 0추가
            if (percent<10)
                printf("0%d%%..\t PI: %.6f\t", percent, pi);
            else printf("%d%%..\t PI: %.6f\t", percent, pi);
            //5%마다 그래프 수정
            for(int i = 0; i < count/(maxCount/20); i++)
                printf("■");
            for(int i = 20; i > count/(maxCount/20); i--)
                printf("□");
            printf("\n");
        }
    }

    return 0;
}