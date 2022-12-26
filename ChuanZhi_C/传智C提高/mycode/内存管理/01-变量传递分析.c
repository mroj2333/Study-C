/*

*/
#include <stdio.h>
#include <stdlib.h>

char *func() {
  int c = 2; //仅在func中可以使用
  char *p =
      malloc(10); //在堆区申请的空间，只要不释放在main、test01和func中都可以使用

  return p;
}

void test01() {
  int b = 5; //在test01和func中可以使用
  func();
}

int main(void) {
  int a = 10; //在main、test01和func中都可以使用
  test01();

  return 0;
}