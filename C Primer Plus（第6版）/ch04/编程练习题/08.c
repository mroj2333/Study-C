#include <stdio.h>
#define MILE   1.609
#define GALLON 3.785

int main(void) {
    float l, g;
    printf("请输入里程：\n");
    scanf("%f", &l);
    printf("请输入耗油量：\n");
    scanf("%f", &g);
    printf("消耗每加仑汽油行驶的英里数为:%.2f\n", l / g);

    printf("%.1f升/100km\n", (l * MILE) / (g * GALLON));

    return 0;
}