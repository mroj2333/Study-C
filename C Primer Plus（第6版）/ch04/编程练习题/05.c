#include <stdio.h>
#define BIT 8

int main(void) {
    float speed, size, time;
    printf("请输入网络下载速度（MBit/s）：\n");
    scanf("%f", &speed);
    printf("请输入文件大小（MByte）：\n");
    scanf("%f", &size);
    time = size * BIT / speed;
    printf(
        "At %.2f megabits per second, a file of %.2f megabytes\ndownloads in "
        "%.2f seconds.\n",
        speed,
        size,
        time);

    return 0;
}