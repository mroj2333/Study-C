#include <stdio.h>

int main(void){
	for (int i = 1; i < 100; ++i)
	{
		if (i%7==0 || i%10==7 || i/10==7)
		{
			printf("敲桌子 ");
		}else{
			printf("%d ", i);
		}
	}

	return 0;
}