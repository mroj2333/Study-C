#include <stdio.h>

double cubed(double n);

int main(void) {
    double a = 0;
    printf("请输入一个浮点数： ");
    scanf("%lf", &a);

    double b = cubed(a);
    printf("%0.4lf cubed is %0.4lf\n", a, b);

    return 0;
}

double cubed(double n) { return n * n * n; }