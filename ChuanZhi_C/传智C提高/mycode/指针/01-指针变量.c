/*
- 指针是一种数据类型，占用内存空间，用来保存内存地址。
- 指针是变量，指针本身也占内存空间，指针也可以被赋值。

*/
#include <stdio.h>

int main(void) {
  int a = 10;
  int b = 20;
  int *p1 = &a;
  int *p2 = &b;

  printf("p1 size = %zd\n", sizeof(p1));
  printf("p2 size = %zd\n", sizeof(p2));

  return 0;
}