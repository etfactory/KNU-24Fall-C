#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {
    double x = 0; //x 좌표
    double y = 0; //y 좌표

    int count = 0, circle = 0;
    int maxCount = 1000000000;

    srand(time(NULL));

    while(count<maxCount) {
        x = (double)rand()/RAND_MAX;
        y = (double)rand()/RAND_MAX;

        if(sqrt(x*x+y*y)<=1) {
            circle++;
        }

        count++;

        if(count%(maxCount/100)==0) {
            printf("%d%%..\t PI: %.6f\t", count/(maxCount/100), (double)circle/count*4);
            for(int i = 0; i < count/(maxCount/20); i++) {
                printf("■");
            }
            for(int i = 20; i > count/(maxCount/20); i--) {
                printf("□");
            }
            printf("\n");
        }
    }
}