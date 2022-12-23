#include <stdio.h>

int main(void) {
    int Arr[8] = {0};
    printf("请输入1个整数：");
    scanf("%d", &Arr[0]);
    for (int i = 1; i < 8; i++) {
        printf("请继续输入1个整数：");
        scanf("%d", &Arr[i]);
    }

    printf("您输入的整数是：");
    for (int i = 7; i >= 0; i--) {
        printf("%d ", Arr[i]);
    }
    putchar('\n');

    return 0;
}