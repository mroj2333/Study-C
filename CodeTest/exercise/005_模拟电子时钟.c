#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(void){
	for (int i = 0; i < 24; ++i)
	{
		for (int j = 0; j < 60; ++j)
		{
			for (int k = 0; k < 60; ++k)
			{
				printf("%2d:%2d:%2d\n", i, j, k);
				Sleep(990);
				system("cls");
			}
		}
	}

	return 0;
}