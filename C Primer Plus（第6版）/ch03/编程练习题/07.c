#include <stdio.h>

int main(void) {
    printf("请输入你的身高，单位为英寸：");
    float a = 0;
    scanf("%f", &a);
    printf("你的身高以厘米为单位是%.2fCM。\n", a * 2.54);

    return 0;
}