#include <stdio.h>
#define CONVERT 60

int main(void) {
    int hours, minutes;

    printf("请输入时间，以分钟为单位：");
    scanf("%d", &minutes);

    while (minutes > 0) {
        printf("你输入的时间是%d分钟，合计%d小时%d分钟。\n",
               minutes,
               minutes / CONVERT,
               minutes % CONVERT);
        printf("继续输入请直接输入，结束请输入0。\n");
        scanf("%d", &minutes);
    }

    return 0;
}