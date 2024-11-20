//구분구적법
//함수 f(x)가 주어졌을 때 구간 [a,b]에서 f(x)의 면적을 구하는 방법
//구간 [a,b]를 n개의 구간으로 나누고 각 구간의 넓이를 구하여 더함
//이 때 n을 늘릴 수록 실제 넓이로 수렴
//n을 두 배씩 늘리면서 적분값을 확인
//f(x)=-log10(1/x)+sin(x)일 때 [10,30]에서의 적분값을 구하시오
#include <stdio.h>
#include <math.h>

double f(double x) {
    return -log10(1/x)+sin(x);
}

double integral(double a, double b, int n) {
    double dx = (b-a)/n;
    double sum = 0;
    for (int i=0; i<n; i++) {
        sum += f(a+i*dx)*dx;
    }
    return sum;
}

int main() {
    double a = 10;
    double b = 30;
    int n = 1;
    int i = 0;
    double result = integral(a,b,n);
    while(1) {
        if (i==30) {
            break;
        }
        n *= 2;
        result = integral(a,b,n);
        printf("구간\t%d\t 적분값:%.4lf\n", n, result);
        i++;
    }
    return 0;
}