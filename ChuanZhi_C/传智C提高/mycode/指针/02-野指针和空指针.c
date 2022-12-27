/*
不允许向NULL或非法地址拷贝内存
*/
#include <stdio.h>
#include <string.h>

int main(void) {
  //空指针
  char *p = NULL;
  strcpy(p, "111"); // error 不允许给空指针赋值

  // 野指针
  char *p1 = 0x123346;
  strcpy(p1, "1111"); // error 不允许给野指针赋值

  return 0;
}