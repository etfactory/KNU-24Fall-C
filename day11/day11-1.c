// 이차방정식의 근 계산

#include <stdio.h>
#include <math.h>

int quadraticEquation(double a, double b, double c, double* x1, double* x2) {
    double inSqrt = b*b-4*a*c;
    if (inSqrt < 0) {
        return 0;
    } else {
        *x1 = (-b+sqrt(inSqrt))/(2*a);
        *x2 = (-b-sqrt(inSqrt))/(2*a);
        return 2;
    }
}

int main() {
    double a, b, c;
    double x1, x2;
    printf("ax^2+bx+c에서 a, b, c의 값을 입력하세요:");
    scanf_s("%lf %lf %lf", &a, &b, &c);

    int result = quadraticEquation(a,b,c,&x1,&x2);

    if (result == 0) {
    } else if (x1 == x2) {
        printf("x = %.2lf \n", x1);
    } else {
        printf("x = %.2lf or %.2lf \n", x1, x2);
    }

    return 0;
}