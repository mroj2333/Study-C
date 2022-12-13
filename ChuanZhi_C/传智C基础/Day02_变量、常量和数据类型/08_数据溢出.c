#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main08(void)
{
	char ch0 = 127;
	char ch1 = 127 + 1;		// char类型的取值范围是：-128 -- 127
	unsigned char ch2 = 255;
	unsigned char ch3 = 255 + 1;		// unsigned char类型的取值范围是：0 -- 255

	printf("ch = %d\n", ch0);
	printf("ch = %d\n", ch1);
	printf("ch = %d\n", ch2);
	printf("ch2 = %d\n", ch3);

	system("pause");
	return EXIT_SUCCESS;
}
