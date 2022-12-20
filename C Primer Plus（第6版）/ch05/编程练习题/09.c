#include <stdio.h>

void Temperatures(double f);

int main(void) {
    printf("请输入一个华氏温度值： ");
    double f;
    int ret = scanf("%lf", &f);

    while (ret == 1) {
        Temperatures(f);
        printf("请继续输入华氏温度或者其他非数字字符结束。\n");
        ret = scanf("%lf", &f);
    }

    return 0;
}

void Temperatures(double f) {
    const double a = 5.0;
    const double b = 9.0;
    const double c = 32.0;
    const double d = 273.16;

    double cc = a / b * (f - c);
    double k = cc + d;

    printf("华氏温度%0.2lf转换成摄氏温度为%0.2lf，转换成开氏温度为%0.2lf。\n",
           f,
           cc,
           k);
}