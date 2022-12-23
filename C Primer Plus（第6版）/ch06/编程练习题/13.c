#include <stdio.h>

int main(void) {
    int Arr[8] = {0};
    int a = 2;

    for (int i = 0; i < 8; i++) {
        Arr[i] = a;
        a = a * 2;
    }

    int index = 0;
    do {
        printf("%d ", Arr[index]);
        index += 1;
    } while (index < 8);

    putchar('\n');

    return 0;
}