#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0701(void)
{
	int a = 0x2C;  // �ȼ� 0x2c ʮ��������ʽ���ȼ� 054  �˽�����ʽ���ȼ� 44  ʮ������ʽ
					// ��һ����ֵǰ�����0x��0X��ʶ�ͱ���������ֵ�ʮ�����Ƶ�
					// ��һ����ֵǰ�����0��ʶ�ͱ���������ֵİ˽��Ƶ�

	printf("10������ʾ a = %d\n", a);
	printf("8������ʾ a = %o\n", a);
	printf("8������ʾ a = %#o\n", a);		// ��ӡ�˽���ǰ׺�ĸ�ʽƥ���
	printf("16������ʾ a = %x\n", a);
	printf("16������ʾ a = %#x\n", a);		// ��ӡʮ������ǰ׺�ĸ�ʽƥ���  Сдģʽ
	printf("16������ʾ a = %#X\n", a);		// ��дģʽ

	system("pause");
	return EXIT_SUCCESS;
}
