#include <stdio.h>

int main() {
  printf("원하는 기능을 입력하시오.\n");
  printf("1.더하기 2.빼기 3.곱하기 4.나누기\n");
  printf("기능: ");
  int input=0;
  double inputNum1;
  double inputNum2;

  scanf("%d", &input);
  printf("숫자 1을 입력하세요 : ");
  scanf("%lf", &inputNum1);
  printf("숫자 2를 입력하세요 : ");
  scanf("%lf", &inputNum2);

  double result = 0.0;
  switch (input) {
    case 1:
      result = inputNum1+inputNum2;
      printf("%lf + %lf = %lf\n", inputNum1, inputNum2, result);
      break;
    case 2:
      result = inputNum1-inputNum2;
      printf("%lf - %lf = %lf\n", inputNum1, inputNum2, result);
      break;
    case 3:
      result = inputNum1*inputNum2;
      printf("%lf * %lf = %lf\n", inputNum1, inputNum2, result);
      break;
    case 4:
      result = inputNum1/inputNum2;
      printf("%lf / %lf = %lf\n", inputNum1, inputNum2, result);
      break;
    default: return 0;
  }
}