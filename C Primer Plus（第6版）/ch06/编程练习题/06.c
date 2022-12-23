#include <stdio.h>

int main(void) {
    int a, b;
    printf("请输入表格的下限：");
    scanf("%d", &a);
    printf("请输入表格的上限：");
    scanf("%d", &b);

    for (int i = 0; i <= b - a; i++) {
        printf(
            "%d %d %d\n", i + a, (i + a) * (i + a), (i + a) * (i + a) * (i + a));
    }

    return 0;
}