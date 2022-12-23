#include <stdio.h>

int main(void) {
    int year = 0;
    double money = 1000000;

    while (money > 0) {
        money = money + money * 0.08;
        money = money - 100000;
        year++;
    }
    printf("%d\n", year);

    return 0;
}