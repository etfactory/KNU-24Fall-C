#include <stdio.h>

int main() {
  printf("���ϴ� ����� �Է��Ͻÿ�.\n");
  printf("1.���ϱ� 2.���� 3.���ϱ� 4.������\n");
  printf("���: ");
  int input=0;
  double inputNum1;
  double inputNum2;

  scanf("%d", &input);
  printf("���� 1�� �Է��ϼ��� : ");
  scanf("%lf", &inputNum1);
  printf("���� 2�� �Է��ϼ��� : ");
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