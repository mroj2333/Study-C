#include <stdio.h>

int main(void) {
    int weeks = 1;
    int friends = 5;
    while (friends < 150) {
        friends = friends - weeks;
        friends = friends * 2;
        printf("第%d周，朋友数量是：%d\n", weeks, friends);
        weeks++;
    }

    return 0;
}