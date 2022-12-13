#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// 隐式类型转换。
int main0601(void)
{
	int a = 321;		

	char ch = a;

	printf("ch = %d\n", ch);		// ch是一个字符变量，但是打印的时间匹配符是%d，编译器会将ch变量隐式的转换成整型变量

	system("pause");
	return EXIT_SUCCESS;
}

// 强制类型转换
int main0602(int var)
{
	//int *p = (int *)malloc(100);

	float price = 3.6;
	int weight = 4;

	//double sum = (int)price * weight;

	double sum = (int)(price * weight);		// 强制类型转换的格式是   (类型名称)待转换的变量

	printf("价格：%lf\n", sum);

	system("pause");
	return EXIT_SUCCESS;
}
