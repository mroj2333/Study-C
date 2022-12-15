#include <stdio.h>

int main(void) {
    // 整数上溢
    int a = 2147483647;
    printf("int 类型的最大取值为：%d，如果我把它加上1它将变为%d\n", a, a + 1);

    // 浮点数上溢
    float b = 3.4e38;
    printf(
        "float 类型的最大取值为：%e，如果我把它乘上10它将变为%e\n", b, b * 10);

    // 浮点数下溢
    float c = -3.4e38;
    printf(
        "float 类型的最小取值为：%e，如果我把它乘上10它将变为%e\n", c, c * 10);

    return 0;
}