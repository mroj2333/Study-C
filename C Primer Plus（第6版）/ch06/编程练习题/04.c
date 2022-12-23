#include <stdio.h>

int main(void) {
    char a = 'A';

    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < i; j++) {
            printf("%c", a);
            a += 1;
        }
        putchar('\n');
    }

    return 0;
}