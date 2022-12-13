#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0501(void)
{
	char ch = 'A';  // 对应的ASCII码是65

	//printf("1 ch = %c\n", ch);
	printf("1 ch = %d\n", ch);

	ch = 'm'; //对应的ASCII码是109

	//printf("2 ch = %c\n", ch);
	printf("2 ch = %d\n", ch);

	//ch = 97;
	ch = 'a';	// 对应的ASCII码是97

	//printf("3 ch = %c\n", ch);
	printf("3 ch = %d\n", ch);

	system("pause");
	return EXIT_SUCCESS;
}

// A -- 65 a -- 97 
int main0502(void)
{
	char ch = 'M';
	char var = '5';

	printf("ch = %c\n", ch + 32);		// 大写字母 +32 可以转换为对应的小写字母
	printf("var = %c\n", var+4);

	printf("'\\n\'的值为=%d\n", '\n');		// \n的ASCII码是10

	system("pause");
	return EXIT_SUCCESS;
}

