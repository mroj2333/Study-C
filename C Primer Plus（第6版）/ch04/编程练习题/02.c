#include <stdio.h>
#include <string.h>

int main(void) {
    printf("请输入你的姓名：\n");
    char name[40];
    scanf("%s", name);
    int len = strlen(name);

    printf("a.\"%s\"\n", name);
    printf("b.\"%18s\"\n", name);
    printf("c.\"%-18s\"\n", name);
    printf("d.\"%*s\"", len + 3, name);

    return 0;
}