#include <stdio.h>
#define WEEK 7

int main(void) {
    int day;
    printf("请输入天数：");
    scanf("%d", &day);

    while (day > 0) {
        printf("%d days are %d weeks, %d days.\n", day, day / WEEK, day % WEEK);
        printf("请继续输入天数或者输入非正值结束：");
        scanf("%d", &day);
    }

    return 0;
}