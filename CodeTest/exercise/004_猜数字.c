#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	srand(time(0));
	int a = rand() % 100;
	int b = 0;
	
	printf("系统随机生成了一个100以内的整数，请你猜猜它的值是多少，请重新输入：");


	while(1){
		scanf("%d", &b);

		if (b < a)
		{
			printf("猜小了，请重新输入：");
		}else if (b>a)
		{
			printf("猜大了，请重新输入：");

		}else{
			printf("恭喜你猜对了，数字是%d\n", a);
		}
	}

	system("pause");
	return 0;
}