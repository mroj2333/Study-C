#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 1024		// ���峣��

int main0301(void)
{
	int a = 10;		// ��������� ��Ҫ��

	short b = 20;		// ��������������������ֵ����������Ҫ�أ�

	long c = 30;
	long long d = 40;

	printf("================a===%u\n", sizeof(a));		// sizeof����һ��unsigned int���͵�����
	printf("================b===%u\n", sizeof(b));		// ������32λ����ʱʹ��printf��ӡ��ʱ��Ӧ��ʹ�ø�ʽƥ��� %u ����
	printf("================c===%u\n", sizeof(c));		// ������64λ����ʱʹ��printf��ӡ��ʱ��Ӧ��ʹ�ø�ʽƥ��� %llu ����
	printf("================d===%u\n", sizeof(d));		// ���򣬱���������ʾ���棺C6328 ��С��ƥ��

	printf("int ��СΪ��%u�ֽ�\n", sizeof(int));
	printf("short ��СΪ��%u�ֽ�\n", sizeof(short));
	printf("long ��СΪ��%u�ֽ�\n", sizeof(long));
	printf("long long ��СΪ��%u�ֽ�\n", sizeof(long long));

	system("pause");

	return EXIT_SUCCESS;
}

int main0302(void)
{
	int a = 3;
	short b = 4;
	long c = 5;			// 5L  5l
	long long d = 6;  // 5LL  5ll

	printf("sizeof(int) = %u�ֽ�\n", sizeof(int));
	printf("sizeof(short) = %u�ֽ�\n", sizeof(short));
	printf("sizeof(long) = %u�ֽ�\n", sizeof(long));
	printf("sizeof(long long) = %u�ֽ�\n", sizeof(long long));

	printf("--------------------------------------\n");

	unsigned int aun = 3;		// 3u
	unsigned short bun = 4;		// 3u
	unsigned long cun = 5;		// 3lu
	unsigned long long dun = 6;	// 3u

	printf("sizeof(unsigned int) = %u�ֽ�\n", sizeof(unsigned int)); // aun
	printf("sizeof(unsigned short) = %u�ֽ�\n", sizeof(unsigned short));
	printf("sizeof(unsigned long) = %u�ֽ�\n", sizeof(unsigned long));
	printf("sizeof(unsigned long long) = %u�ֽ�\n", sizeof(unsigned long long));
}
