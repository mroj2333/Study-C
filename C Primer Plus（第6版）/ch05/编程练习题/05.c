#include <stdio.h>

int main(void) {
    int count, sum, day;

    count = 0;
    sum = 0;
    printf("请输入一个整数： ");
    scanf("%d", &day);
    while (count++ < day) {
        sum = sum + count;
    }
    printf("sum = %d\n", sum);

    return 0;
}