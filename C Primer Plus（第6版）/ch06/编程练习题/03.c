#include <stdio.h>

int main(void) {
    char a = 'F';
    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < i; j++) {
            printf("%c", a - j);
        }
        putchar('\n');
    }

    return 0;
}