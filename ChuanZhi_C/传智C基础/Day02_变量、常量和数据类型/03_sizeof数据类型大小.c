#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 1024		// 定义常量

int main0301(void)
{
	int a = 10;		// 定义变量： 三要素

	short b = 20;		// 类型名、变量名、变量值（变量的三要素）

	long c = 30;
	long long d = 40;

	printf("================a===%u\n", sizeof(a));		// sizeof返回一个unsigned int类型的数据
	printf("================b===%u\n", sizeof(b));		// 在生成32位程序时使用printf打印的时间应该使用格式匹配符 %u 接收
	printf("================c===%u\n", sizeof(c));		// 在生成64位程序时使用printf打印的时间应该使用格式匹配符 %llu 接收
	printf("================d===%u\n", sizeof(d));		// 否则，编译器会提示警告：C6328 大小不匹配

	printf("int 大小为：%u字节\n", sizeof(int));
	printf("short 大小为：%u字节\n", sizeof(short));
	printf("long 大小为：%u字节\n", sizeof(long));
	printf("long long 大小为：%u字节\n", sizeof(long long));

	system("pause");

	return EXIT_SUCCESS;
}

int main0302(void)
{
	int a = 3;
	short b = 4;
	long c = 5;			// 5L  5l
	long long d = 6;  // 5LL  5ll

	printf("sizeof(int) = %u字节\n", sizeof(int));
	printf("sizeof(short) = %u字节\n", sizeof(short));
	printf("sizeof(long) = %u字节\n", sizeof(long));
	printf("sizeof(long long) = %u字节\n", sizeof(long long));

	printf("--------------------------------------\n");

	unsigned int aun = 3;		// 3u
	unsigned short bun = 4;		// 3u
	unsigned long cun = 5;		// 3lu
	unsigned long long dun = 6;	// 3u

	printf("sizeof(unsigned int) = %u字节\n", sizeof(unsigned int)); // aun
	printf("sizeof(unsigned short) = %u字节\n", sizeof(unsigned short));
	printf("sizeof(unsigned long) = %u字节\n", sizeof(unsigned long));
	printf("sizeof(unsigned long long) = %u字节\n", sizeof(unsigned long long));
}
