#include <stdio.h>

float func(float a, float b);

int main(void) {
    float a, b;
    printf("请输入两个浮点数，以空格分割回车结束：");
    int ret = scanf("%f %f", &a, &b);
    while (ret == 2) {
        printf("%.2f\n", func(a, b));
        printf("请继续输入两个浮点数，或者输入非数字结束程序：");
        ret = scanf("%f %f", &a, &b);
    }

    return 0;
}

float func(float a, float b) {
    float ret = (a - b) / (a * b);
    return ret;
}