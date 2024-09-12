#include <stdio.h>

int main() {
    int number = 5;

    for(int i=0; i<number; i++) {
        for(int j=i; j<=number-1;j++) {
            printf(" ");
        }
        for(int k=0; k<=(i*2); k++) {
            printf("*");
        }
        printf("\n");
    }
}