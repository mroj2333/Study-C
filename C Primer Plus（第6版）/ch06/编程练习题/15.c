#include <stdio.h>
#include <string.h>

int main(void) {
    int index = 0;
    char Arr[255] = {0};

    for (int i = 0; i < 255; i++) {
        scanf("%c", &Arr[i]);
        if (Arr[i] == '\n') {
            Arr[i] = '\0';
            break;
        }
    }

    int len = strlen(Arr);
    for (int i = len; i >= 0; i--) {
        printf("%c", Arr[i]);
    }

    putchar('\n');

    return 0;
}