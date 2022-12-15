#include <stdio.h>

int main(void) {
    float cups = 0;

    printf("请输入杯数：");
    scanf("%f", &cups);

    float pint = cups / 2;
    float angs = cups * 8;
    float tcups = angs * 2;
    float ccups = tcups * 3;
    printf("以品脱为单位有：%.2f\n", pint);
    printf("以盎司为单位有：%.2f\n", angs);
    printf("以汤勺为单位有：%.2f\n", tcups);
    printf("以茶勺为单位有：%.2f\n", ccups);

    return 0;
}