#include <stdio.h>

int main(void) {
    printf("请输入你的姓名，格式为：名字 姓氏\n");
    char name1[10];
    char name2[10];
    scanf("%s %s", name2, name1);
    printf("%s，%s\n", name1, name2);

    return 0;
}