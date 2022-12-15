#include <stdio.h>

int main(void) {
    int a=0;
    printf("请输入一个数值，范围在0～127之间：");
    scanf("%d", &a);
    printf("您输入的数字对应的ASCII码字符是：%c。\n", a);

    return 0;
}