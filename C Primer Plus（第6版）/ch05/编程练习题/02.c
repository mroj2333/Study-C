#include <stdio.h>

int main(void) {
    int num = 0;
    int tmp = 0;
    printf("请输入一个整数：\n");
    scanf("%d", &num);
    tmp = num;

    while (tmp++ < num + 11) {
        printf("%d ", tmp - 1);
    }
    printf("\n");

    return 0;
}