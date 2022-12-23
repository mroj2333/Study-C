#include <stdio.h>

int main(void) {
    double Arr1[8] = {0};
    double Arr2[8] = {0};

    for (int i = 0; i < 8; i++) {
        printf("请输入数组的第%d个元素：", i);
        scanf("%lf", &Arr1[i]);
        if (i == 0) {
            Arr2[i] = Arr1[i];
        } else {
            Arr2[i] = Arr2[i - 1] + Arr1[i];
        }
    }

    for (int i = 0; i < 8; i++) {
        printf("%.2lf ", Arr1[i]);
    }
    putchar('\n');
    for (int i = 0; i < 8; i++) {
        printf("%.2lf ", Arr2[i]);
    }
    putchar('\n');

    return 0;
}