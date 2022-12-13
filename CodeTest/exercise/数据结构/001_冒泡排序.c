#include <stdio.h>

int main(void){
	int Arr[] = {45, 85, 34, 46, 61, 22};

	int len = sizeof(Arr) / sizeof(Arr[0]);
	int tmp = 0;

	for (int i = 0; i < len -1; i++){
		for(int j = 0; j < len -1 -i; j++){
			if (Arr[j] > Arr[j+1])
			{
				tmp = Arr[j];
				Arr[j] = Arr[j+1];
				Arr[j+1] = tmp;
			}
		}
	}

	for (int i = 0; i < len; ++i)
	{
		printf("%d ", Arr[i]);
	}

	return 0;
}