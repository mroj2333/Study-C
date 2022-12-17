#include <stdio.h>
#include <string.h>

int main(void) {
    char fname[40], lname[40];

    printf("请输入你的姓氏：\n");
    scanf("%s", fname);
    printf("请输入你的名字：\n");
    scanf("%s", lname);

    int flen = strlen(fname), llen = strlen(lname);
    printf("%s %s\n", fname, lname);
    printf("%*d %*d\n", flen, flen, llen, llen);
    putchar('\n');
    printf("%s %s\n", fname, lname);
    printf("%-*d %-*d\n", flen, flen, llen, llen);

    return 0;
}