#include <stdio.h>

int main(void) {
    printf("请输入水的夸脱数：");
    double a = 0;
    double b = 0;
    scanf("%lf", &a);
    b = a * 950 / 1.0e-23;
    printf("%.2lf夸脱水大约有%.2e个水分子。\n", a, b);

    return 0;
}