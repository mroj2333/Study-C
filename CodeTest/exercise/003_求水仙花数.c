#include <stdio.h>

int  main(void){
	int a, b, c;

	for (int i = 100; i < 1000; ++i){
		a = i % 10;
		b = i / 10 % 10;
		c = i / 100;
		a = a * a * a;
		b = b * b * b;
		c = c * c * c;

		if(a+b+c == i){
			printf("%d ", i);
		}
	}

	return 0;
}