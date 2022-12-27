#include <stdio.h>

void test01(void);
void test02(void);

struct LinkNode {
  int a;
  struct LinkNode *p;
};

int main(void) {
  // 动态链表

  //静态链表

  return 0;
}

void test01(void);
void test02(void) {
  // 创建节点
  struct LinkNode node01 = {1, NULL};
  struct LinkNode node02 = {2, NULL};
  struct LinkNode node03 = {3, NULL};
  struct LinkNode node04 = {4, NULL};
  struct LinkNode node05 = {5, NULL};

  // 建立关系
  node01.p = &node02;
  node02.p = &node03;
  node03.p = &node04;
  node04.p = &node05;

  // 打印链表的值
}