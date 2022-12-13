#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0101(void)
{
	char ch = 'a';

	printf("ch = %c\n", ch);		// 输出字符使用格式化匹配符%c

	char str[20] = "hello world";

	printf("str = %s\n", str);		// 输出字符串使用格式化匹配符%s

	system("pause");
	return EXIT_SUCCESS;
}

int main0102(void)
{
	char str[] = "hello world";

	printf("str = |%-15s|\n", str);		// 输出15个字符的内容、使用||进行包裹，并使用左对齐的方式

	system("pause");
	return EXIT_SUCCESS;
}

int main0103(void)
{
	putchar(97);  // 'a' == 97
	putchar('b');
	putchar('c');
	putchar('d');

	putchar('abcZ');		// 错误的输出方式，'abcZ'既不是一个字符也不是一个字符串，会导致程序出错

	system("pause");
	return EXIT_SUCCESS;
}
