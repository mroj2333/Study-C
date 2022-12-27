/*
- 指针是一种数据类型，占用内存空间，用来保存内存地址。
- 指针是变量，指针本身也占内存空间，指针也可以被赋值。

*/
#include <stdio.h>

void test01(void);
void test02(void);

int main(void) {
  test01();
  test02();

  return 0;
}

void test01(void) {
  int a = 10;
  int b = 20;
  int *p1 = &a;
  int *p2 = &b;

  printf("test01:\n");
  printf("p1 size = %zd\n", sizeof(p1));
  printf("p2 size = %zd\n", sizeof(p2));
  printf("a  size = %zd\n", sizeof(a));
}
void test02(void) {
  int a = 10;
  int *p = &a;

  printf("test02:\n");
  printf("对指针变量p取地址，值为：      %p\n", &p);
  printf("直接输出指针变量p的地址，值为：%p\n", p);
  printf("对变量a取地址，值为：          %p\n", &a);
}