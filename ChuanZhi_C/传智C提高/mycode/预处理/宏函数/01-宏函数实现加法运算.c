/*
本例是一个简单的使用宏函数进行加法的运算实现，但是宏函数在使用的过程中有一些
需要注意的地方

1、使用宏函数的时间一般需要使用小括号进行包括（详见下一个文件的示例）
2、通常会将短小、频繁使用的函数定义成宏函数
3、宏函数 会比一般的函数在一定程度上效率更高，因为省去了函数出栈入栈时间上的开销

优点：以空间换时间
*/
#include <stdio.h>
#define MYADD(x, y) x + y

int main(void) {
  int a = 2;
  int b = 3;

  int ret = MYADD(a, b);
  printf("ret = %d\n", ret);
  printf("%d\n", MYADD(5, 2));

  return 0;
}