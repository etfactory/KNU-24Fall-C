//구분구적법
//함수 f(x)가 주어졌을 때 구간 [a,b]에서 f(x)의 면적을 구하는 방법
//구간 [a,b]를 n개의 구간으로 나누고 각 구간의 넓이를 구하여 더함
//이 때 n을 늘릴 수록 실제 넓이로 수렴
//n을 두 배씩 늘리면서 적분값을 확인
//f(x)=-log10(1/x)+sin(x)일 때 [10,30]에서의 적분값을 구하시오
//F(x)=log10(x)-cos(x), F(b)-F(a)
#include <stdio.h>
#include <math.h>

double f(double x) {
    return -log10(1/x)+sin(x);
    //return x*x+1;
}

double integral(int a, int b, int n) {
    double result = 0;
    double dx = (double)(b - a) / n;
    for (int i = 0; i < n; i++) {
        double x = a + i * dx;
        result += f(x) * dx;
    }
    return result;
}

int main() {
    int a, b, max;
    int n = 1;
    double result = 0;

    printf("적분할 시작 값을 입력하세요:");
    scanf_s("%d",&a);
    printf("적분할 끝 값을 입력하세요:");
    scanf_s("%d",&b);
    printf("시행할 최대 구간을 입력하세요(2^n):");
    scanf_s("%d",&max);

    int i = 0;
    while(1) {
        if (i==max) {
            break;
        }
        n *= 2;
        result = integral(a,b,n);
        printf("구간%12d 적분값 : %.6lf\n", n, result);
        i++;
    }
    return 0;
}