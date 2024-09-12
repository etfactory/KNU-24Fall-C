#include <stdio.h>

int main() {
    int i=0;

    while(i<=100) {
        if((i%3==0&&i%4==0) != (i%7==0)) {
            printf("%d\t",i);
        }
        i++;
    }
}