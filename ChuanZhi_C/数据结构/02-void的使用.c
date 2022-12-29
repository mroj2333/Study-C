#include <stdio.h>

void test01(void);

int main(void) {
  test01();

  return 0;
}

// 1、void无类型
void test01(void) {
  // 不可以使用void创建变量，因为不能够分配内存
  // void a = 3; //error
}

// 2、void用途：限定函数返回值、限定函数参数

// 3、void * 万能指针，不管是什么类型的指针、几级指针都是4字节