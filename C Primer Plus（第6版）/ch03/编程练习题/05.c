#include <stdio.h>

int main(void) {
    int age = 0;
    printf("请输入你的年龄：");
    scanf("%d", &age);
    float ages = age * 3.156e7;
    printf("你今年%d岁了，已经活了%.2e秒了。\n", age, ages);

    return 0;
}