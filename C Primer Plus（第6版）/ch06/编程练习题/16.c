#include <stdio.h>

int main(void) {
    float a = 100;
    float b = 100;
    int index = 0;

    while (a >= b) {
        a = a + 10;
        b = b + b * 0.05;
        index++;
    }

    printf("第%d年的时候Deirdre的投资额才会超过Daphne\n", index);
    printf("Deirdre的投资额是:%.2f,Daphne的投资额是:%.2f。\n", a, b);

    return 0;
}