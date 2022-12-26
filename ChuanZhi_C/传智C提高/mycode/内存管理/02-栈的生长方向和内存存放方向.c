/*
1、栈的生长方向
    通过test01可以看出先创建的变量内存地址比后创建的变量内存地址大，由
    此可以看出，栈是从高到低进行生长
也就是说，高位地址是栈底，低位地址是栈顶

2、内存存放方向
    通过test02可以看出，数据在内存中存放的方向是高位地址存放高位数据，
    低位地址存放低位的数据；这种对齐的方式称为  小端对齐
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
  int a = 1;
  int b = 2;
  printf("test01:栈的生长方向\n");
  printf("变量a的内存地址是：%p\n", &a);
  printf("变量b的内存地址是：%p\n", &b);
}

void test02(void) {
  int a = 0x11223344;
  char *p = (char *)&a;
  printf("test02:内存的存放方向\n");
  printf("*p \t= %x\n", *p);
  printf("*(p+1) \t= %x\n", *(p + 1));
}