#include <stdio.h>

int main(void) {
    printf("请输入一个整数：");
    int a = 0;
    scanf("%d", &a);

    while (a > 0) {
        float b = 1, c = 1;
        for (int i = 2; i <= a; i++) {
            b += 1.0 / i;
            if (i % 2 == 0) {
                c = c - 1.0 / i;
            } else {
                c = c + 1.0 / i;
            }
        }

        printf("b = %.4f, c = %.4f\n请继续输入一个整数，或者输入非正整数退出：",
               b,
               c);
        scanf("%d", &a);
    }

    return 0;
}