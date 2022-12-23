#include <stdio.h>

int main(void) {
    char c;
    printf("请输入一个大写字母： ");
    scanf("%c", &c);
    int a = c - 65;

    for (int i = 0; i <= a; i++) {
        for (int j = a - i; j > 0; j--) {
            printf(" ");
        }
        for (int k = 0; k <= i; k++) {
            printf("%c", 65 + k);
        }
        for (int l = i; l > 0; l--) {
            printf("%c", 65 + l - 1);
        }
        printf("\n");
    }

    return 0;
}