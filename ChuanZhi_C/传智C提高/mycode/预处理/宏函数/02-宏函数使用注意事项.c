/*
test01是没有使用小括号包裹的效果，可以看到程序运行后的结果与我
们期望的结果是有一定的出入的

test02使用另一个使用了小括号的宏函数，得到了预期的结果
*/
#include <stdio.h>
#define MYADD(x, y) x + y
#define MYADD2(x, y) ((x) + (y))

void test01(void);
void test02(void);

int main(void) {
  test01();
  test02();

  return 0;
}

void test01(void) {
  // (10+5)*2 = 30
  printf("test01:%d\n", MYADD(10, 5) * 2);
}

void test02(void) {
  // (10+5)*2 = 30
  printf("test02:%d\n", MYADD2(10, 5) * 2);
}