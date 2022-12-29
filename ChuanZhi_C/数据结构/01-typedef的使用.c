#include <stdio.h>

void test01(void);
void test02(void);
void test03(void);

int main(void) {
  test01();

  return 0;
}

void test01(void) {
  struct Person {
    char name[20];
    int age;
  };
  struct Person P1;
  P1.age = 18;
  // 上面我们定义的结构体在使用的时间只能带上struct，如果不带程序会报错
  // 我们可以使用typedef来给结构体起别名，简化struct关键字
  typedef struct Person MyPerson;
  // 现在就可以使用我们定义出来的别名MyPerson来创建一个Person结构体的对象了
  MyPerson P2;
  P2.age = 20;
  printf("test01:\n");
  printf("P1.age = %d\n", P1.age);
  printf("P2.age = %d\n", P2.age);
  // 运行程序可以看到P1、P2的age属性都得到了正确的赋值
}

void test02(void) {
  char *p1, p2;
  // 很多人初学C语言的时间会把上面的表达式误以为p1和p2都是char*类型的指针变量
  // 实际上只有p1是char*类型，而p2则是char类型的
  // 为了避免这种问题，我们可以这样定义
  char *p3, *p4;
  // 这样定义出来的两个变量都是char*类型的
  // 我们也可以使用typedef来解决这个问题
  typedef char *MyChar;
  MyChar p5, p6;
  // 这样定义出来的两个变量也都是char*类型的
}

void test03(void) {
  // typedef可以提高移植性
  // long long类型是C99新增的类型，如果我们的程序中有很多long long类型的定义，那
  // 么程序移植到不支持C99的系统上将无法运行
  // 我们可以通过typedef定义long
  // long类型的别名，移植后只需修改一处即可使程序正常运行
  typedef long long MyInt;
  MyInt a = 10;
  MyInt b = 100;
}