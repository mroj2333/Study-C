#include <stdio.h>

int func(int a, int b);

int main(void) {
    int a, b;
    printf("Enter lower and upper integer limits: ");
    int ret = scanf("%d %d", &a, &b);
    if (a == b) {
        printf("Done\n");
        return 0;
    }
    while (ret == 2) {
        printf("The sums of the squares from %d to %d is %d\n",
               a * a,
               b * b,
               func(a, b));
        printf("Enter next set of limits: ");
        ret = scanf("%d %d", &a, &b);
        if (a == b) {
            break;
        }
    }
    printf("Done\n");

    return 0;
}

int func(int a, int b) {
    int ret = 0;
    for (int i = b - a; i >= 0; i--) {
        ret = ret + (a + i) * (a + i);
    }
    return ret;
}