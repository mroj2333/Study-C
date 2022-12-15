/* altnames.c -- 可移植整数类型名 */
#include <stdio.h>
#include <inttypes.h>

int main(void) {
    int32_t me32; // me32是一个32位有符号整型变量

    me32 = 45933945;
    printf("First, assumr int32_t is int: ");
    printf("me32 = %d\n", me32);
    printf("Instead, use a \"macro\" from inttyoes.h: ");
    printf("me32 = %" PRId32 "\n", me32);

    return 0;
}