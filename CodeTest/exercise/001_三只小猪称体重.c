#include <stdio.h>

int main(void){
	double a, b, c;

	printf("请输入三只小猪的体重，以空格分隔，回车结束");
	scanf("%lf %lf %lf",&a, &b, &c);

	if (a > b){
		if(a > c){
			printf("第一只小猪最重，%.2f\n", a);
		}else if(a == c){
			printf("第一、三只小猪最重，%.2f\n", a);
		}else{
			printf("第三只小猪最重，%.2f\n", c);
		}
	}else if(a < b){
		if(c < b){
			printf("第二只小猪最重，%.2f\n", b);
		}else if(c == b){
			printf("第二、三只小猪最重，%.2f\n", b);
		}else{
			printf("第三只小猪最重，%.2f\n", c);
		}
	}else{
		if (a > c){
			printf("第一、二只小猪最重，%.2f\n", a);
		}else if(a < c){
			printf("第三只小猪最重，%.2f\n", c);
		}else{
			printf("三只小猪一样重，%.2f\n", a);
		}
	}

	return 0;
}