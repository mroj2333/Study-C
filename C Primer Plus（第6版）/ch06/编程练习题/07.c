#include <stdio.h>
#include <string.h>

int main(void) {
    char Arr[1024] = {0};
    printf("请输入一个单词：");
    scanf("%s", Arr);

    for (int i = strlen(Arr); i >= 0; i--) {
        printf("%c", Arr[i]);
    }
    putchar('\n');

    return 0;
}