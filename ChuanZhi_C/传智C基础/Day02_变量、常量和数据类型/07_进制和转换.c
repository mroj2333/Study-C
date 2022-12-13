#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0701(void)
{
	int a = 0x2C;  // 等价 0x2c 十六进制形式；等价 054  八进制形式；等价 44  十进制形式
					// 在一个数值前面加上0x或0X标识就表明这个数字的十六进制的
					// 在一个数值前面加上0标识就表明这个数字的八进制的

	printf("10进制显示 a = %d\n", a);
	printf("8进制显示 a = %o\n", a);
	printf("8进制显示 a = %#o\n", a);		// 打印八进制前缀的格式匹配符
	printf("16进制显示 a = %x\n", a);
	printf("16进制显示 a = %#x\n", a);		// 打印十六进制前缀的格式匹配符  小写模式
	printf("16进制显示 a = %#X\n", a);		// 大写模式

	system("pause");
	return EXIT_SUCCESS;
}
