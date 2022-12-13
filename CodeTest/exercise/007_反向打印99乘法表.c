#include <stdio.h>

int main(void){
	for (int i = 9; i > 0; i--){
		for(int j = 1; j <= i; j++){
			printf("%d*%d=%2d\t", j, i, j*i);
		}
		printf("\n");
	}

	return 0;
}