#include <stdio.h>

int main(void) {
    char Arr[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (int i = 0; i < 26; i++) {
        printf("%c ", Arr[i]);
    }

    putchar('\n');

    return 0;
}