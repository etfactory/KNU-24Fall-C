#include <stdio.h>

int main() {
    int number;

    printf("몇층 피라미드?:");
    scanf_s("%d", &number);

    printf("%d층 피라미드\n", number);

    for(int i=0; i<number; i++) {
        for(int j=i; j<=number-1;j++) {
            printf(" ");
        }
        for(int k=0; k<=i*2; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}