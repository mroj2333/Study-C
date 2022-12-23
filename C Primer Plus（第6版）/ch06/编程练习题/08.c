#include <stdio.h>

int main(void) {
    float a, b;
    printf("请输入两个浮点数，以空格分割回车结束：");
    int ret = scanf("%f %f", &a, &b);
    while (ret == 2) {
        printf("%.2f\n", (a - b) / (a * b));
        printf("请继续输入两个浮点数，或者输入非数字结束程序：");
        ret = scanf("%f %f", &a, &b);
    }

    return 0;
}