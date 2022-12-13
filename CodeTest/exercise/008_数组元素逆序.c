#include <stdio.h>

int main(void){
	int Arr[] = {1, 2, 3, 4, 5, 6};

	int len = sizeof(Arr) / sizeof(Arr[0]);
	int indx = 0;
	int last = len -1;
	int tmp = 0;

	while(indx < last){
		tmp = Arr[indx];
		Arr[indx] = Arr[last];
		Arr[last] = tmp;
		indx++;
		last--;
	}

	for (int i = 0; i < 6; ++i)
	{
		printf("%d ", Arr[i]);
	}

	return 0;
}