#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0401(void)
{
	int a = 34;
	int b = 0;

	char str[10] = "hello";

	++str[0];		// 对str字符数组的第一个元素进行+1操作 == ++(str[0])  == str[0] + 1
	printf("%s\n", str);

	printf("a = %d\n", !a);
	printf("b = %d\n", !b);

	printf("======%d\n", a && !b);

	printf("------%d\n", !a || b);

	system("pause");
	return EXIT_SUCCESS;
}
