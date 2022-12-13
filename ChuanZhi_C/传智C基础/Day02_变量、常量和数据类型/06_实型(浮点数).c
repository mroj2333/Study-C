#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0601(void)
{
	float m = 3.145;
	double n = 4.566545;

	printf("m = %08.2f\n", m);		// 00003.14  一共输出八位数字，其中小数点后面是两位，小数点占一位，剩余的分给小数点前面的，其余的用0填充
	printf("n = %08.3lf\n", n);		// 0004.567

	system("pause");
	return EXIT_SUCCESS;
}
