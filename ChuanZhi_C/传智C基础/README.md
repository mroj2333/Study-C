# Day01_Hello World

## 解决VS IDE环境下命令行提示窗一闪而过

1. 通过 system()函数解决：
   在 `return 0；`之前 添加 `system("pause");` 函数调用。

2. 借助VS工具解决：
   在项目上   →   右键   →   属性   →   配置属性   →   连接器   →   系统   →   子系统   →   在下拉框中选择“控制台 (/SUBSYSTEM:CONSOLE)”

## 两种编写 helloworld 的方式：

1. 借助VS编辑工具编写。
   创建项目   →   创建 `helloworld.c `源文件   →   写 helloworld程序   →   Ctrl + F5 执行。 

2. 借助记事本、gcc编译工具编写。

## gcc编译工具的环境变量配置：

在QT的安装目录中找 gcc.exe 目录位置。例如： `C:\Qt\Qt5.5.0\Tools\mingw492_32\bin`

我的电脑   →   属性   →   高级系统设置   →   环境变量   →   系统环境变量   →   path   →   将gcc.exe 目录位置写入到 path的值中。

使用记事本创建 `helloworld.c` 文件   →   在记事本中写 helloworld 程序   →   使用gcc编译工具 ，在记事本写的 helloworld.c 所在目录中，执行 `gcc helloworld.c -o myhello.exe`   →   在终端（黑窗口）中，运行 ： `myhello.exe`

## C语言的注释

单行注释：`// 单行注释注释内容`

多行注释：`/* 多行注释注释内容 */`

不允许嵌套使用。 多行中可嵌套单行。

## system 函数：

执行系统命令。如： `pause、cmd、calc、mspaint、notepad.....`

```c
system("cmd");  
system("calc");

// 清屏命令：
cls; system("cls");
```

## gcc编译4步骤：【重点】

1. 预处理`-E	xxx.i`预处理文件

```c
gcc -E xxx.c -o xxx.i
```

```
1) 头文件展开  --- 不检查语法错误。 可以展开任意文件。
2）宏定义替换  --- 将宏名替换为宏值。
3）替换注释  --- 变成空行
4）展开条件编译  --- 根据条件来展开指令。
```

2. 编译`-S	xxx.s`汇编文件

```c
gcc -S hello.i -o hello.s
```

```
1）逐行检查语法错误。【重点】	--- 整个编译4步骤中最耗时的过程。
2）将C程序翻译成 汇编指令，得到.s 汇编文件。
```

3. 汇编`-c	xxx.o`目标文件

```c
gcc -c hello.s -o hello.o
```

```
1）翻译：将汇编指令翻译成对应的 二进制编码。
```

4. 链接`无	xxx.exe`可执行文件。

```c
gcc  hello.o -o hello.exe
```

```
1）数据段合并
2）数据地址回填
3）库引入
```

## 调试程序：

> ### 添加行号：
>
> 工具   →   选项   →   文本编辑器   →   C/C++   →   行号 选中。

1. 设置断点。F5启动调试
2. 停止的位置，是尚未执行的指令。
3. 逐语句执行一下条 （F11）：进入函数内部，逐条执行跟踪。
4. 逐过程执行一下条 （F10）：不进入函数内部，逐条执行程序。
5. 添加监视：
   调试  →   窗口   →   监视：输入监视变量名。自动监视变量值的变化。


# Day02_变量、常量和数据类型

## 常量

不会变化的数据。不能被修改。

1. `“hello”`、`'A'`、`-10`、`3.1415926`（浮点常量）
2. `#define PI 3.1415`【强调】：没有分号结束标记。 【推荐】 定义宏： 定义语法： `#define 宏名 宏值`
3. `const int a = 10;`定义语法：`const 类型名 变量名 = 变量值;`。

## const关键字

被该关键字修饰的变量，表示为只读变量。

## 变量

会变化的数据。能被修改。

定义语法：`类型名 变量名 = 变量值;`。（一般方法）
变量三要素：类型名、变量名、变量值。`int r = 3;`  `float s = PI*r*r;`(变量值是一个表达式)
变量的定义：`int a = 40;`
变量的声明：

1) `int a;` 没有变量值的变量定义 叫做声明。
2) `extern int a;` 添加了关键字 extern。

1. 变量定义会开辟内存空间。变量声明不会开辟内存空间。
2. 变量要想使用必须有定义。

当编译器编译程序时，在变量使用之前，必须要看到变量定义。如果没有看到变量定义，编译器会自动找寻一个变量声明提升成为定义。

如果该变量的声明前有 extern 关键字，无法提升。

**【建议】：定义变量时。尽量不要重名。**

## 标识符

变量和常量的统称。

命名规则：

1. 通常常量使用大写、变量使用小写。大小写严格区分。
2. 只能使用字母、数组、下划线（_）命名标识符。且，数字不能开头。 `a-z/A-Z/0-9/_`

```c
int a5ir = 10; ok
int _34F = 6; ok
float s2_i85c = 5.4;  ok
int 98ti_54 = 4;  error.
```

3. 禁止使用关键字和系统函数作为标识符名称。  `main/system/printf/sleep....`

## sizeof关键字

不是函数。用来求一个变量、类型的大小。 返回一个 无符号整数。 使用 `%u` 接收返回值。
方法1： `sizeof（类型名）`→`sizeof(int)`
方法2： `sizeof(变量名)`→ `int a = 20；` ` sizeof(a)`

【了解】： `sizeof 变量名/类型名`
举例1： `sizeof int`
举例2： `sizeof a`

## 有符号整型

signed： 有符号 （超级不常用， 通常省略）：`int a = 10;`   ` a = -7;`
int类型：`%d`   4 字节
`int 名 = 值;`
`int a = 10;`

short类型：`%hd`  2 字节
`short 名 = 值;`
`short s1 = 3;`

long类型：`%ld`  4 字节(windows: 32/64: 4字节； Linux：32位:4字节， 64位:8字节)
`long 名 = 值;`
`long len = 6;`

long long 类型：`%lld`  8 字节
`long long 名= 值;`
`long long llen = 70;`

## 无符号整型

unsigned： 无符号 只表示数据量，而没有方向（没有正负）

unsigned int类型：`%u`  4 字节
`unsigned int 名 = 值;`
`unsigned int a = 40;`

unsigned short类型：`%hu`  2 字节
`unsigned short 名 = 值;`
`unsigned short s1 = 3;`

unsigned long类型：`%lu`  4 字节 (windows: 32/64: 4字节； Linux：32位:4字节， 64位:8字节)
`unsigned long 名 = 值;`
`unsigned long len = 6;`

unsigned long long 类型：`%llu`  8 字节
`unsigned long long 名 = 值;`
`unsigned long long llen = 70;`

## char字符类型

1字节  存储一个字符。本质是ASCII码。 `‘A’`、`‘a’`、`‘%’`、`‘#’`、`‘0’`
格式匹配符： `%c`
`‘A’` 的ASCII码是：65
`‘a’` 的ASCII码是：97
`‘0’` 的ASCII码是：48
`‘\n’` 的ASCII码是：10
`‘\0’` 的ASCII码是：0

## 转义字符

`‘\’` 将普通字符转为 特殊意。 将特殊字符转为本身意。
`'\n'` ASCII码为10，也就是换行符   和    `‘\0’`ASCII码为0，也就是空字符

## 浮点类型

float：单精度浮点型。4字节
`float v1 = 4.345;`
`%f`格式匹配符。 默认保留 6 位小数。

double：双精度浮点型。8字节【默认】
`double v2 = 5.678;`
`unsigned float v1 = 4.345;`无符号的 float 数据
`unsigned double v2 = 5.678;`无符号的 double 数据

`printf("n = %08.3f\n", n);`输出的含义为：显示8位数（包含小数点）， 不足8位用0填充。并且保留3位小数。对第4位做四舍五入。

## 进制和转换

2^10^ = 1024		2^9^ = 512		2^8^ = 256		2^7^ = 128		2^6^ = 64		2^5^ = 32		2^4^ = 16		2^3^ = 8		2^2^ = 4

### 10进制

十进制转2进制。--- 除2反向取余法。 【重点】
十进制转8进制。--- 除8反向取余法。
十进制转16进制。--- 除16反向取余法。

10进制转2进制
`int a = 56;`-- 111000
`int b = 173;`    -- 10101101

### 8进制

定义8进制数语法：零开头，每位数0~7之间。
`056`：  → 46
`0124`： → 84

8进制转2进制:按421码将每个八进制位展开。
`056`：5 → 101; 6  → 110 	→ 101110
`05326`：5 → 101; 3 → 011;2 → 010; 6 → 110 	→ 101011010110

2进制转8进制：自右向左，每3位一组，按421码转换。高位不足三位补0

1 010 111 010 110 → 012726

### 16进制

语法： 以0x开头，每位 取 `0-9/A-F/a-f`
A -- 10		B -- 11		C -- 12		D -- 13		E -- 14		F -- 15		

16进制转10进制:
`0x1A`:  16+10 = 26
`0x13F`：15+3x16+256 

16进制转2进制:
`0x1A`:00011010
`0x13F`：000100111111

2进制转16进制:自右向左，每4位一组，按8421码转换。高位不足三位补0
`0001 0011 1111`:13F

总结：
`int m = 0x15F4;`
`int n = 345;`
`int var = 010011;` // 不允许。 不能给变量直接赋值 二进制数据。

## 输出格式匹配符

`%d`:匹配int类型
`%u`:匹配unsigned int类型
`%o`:匹配8进制int类型
`%x`:匹配16进制int类型
`%hd`:匹配short类型
`%hu`:匹配unsigned short类型
`%ld`:匹配long int类型
`%lu`:匹配unsigned long int类型
`%lld`:匹配long long int类型
`%llu`:匹配unsigned long long int类型
`%c`:匹配char类型
`%f`:匹配float类型
`%lf`:匹配double类型
`%s`:匹配string类型

## 存储知识

1 bit位  就是一个 二进制位。一个字节 1B = 8bit位。 1KB = 1024B，1MB = 1024KB，1GB = 1024MB，1TB = 1024GB。

## 源码反码补码：【了解】

源码：
`43` -> `00101011`
`-43` --> `10101011`

反码：
`43` -> `00101011`
`-43` --> `10101011`
11010100

补码：(现今计算机采用的存储形式)
`43` -> `00101011`： 正数不变
`-43` --> `11010101`： 负数，最高位表符号位， 其余取反+1
`43-27` ==》 `43 + -27`

人为规定： `10000000`   →  `-128`

## 各类型取值范围

### char 类型

1字节 8个bit位。 数值位有7个。   
有符号: -2^7^ --- 2^7^-1  ==   -2^8-1^ -- 2^8-1^ -1    →  -128 ~ 127
无符号： 0 ~ 2^8^ -1   →  0~255
不要超出该数据类型的存储范围。

### short类型

2字节  16bit
有符号: -2^15^ ~ 2^15^-1  ==  -2^16-1^ ~ 2^16-1^ -1    ==  -32768 ~ 32767
无符号： 0 ~ 2^8^ -1   ==  0~65535

### int 类型

4字节
有符号：-2^32-1^ ~ 2^32-1^-1 ==  -2147483648 ~ 2147483647
无符号：0 ~ 2^32^ -1   ==  0 ~ 4294967295

### long类型

4字节
有符号：  →  -2147483648 ~ 2147483647
无符号：0 ~ 2^32^ -1   ==  0 ~ 4294967295

### longlong 类型

8字节
有符号：  →  -2^63^  ~  2^63^-1
无符号：  →  0 ~ 2^63^-1


# Day03_运算符和分支循环语句

## extern

表示声明。 没有内存空间。 不能提升。

## const

限定一个变量为只读变量。

## volatile

防止编译器优化代码。
`volatile int flg = 0; `

## register

定义一个寄存器变量。没有内存地址。
`register int a = 10;`

## 字符串

C语言中，用双引号引着的一串字符，称之为字符串。一定有一个结束标记`'\0'`
`char ch = ‘A’;`  一个字节
`"abc"`  --> `'a''b''c''\0'`
`‘a’` 不等价` “a”`（`'a''\0'`）

## printf函数

`%s`：打印字符串， 挨着从字符串的第一个字符开始打印，打印到'\0'结束。
`%d`：打印整数
`%c`：打印字符
`%x`：打印16进制数
`%u`：打印无符号
`%m.n`: 打印实型时用到，一共有 m 位(整数、小数、小数点)，n位小数。
`%0m.nf`: 其中 f：表示打印实型，一共有 m 位(整数、小数、小数点)，n位小数。 0：表示不足 m 位时，用0凑够m位。
`%%`： 显示一个%。 转义字符`'\'` 对 % 转义无效。
`%Ns`：显示N个字符的字符串。不足N用空格向左填充。
`%0Ns`：显示N个字符的字符串。不足N用0向左填充。
`%-Ns`：显示N个字符的字符串。不足N用空格向右填充。

## putchar函数

输出一个 字符 到屏幕。直接使用 ASCII 码。不能输出字符串。
`‘abc’`既不是一个有效字符，也不是一个有效字符串。
常用`putchar('\n');`来打印换行。
`printf("\n");`

## scanf函数

从键盘接收用户输入。

1. 接收 整数 `%d`
   `int a, b, c;`  创建变量空间， 等待接收用户输入。
   `scanf("%d %d %d", &a, &b, &c);`

2. 接收 字符 	`%c`
   `char a, b, c;`
   `scanf("%c %c %c", &a, &b, &c);`

3. 接收 字符串 `%s`
   `char str[10];`// 定义一个数组，用来接收用户输入的 字符串。
   `scanf("%s", str);`// 变量名要取地址传递给 scanf， 数组名本身表示地址，不用 & 符。

接收字符串：
1） scanf 具有安全隐患。如果存储空间不足，数据能存储到内存中，但不被保护。【空间不足不要使用】
2） scanf 函数接收字符串时， 碰到 空格 和 换行 会自动终止。不能使用 scanf 的 `%s` 接收带有空格的字符串。

## 解决scanf 4996错误

将 `#define _CRT_SECURE_NO_WARNINGS`  添加到程序 第一行。 

## getchar()函数

从键盘获取用户输入的 一个字符,返回该获取的字符的 ASCII 码。


## 算数运算符

先 * / % 后 + -
除法运算后，得到的结果赋值给整型变量时，取整数部分。
除0 ：错误操作。不允许。
对0取余：错误操作。不允许。
不允许对小数取余。余数不能是 小数。 `35 % 3.4;`
对负数取余，结果为余数的绝对值。`10 % -3;`  --》 `1`

## ++ 和 --

前缀自增、自减：先自增/自减， 在取值。

```c
int a = 10;
++a;	// a = a+1;
```

后缀自增、自减:先取值， 再自增/自减。

```c
int a  = 10;
a++;	// a = a+1;
```

## 赋值运算

```c
int a = 5;
a += 10; 	 // a = a+10;
a -= 30;  	// a = a-30;
a %= 5;  	// a = a % 5;
```

## 比较运算符

== 判等
!= 不等于
< 小于
<= 小于等于

> 大于
> = 大于等于

`13 < var < 16;` ==> `var > 13 && var < 16;`

## 逻辑运算符

0为假，非0为真。（1）
逻辑非：!
非真为假， 非假为真。
逻辑与： &&（并且）
同真为真，其余为假。
逻辑或：|| （或）

有真为真。同假为假。

## 运算符优先级

[]() > ++ -- (后缀高于前缀) (强转) sizeof > 算数运算（先乘除取余，后加减）> 比较运算 > 逻辑运算 > 三目运算（条件运算）> 赋值运算 > 逗号运算

## 三目运算符： ? :

`表达式1 ？ 表达式2 : 表达式3`
表达式1 是一个判别表达式。 如果为真。整个三目运算，取值表达式2。如果为假。整个三目运算，取值表达式3。
默认结合性。自右向左。

## 类型转换

### 隐式类型转换：由编译器自动完成。

由赋值产生的类型转换。 小--》大 没问题。 大 --》 小 有可能发生数据丢失。

```c
int r = 3;
float s = 3.14 * r * r;
```

### 强制类型转换：

语法：`（目标类型）待转换变量`
`（目标类型）待转换表达式`
大多数用于函数调用期间，实参给形参传值。

## if分支语句

匹配一个范围.属于模糊匹配.

```c
if (判别表达式1)
{
	判别表达式为真，执行代码。
}
else if(判别表达式2)
{
	判别表达式1为假，并且判别表达式2，执行代码。
}
else if(判别表达式3)
{
	判别表达式1为假，判别表达式2为假，判别表达式3， 执行代码。
}
...
else
{
	以上所有判断表达式都为假， 执行代码。
}
```

### 练习

三只小猪称体重：屏幕输入三只小猪的重量。借助if分支语句，找出最重的小猪重量。

```c
#include <stdio.h>

void threepigs(void){
    double a, b, c;

    printf("请输入小猪的体重，输入完成后按回车结束。\n注意：共需输入三次，只需输入数字部分、无需输入单位（系统默认单位为kg）。\n");
    scanf("%lf",&a);
    scanf("%lf",&b);
    scanf("%lf",&c);

    if(a < b){
        if(b < c){
            printf("第三只小猪最重，它的体重是%.2fkg，其余两只小猪体重分别为：%.2fkg、%.2fkg。", c, a, b);
        } else{
            printf("第二只小猪最重，它的体重是%.2fkg，其余两只小猪体重分别为：%.2fkg、%.2fkg。", b, a, c);
        }
    } else if(a > c){
        printf("第一只小猪最重，它的体重是%.2fkg，其余两只小猪体重分别为：%.2f、%.2fkg。", a, b, c);
    } else{
        printf("第三只小猪最重，它的体重是%.2fkg，其余两只小猪体重分别为：%.2fkg、%.2fkg。", c, a, b);
    }
}

int main() {

    threepigs();      

    return 0;
}
```




## switch 分支

精确匹配

```c
switch(判别表达式)
{
  case 1：
  执行语句1；
  break;// 防止case穿透

  case 2:
  执行语句2;
  break;

  case 3:
  执行语句3;
  break;
  ...

  case N:
  执行语句N;
  break;

  default:
  其他情况的统一处理;
  break;
}
```

### case 穿透

在一个case分支中如果,没有break;那么它会向下继续执行下一个case分支.

## while循环

```c
while(条件判别表达式)
{
  循环体
}
```

### 练习

敲7：1--100数数， 逢7和7的倍数，敲桌子。
7的倍数：`num % 7 == 0`
个位含7：`num % 10 == 7`
十位含7：`num / 10 == 7`

```c
#include <stdio.h>

void miss_7(void){
    int i = 1;

    while (i < 101){
        if(i % 7 == 0){
            printf("敲桌子\n");
        } else if (i / 10 == 7){
            printf("敲桌子\n");
        } else if (i % 10 == 7){
            printf("敲桌子\n");
        } else{
            printf("%d\n", i);
        }
        i++;
    }
}

int main() {

    miss_7();         

    return 0;
}
```



## do while 循环

无论如何先执行循环体一次。然后在判断是否继续循环。

```c
do {
  循环体
} while (条件判别表达式);
```

### 练习

求水仙花数: 一个三位数(100 -- 999)。各个位上的数字的立方和等于本数字。
个位数：` int a = num % 10;`   `a*a*a;`
十位数：` int b = num / 10 % 10;` 
百位数： `int c = num / 100;`

```c
#include <stdio.h>

void shuixianhua(void){
    int j,k,l;

    for (int i = 0; i < 1000; ++i) {
        j = i / 100;
        k = i / 10 % 10;
        l = i % 10;

        if (i == j*j*j + k*k*k + l*l*l){
            printf("%d是水仙花数！\n", i);
        }
    }
}

int main() {

    shuixianhua();    

    return 0;
}
```

# Day05_二维数组、字符串、函数

## 二维数组

```c
int arr[10] = {1,2,3,5,6,7};
{1,2,3,5,6,7};
{1,2,3,5,6,7};
{1,2,3,5,6,7};
{1,2,3,5,6,7};
```



### 定义语法

```c
int arr[2][3] = 
{
  {2, 5, 8},
  {7, 9 10}
};
```

```c
int arr[3][5] = {{2, 3, 54, 56, 7 }, {2, 67, 4, 35, 9}, {1, 4, 16, 3, 78}};
```

### 打印

```c
for(i = 0; i < 3; i++)// 行
{
  for(j = 0; j <5; j++)   // 列
  {
    printf("%d ", arr[i][j]);
  }
  printf("\n");
}
```

### 大小

数组大小: `sizeof(arr);`
一行大小: `sizeof(arr[0]);` 二维数组的一行，就是一个一维数组。
一个元素大小:`sizeof(arr[0][0])`单位：字节
行数：`row = sizeof(arr)/ sizeof(arr[0])`
列数：`col = sizeof(arr[0])/ sizeof(arr[0][0])`

### 地址合一

`printf("%p\n", arr);` == `printf("%p\n", &arr[0][0]);` == `printf("%p\n", arr[0]);`
数组的首地址 == 数组的首元素地址 == 数组的首行地址。

### 二维数组的初始化

1）常规初始化：

```c
int arr[3][5] = {{2, 3, 54, 56, 7 }, {2, 67, 4, 35, 9}, {1, 4, 16, 3, 78}};
```

2) 不完全初始化：

```c
int arr[3][5] = {{2, 3}, {2, 67, 4, }, {1, 4, 16, 78}};  // 未被初始化的数值为 0 
int arr[3][5] = {0};		// 初始化一个 初值全为0的二维数组
int arr[3][5] = {2, 3, 2, 67, 4, 1, 4, 16, 78};   // 【少见】 系统自动分配行列。
```

3）不完全指定行列初始化：

```c
int arr[][] = {1, 3, 4, 6, 7};  // 二维数组定义必须指定列值。
int arr[][2] = { 1, 3, 4, 6, 7 };  // 可以不指定行值。
```

### 练习

求出5名学生3门功课的总成绩。（一个学生的总成绩。一门功课的总成绩）

```c
int scores[5][3];

int row = sizeof(scores) / sizeof(scores[0]);
int col = sizeof(scores[0]) / sizeof(scores[0][0]);

// 获取 5 名学生、3门功课成绩
for (size_t i = 0; i < row; i++)
{
	for (size_t j = 0; j < col; j++)
	{
		scanf("%d", &scores[i][j]);
	}
}

// 求一个学生的总成绩
for (size_t i = 0; i < row; i++) // 每个学
{
	int sum = 0;
	for (size_t j = 0; j < col; j++)// 每个学生的成绩
	{
		sum += scores[i][j];
	}
	printf("第%d个学生的总成绩为：%d\n", i+1, sum);
}

//求一门功课的总成绩
for (size_t i = 0; i < col; i++)  // 第几门功课
{
	int sum = 0;
	for (size_t j = 0; j < row; j++)  // 每门功课的第几个学生
	{
		sum += scores[j][i];
	}
	printf("第%d门功课的总成绩为：%d\n", i + 1, sum);
}
```

## 快捷导入代码

VS  →  工具  →  代码片段管理器  →  Visual C++

## 多维数组：【了解】

三维数组：`[层][行][列]`
`数组类型 数组名[层][行][列];`

```c
int arr[3][3][4];
{ {12, 3, 4, 5}
  {12, 3, 4, 5} },
{ {12, 3, 4, 5}
  {12, 3, 4, 5} },
{ {12, 3, 4, 5}
  {12, 3, 4, 5} },
```

```c
for(i = 0; i < 3; i++)  层
for (j = 0; j < 3; j++)  行
for (k = 0; k<4; k++)  列
printf("%d ", arr[i][j][k]);
```

4维、5维、6维。。。N维。

```c
int arr[10];
short arr[20];
long long arr[20];
```

## 字符数组 和 字符串区别：

字符数组： 
`char str[5] = {'h', 'e', 'l', 'l', 'o'};`

字符串：
`char str[6] = {'h', 'e', 'l', 'l', 'o', '\0'};`
`char str[6] = "hello";`

`printf("%s");`使用printf打印字符串的时候，必须碰到 \0 结束。

### 练习

键盘输入字符串，存至str[]中，统计每个字母出现的次数。

```c
for (size_t i = 0; i < 10; i++)
{
	scanf("%c", &str[i]);
}

int count[26] = {0};  // 代表26个英文字母出现的次数。 

for (size_t i = 0; i < 11; i++)
{
  int index = str[i] - 'a';// 用户输入的字符在 count数组中的下标值。
  count[index]++;
}

for (size_t i = 0; i < 26; i++)
{
  if (count[i] != 0)
  {
    printf("%c字符在字符串中出现 %d 次\n", i+'a', count[i]);
  }
}
```

## 字符串获取 scanf

注意：
1）用于存储字符串的空间必须足够大，防止溢出。 `char str[5];`

2) 获取字符串，`%s`， 遇到空格 和 `\n` 终止。

借助“正则表达式”, 获取带有空格的字符串：`scanf("%[^\n]", str);`

## 字符串操作函数

`gets`： 从键盘获取一个字符串， 返回字符串的首地址。 可以获取带有 空格的字符串。 【不安全】

```c
char *gets(char *s);
```

参数：用来存储字符串的空间地址。
返回值：返回实际获取到的字符串首地址。

`fgets`: 从`stdin`获取一个字符串， 预留 `\0` 的存储空间。空间足够读 `\n`, 空间不足舍弃 `\n`  【安全】

```c
char *fgets(char *s, int size, FILE *stream);
```

参1：用来存储字符串的空间地址。
参2：描述空间的大小。
参3：读取字符串的位置。键盘  →  标准输入：stdin
返回值：返回实际获取到的字符串首地址。

`puts`：将一个字符串写出到屏幕. `printf("%s", "hello");`  /  `printf("hello\n");`  /  `puts("hello");`   输出字符串后会自动添加 `\n` 换行符。

```c
int puts(const char *s);
```

参1：待写出到屏幕的字符串。
返回值： 成功：非负数 0。 失败： -1.

`fputs`：将一个字符串写出到`stdout`.输出字符串后， 不添加 `\n` 换行符。

```c
int fputs(const char * str, FILE * stream);
```

参1：待写出到屏幕的字符串。屏幕 --》标准输出： `stdout`
参数：写出位置 `stdout`
返回值： 成功：0。 失败： -1.

`strlen`: 碰到 \0 结束。

```c
size_t strlen(const char *s);
```

参1： 待求长度的字符串
返回：有效的字符个数。

### 练习

字符串追加，将两个字符串拼接形成一个新的字符串

```c
char str1[] = "hello";
char str2[] = "world";

char str3[100] = {0};

int i = 0;// 循环 str1
while (str1[i] != '\0')
{
  str3[i] = str1[i];  // 循环着将str1中的每一个元素，交给str3
  i++;
}// str3=[h e l l o]
//printf("%d\n", i);  --> 5

int j = 0;// 循环 str2
while (str2[j]) // 等价于 while(str2[j] !='\0') 等价于 while (str2[j] != 0)
{
  str3[i+j] = str2[j];
  j++;
}// str3=[h e l l o w o r l d]

// 手动添加 \0 字符串结束标记
str3[i + j] = '\0';
```

## 函数的作用

1. 提高代码的复用率
2. 提高程序模块化组织性。

## 函数分类

系统库函数： 标准C库。 libc

1. 引入头文件 --- 声明函数
2. 根据函数原型调用。

### 用户自定义:

除了需要提供函数原型之外，还需要提供函数实现。

### 随机数：

1. 播种随机数种子： `srand(time(NULL));`
2. 引入头文件 `#include <stdlib.h>  <time.h>`
3. 生成随机数： `rand() % 100;`

### 函数定义：

包含 函数原型（返回值类型、函数名、形参列表） 和 函数体（大括号一对， 具体代码实现）
形参列表： 形式参数列表。一定包 类型名 形参名。

```c
int add（int a, int b, int c）
{
	return a+b+c;
}

int test(char ch, short b, int arr[], int m)
```

### 函数调用：

包含 函数名(实参列表);  

```c
int ret = add(10, 4, 28);
```

实参(实际参数)： 在调用是，传参必须严格按照形参填充。（参数的个数、类型、顺序）  没有类型描述符

```c
int arr[] = {1, 3, 6};
```

## 函数声明

包含 函数原型（返回值类型、函数名、形参列表） + “;”
要求 在函数调用之前，编译必须见过函数定义。否则，需要函数声明。

```c
int add（int a, int b, int c）；
```

### 隐式声明：【不要依赖】

默认编译器做隐式声明函数时，返回都为 int ，根据调用语句不全函数名和形参列表。

```c
#include <xxx.h> // --> 包含函数的声明
```

## exit函数

```c
#include <stdlib.h>
```

## return关键字

返回当前函数调用，将返回值返回给调用者。

## exit()函数

退出当前程序。

## 多文件编程

将多个含有不同函数功能 .c 文件模块，编译到一起，生成一个 .exe文件。
`<>`包裹的头文件为系统库头文件。
`""`包裹的头文件为用户自定义头文件。

防止头文件重复包含：头文件守卫。
1） `#pragma once`--- windows中
2）head.h

```c
#ifndef __HEAD_H__
#define __HEAD_H__
.... 头文件内容
#endif
```


# Day06_指针基础

## 指针和内存单元

指针： 地址。
内存单元： 计算机中内存最小的存储单位。――内存单元。大小一个字节。 每一个内存单元都有一个唯一的编号（数）。称这个内存单元的编号为 “地址”。
指针变量：存地址的变量。

## 指针定义和使用

```c
int a = 10;
int *p = &a;int* p;				// --- windows;int *p     ---Linux   int * p ;
int a, *p, *q, b;
*p = 250;			// 指针的 解引用。 间接引用。
*p			// ： 将p变量的内容取出，当成地址看待，找到该地址对应的内存空间。
```

如果做左值： 存数据到空间中。
如果做右值： 取出空间中的内容。

### 任意“指针”类型大小

指针的大小与类型 无关。 只与当前使用的平台架构有关。   32位：4字节。 64位： 8字节。

## 野指针

1) 没有一个有效的地址空间的指针。

```c
int *p;
*p = 1000;
```

2）p变量有一个值，但该值不是可访问的内存区域。

```c
int *p = 10;
*p = 2000;
```

【杜绝野指针】

## 空指针

```c
int *p = NULL;     
#define NULL ((void *)0)
```

`*p` 时 p所对应的存储空间一定是一个 无效的访问区域。

## 万能指针/泛型指针（void *）

可以接收任意一种变量地址。但是，在使用【必须】借助“强转”具体化数据类型。

```
char ch = 'R';
void *p;  // 万能指针、泛型指针
p = &ch;
printf("%c\n", *(char *)p);
```

## const关键字

修饰变量：

```c
const int a = 20;
int *p = &a;
*p = 650;
printf("%d\n", a);
```

修饰指针：

```c
const int *p;		// 可以修改 p;不可以修改 *p。
int const *p;		// 同上。
int * const p;	// 可以修改 *p;不可以修改 p。
const int *const p;	// 不可以修改 p;不可以修改 *p。
```

总结：const 向右修饰，被修饰的部分即为只读。
常用：在函数形参内，用来限制指针所对应的内存空间为只读。

## 指针和数组

数组名： 【数组名是地址常量】 --- 不可以被赋值。 `++ / -- / += / -= / %= / /=`  (带有副作用的运算符)
指针是变量。可以用数组名给指针赋值。 ++ -- 

### 取数组元素

```c
int arr[] = {1,3, 5, 7, 8};
int *p = arr;  
arr[i] == *(arr+0) == p[0] == *(p+0)
```

### 指针和数组区别

1. 指针是变量。数组名为常量。
2. `sizeof(指针)`  →  4字节 / 8字节
   `sizeof(数组)`  →  数组的实际字节数。

### 指针++ 操作数组

```c
int arr[] = { 1, 2, 4, 5, 6, 7, 8, 9, 0 };
int *p = arr;

for (size_t i = 0; i < n; i++)
{
  printf("%d ", *p);
  p++;  // p = p+1;   一次加过一个int大小。 一个元素。
}
```

p的值会随着循环不断变化。打印结束后，p指向一块无效地址空间(野指针)。

## 指针加减运算

### 数据类型对指针的作用

1）间接引用：
决定了从指针存储的地址开始，向后读取的字节数。  （与指针本身存储空间无关。）
2）加减运算：
决定了指针进行 +1/-1 操作向后加过的 字节数。

`指针 * / %` ： error!!!

### 指针 +- 整数：

1) 普通指针变量+-整数

```c
char *p;		// 打印 p 、 p+1  偏过 1 字节。
short*p;		// 打印 p 、 p+1  偏过 2 字节。
int  *p;		// 打印 p 、 p+1  偏过 4 字节。
```

2）在数组中+- 整数

```c
short arr[] = {1, 3, 5, 8};
int *p = arr;
p+3;// 向右(后)偏过 3 个元素
p-2;// 向前(左)偏过 2 个元素
```

3）&数组名 + 1
加过一个 数组的大小（数组元素个数 x sizeof（数组元素类型））

### 指针 +- 指针：

`指针 + 指针`： error！！！
`指针 - 指针`：
1） 普通变量来说， 语法允许。无实际意义。【了解】
2） 数组来说：偏移过的元素个数。

## 指针实现 strlen 函数

```c
char str[] = "hello";
char *p = str;

while (*p != '\0')
{
	p++;
}

p-str; 	// 即为 数组有效元素的个数。
```

## 指针比较运算

1） 普通变量来说， 语法允许。无实际意义。
2） 数组来说：地址之间可以进行比较大小。
可以得到，元素存储的先后顺序。

3） 

```c
int *p;
p = NULL;// 这两行等价于： int *p = NULL;
if (p != NULL)
printf(" p is not NULL");
else 
printf(" p is NULL");
```

## 指针数组

一个存储地址的数组。数组内部所有元素都是地址。

1) 

```c
int a = 10;
int b = 20;
int c = 30;

int *arr[] = {&a, &b, &c}; // 数组元素为 整型变量 地址
```

2) 

```c
int a[] = { 10 };
int b[] = { 20 };
int c[] = { 30 };

int *arr[] = { a, b, c }; // 数组元素为 数组 地址。
```

指针数组本质，是一个二级指针。
二维数组， 也是一个二级指针。

## 多级指针

```c
int a = 0;
int *p = &a;					// 一级指针是 变量的地址。
int **pp = &p;				// 二级指针是 一级指针的地址。
int ***ppp = &pp;			// 三级指针是 二级指针的地址。
int ****pppp = &ppp;	// 四级指针是 三级指针的地址。【了解】
......
```

多级指针，不能  跳跃定义！

对应关系：

```c
ppp == &pp;									// 三级指针
*ppp == pp == &p; 					// 二级指针
**ppp == *pp == p == &a			// 一级指针
***ppp == **pp == *p == a		// 普通整型变量
```

`*p` ： 将p变量的内容取出，当成地址看待，找到该地址对应的内存空间。
如果做左值： 存数据到空间中。
如果做右值： 取出空间中的内容。


# Day07_指针和字符串

## 指针和函数

### 栈帧

当函数调用时，系统会在 stack 空间上申请一块内存区域，用来供函数调用，主要存放 形参 和 局部变量（定义在函数内部）。

当函数调用结束，这块内存区域自动被释放（消失）。


### 传值和传址

传值：函数调用期间，实参将自己的值，拷贝一份给形参。 
传址：函数调用期间，实参将地址值，拷贝一份给形参。 【重点】
		（地址值  →   在swap函数栈帧内部，修改了main函数栈帧内部的局部变量值）

###指针做函数参数

```c
int swap2(int *a, int *b);
int swap2(char *a, char *b);
```

调用时，传有效的地址值。

### 数组做函数参数

```c
void BubbleSort(int arr[10]) == void BubbleSort(int arr[])  == void BubbleSort(int *arr) 
```

传递不再是整个数组，而是数组的首地址（一个指针）。
所以，当整型数组做函数参数时，我们通常在函数定义中，封装2个参数。一个表数组首地址，一个表元素个数。

### 指针做函数返回值

```c
int *test_func(int a, int b);
```

指针做函数返回值，不能返回【局部变量的地址值】。

### 数组做函数返回值

C语言，不允许！！！！  只能写成指针形式。

## 指针和字符串

1）

```c
char str1[] = {'h', 'i', '\0'};		// 变量，可读可写
char str2[] = "hi";		// 变量，可读可写
char *str3 = "hi";		// 常量，只读
```

str3变量中，存储的是字符串常量“hi”中首个字符‘h’的地址值。

```c
str3[1] = 'H';		// 错误！！
char *str4 = {'h', 'i', '\0'};		// 错误！！！
```

2）
当字符串（字符数组）， 做函数参数时， 不需要提供2个参数。 因为每个字符串都有 '\0'。

## 练习：比较两个字符串

`strcmp();`实现
比较 str1 和 str2， 如果相同返回0， 不同则依次比较ASCII码，str1 > str2 返回1，否则返回-1

数组方式：

```c
int mystrcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] == str2[i])   // *(str1+i) == *(str2+i)
	{
		if (str1[i] == '\0')
		{
			return 0;// 2字符串一样。
		}
		i++;
	}
	return str1[i] > str2[i] ? 1 : -1;
}
```

指针方式：

```c
int mystrcmp2(char *str1, char *str2)
{
	while (*str1 == *str2)   // *(str1+i) == *(str2+i)
	{
		if (*str1 == '\0')
		{
			return 0;		// 2字符串一样。
		}
		str1++;
		str2++;
	}
	return *str1 > *str2 ? 1 : -1;
}
```

## 练习：字符串拷贝

```c
//数组版本
void mystrcpy(char *src, char *dst)
{
	int i = 0;
	while (src[i] != 0)  // src[i] == *(src+i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
```

```c
//指针版
void mystrcpy2(char *src, char *dst)
{
	while (*src != '\0')  // src[i] == *(src+i)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
}
```

## 练习：在字符串中查找字符出现的位置：

```c
char *myStrch(char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
		{
			return str;
		}
		str++;
	}
	return NULL;
}
// hellowrld --- 'o'
char *myStrch2(char *str, char ch)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == ch)
		{
			return &str[i];  
		}
		i++;
	}
	return NULL;
}
```

## 练 习：字符串去空格

```c
void str_no_space(char *src, char *dst)
{
	int i = 0;   // 遍历字符串src
	int j = 0; // 记录dst存储位置
	while (src[i] != 0)
	{
		if (src[i] != ' ')
		{
			dst[j] = src[i];
			j++;
		}
		i++;
	}
	dst[j] = '\0';
}
// 指针版
void str_no_space2(char *src, char *dst)
{
	while (*src != 0)
	{
		if (*src != ' ')
		{
			*dst = *src;
			dst++;
		}
		src++;
	}
	*dst = '\0';
}
```

## 带参数的main函数

无参main函数：` int main(void) == int main()`

带参数的main函数：` int main(int argc, char *argv[]) == int main(int argc, char **argv)`
参1：表示给main函数传递的参数的总个数。
参2：是一个数组！数组的每一个元素都是字符串 char * 

测试1： 
命令行中的中，使用gcc编译生成 可执行文件，如：` test.exe`
`test.exe abc xyz zhangsan nichousha `
命令解释：
`argc` --- 5
`test.exe` -- argv[0]
`abc` -- argv[1]
`xyz` -- argv[2]
`zhangsan` -- argv[3]
`nichousha` -- argv[4]

测试2：
在VS中。项目名称上  →  右键  →  属性  →  调试  →  命令行参数  →  将 `test.exe abc xyz zhangsan nichousha` 写入。
命令解释：
`argc` --- 5
`test.exe` -- argv[0]
`abc` -- argv[1]
`xyz` -- argv[2]
`zhangsan` -- argv[3]
`nichousha` -- argv[4]

str 中 substr 出现次数：
`strstr`函数： 在 str中，找substr出现的位置。

```c
char *strstr(char *str, char *substr)   // -- #include <string.h>
```

参1： 原串
参2： 子串
返回值： 子串在原串中的位置。（地址值）；如果没有： NULL

实 现：

```c
int str_times(char *str, char *substr)
{
	int count = 0;
	char *p = strstr(str, substr);  // "llollollo"

	while (p != NULL)
	{
		count++;
		p += strlen(substr);// p = p+strlen(substr) --> "llollo"
		p = strstr(p, substr);// 返回： "llo"
	}
	return count;
}
```


# Day08_字符串和内存

## 求非空字符串元素个数

```c
“ni chou sha chou ni za di”  
```

实现：

```c

```



## 字符串逆置： str_inverse

```c
hello -- olleh 
```

```c
void str_inserse(char *str)
{
	char *start = str;		// 记录首元素地址
	char *end = str + strlen(str) - 1;		// 记录最后一个元素地址。

	while (start < end)		// 首元素地址是否 < 最后一个元素地址
	{
		char tmp = *start;		// 三杯水 char 元素交换
		*start = *end;
		*end = tmp;
		start++;		// 首元素对应指针后移
		end--;		// 尾元素对应指针前移
	}
}
```

## 判断字符串是回文

```c
int str_abcbb(char *str)
{
	char *start = str;		// 记录首元素地址
	char *end = str + strlen(str) - 1;		// 记录最后一个元素地址。

	while (start < end)		// 首元素地址是否 < 最后一个元素地址
	{
		if (*start != *end)		// 判断字符是否一致。
		{
			return 0; 		// 0 表示非 回文
		}
		start++;
		end--;
	}
	return 1;		// 1 表示 回文
}
```

## 字符串处理函数：`#include <string.h>`

### 字符串拷贝：

`strcpy()`:
将 src 的内容，拷贝给 dest。 返回 dest。 保证dest空间足够大。【不安全】

```c
char *strcpy(char *dest, const char *src);
```

函数调用结束 返回值和 dest参数结果一致。

`strncpy()`:
将 src 的内容，拷贝给 dest。只拷贝 n 个字节。 通常 n 与dest对应的空间一致。 
默认 不添加 ‘\0’

```c
char *strncpy(char *dest, const char *src, size_t n);
```

特性： n > src: 只拷贝 src 的大小
     n < src: 只拷贝 n 字节大小。 不添加 ‘\0’

### 字符串拼接：

`strcat()`:
将 src 的内容，拼接到 dest 后。 返回拼接后的字符串。保证 dest 空间足够大。

```c
char *strcat(char *dest, const char *src);
```

`strncat()`：
将 src 的前 n 个字符，拼接到 dest 后。 形成一个新的字符串。保证 dest 空间足够大。

```c
char *strncat(char *dest, const char *src, size_t n);
```

函数调用结束 返回值和 dest 参数结果一致。


### 字符串比较：

不能使用 > < >= <= == != 

`strcmp()`:
比较s1和s2两个字符串，如果相等 返回0.如果不相等，进一步表 s1 和 s2 对应位 ASCII码值。
s1 > s2 返回1
s1 < s2 返回-1

```c
int strcmp(const char *s1, const char *s2);
```

`strncmp()`:

```c
int strncmp(const char *s1, const char *s2, size_t n);
```

比较s1和s2两个字符串的前n个字符，
如果相等 返回0。如果不相等，进一步表 s1 和 s2 对应位 ASCII码值。（不比字符串ASCII码的和）
s1 > s2 返回1
s1 < s2 返回-1

### 字符串格式化输入、输出：

`sprintf()`:  s -- string

```c
int sprintf(char *str, const char *format, ...);
```

对应printf，将原来写到屏幕的“格式化字符串”，写到 参数1 str中。

```c
printf("%d+%d=%d\n", 10, 24, 10+24);
```

---》 

```c
char str[100];
sprintf(str, "%d+%d=%d\n", 10, 24, 10+24);  // 格式串写入str数组中。
```

`sscanf()`:

```c
int sscanf(const char *str, const char *format, ...);
```

对应scanf， 将原来从屏幕获取的“格式化字符串”， 从 参数1 str中 获取。

```c
scanf("%d+%d=%d", &a, &b, &c);
```

---》

```c
char str[]= "10+24=45";
sscanf(str, "%d+%d=%d", &a, &b, &c);  a --> 10, b --> 24, c --> 45
```

### 字符串查找字符、子串：

`strchr()`:
在字符串str中 找一个字符出现的位置。 返回字符在字符串中的地址。

```c
char *strchr(const char *s, int c);
printf("%s\n" strchr("hehehahahoho", 'a'));  --> "ahahoho"
```

`strrchr()`:
自右向左，在字符串str中 找一个字符出现的位置。 返回字符在字符串中的地址。

```c
char *strrchr(const char *s, int c);
printf("%s\n" strrchr("hehehahahoho", 'a'));  --> "ahoho"
```

`strstr()`:
在字符串str中，找子串substr第一次出现的位置。返回地址。

```c
char *strstr(const char *str, const char *substr);
```

### 在字符串中找子串的位置

```c
printf("%s\n" strrchr("hehehahahoho", "ho"));  // --> "hoho"
printf("%s\n" strrchr("hehehahahoho", "xixi"));  // --> NULL
scanf("%s", str);
scanf("%[^\n]", str);
```

## 字符串分割

`strtok()`: 按照既定的分割符，来拆分字符串。`“www.baidu.com”`  --> `"www\0baidu.com"`

```c
char *strtok(char *str, const char *delim);
```

参1： 待拆分字符串
参2： 分割符组成的“分割串”
返回：字符串拆分后的首地址。 “拆分”:将分割字符用 '\0'替换。
特性：
1）strtok拆分字符串是直接在 原串 上操作，所以要求参1必须，可读可写（`char *str = "www.baidu.com" `不行！！！）
2）第一次拆分，参1 传待拆分的原串。第1+ 次拆分时，参1传 NULL.

### 练习： 拆分 ".itcast.cn$This is a strtok$test"

```c
char str[] = "www.itcast.cn$This is a strtok$test";

char *p = strtok(str， "$ .");

while (p != NULL)
{
	p = strtok(NULL, " .$");
	printf("p = %s\n", p);
}
```

## atoi/atof/atol

使用这类函数进行转换，要求，原串必须是可转换的字符串。
错误使用：`"abc123"` --> `0`;`"12abc345"` ---> `12`;  `"123xyz"` -->`123`

`atoi`：字符串 转 整数。

```c
int atoi(const char *nptr);
```

`atof`：字符串 转 浮点数

`atol`：字符串 转 长整数

## 局部变量

概念：定义在函数 内 部的变量。
作用域：从定义位置开始，到包裹该变量的第一个右大括号结束。

## 全局变量

概念：定义在函数 外 部的变量。
作用域：从定义位置开始，默认到本文件内部。 其他文件如果想使用，可以通过声明方式将作用域导出。


## static全局变量

定义语法： 在全局变量定义之前添加 static 关键字。static int a = 10；
作用域：被限制在本文件内部，不允许通过声明导出到其他文件。

## static局部变量

定义语法： 在局部变量定义之前添加 static 关键字。
特性： 静态局部变量只定义一次。在全局位置。 通常用来做计数器。
作用域：从定义位置开始，到包裹该变量的第一个右大括号结束。


## 全局函数

定义语法： 函数原型 + 函数体

## static函数

定义语法：static + 函数原型 + 函数体
static 函数 只能在 本文件内部使用。 其他文件即使声明也无效。

## 生命周期

局部变量：从变量定义开始，函数调用完成。 --- 函数内部。
全局变量：程序启动开始，程序终止结束。  --- 程序执行期间。
static局部变量：程序启动开始，程序终止结束。  --- 程序执行期间。
static全局变量：程序启动开始，程序终止结束。  --- 程序执行期间。
全局函数：程序启动开始，程序终止结束。  --- 程序执行期间。
static函数：程序启动开始，程序终止结束。  --- 程序执行期间。

## 内存4区模型

代码段：`.text段`。 程序源代码（二进制形式）。
数据段：只读数据段` .rodata段`。初始化数据段 `.data段`。 未初始化数据段` .bss 段`。
`stack`：栈。 在其之上开辟 栈帧。windows 1M --- 10MLinux： 8M --- 16M
`heap`：堆。 给用户自定义数据提供空间。 约 1.3G+

### 开辟释放 heap 空间

```c
void *malloc(size_t size);		// 申请 size 大小的空间
```

返回实际申请到的内存空间首地址。 【我们通常拿来当数组用】

```c
void free(void *ptr);		// 释放申请的空间
```

参数： malloc返回的地址值。

### 使用 heap 空间

空间时连续。 当成数组使用。
free后的空间，不会立即失效。 通常将free后的 地址置为`NULL`。
free 地址必须 是 `malloc`申请地址。否则出错。
如果malloc之后的地址一定会变化，那么使用临时变量`tmp` 保存。

### 二级指针对应的 heap空间

申请外层指针： 

```c
char **p = (char **)malloc(sizeof(char *) * 5);
```

申请内层指针：

```c
for(i = 0; i < 5; i++)
{
  p[i] = (char *)malloc(sizeof(char) *10);
}
```

使用： 不能修改 p 的值。

```c
for(i = 0; i < 5; i++)
{
  strcpy(p[i], "helloheap");
}

// 释放内层：
for(i = 0; i < 5; i++)
{
free(p[i]);
}

// 释放外层：
free(p);
```


# Day09_结构体

## printf、sprintf 和 fprintf： 

变参函数：参数形参中 有“`...`”, 最后一个固参通常是格式描述串（包含格式匹配符）， 函数的参数个数、类型、顺序由这个固参决定。

```c
printf("hello");
printf("%s", "hello");
printf("ret = %d+%d\n", 10, 5);
printf("%d = %d%c%d\n", 10+5, 10, '+', 5);		// --> 屏幕

char buf[1024];		//缓冲区  
sprintf(buf, "%d = %d%c%d\n", 10+5, 10, '+', 5);		// --> buf 中

FILE * fp = fopen();
fprintf(fp, "%d = %d%c%d\n", 10+5, 10, '+', 5);		// --> fp 对应的文件中
```

## scanf、sscanf 和 fscanf

```c
scanf("%d", &m);		// 键盘 --> m

char str[] = "98";
sscanf(str, "%d", &m);str --> m

FILE * fp = fopen("r");
fscanf(fp, "%d", &m);fp指向的文件中 --> m
```

## fprintf()函数

写

```c
int fprintf(FILE * stream, const char * format, ...);
```

## fscanf()函数

读

```c
int fscanf(FILE * stream, const char * format, ...);
```

成功：正确匹配的个数。
失败： -1

1) 边界溢出。 存储读取的数据空间。在使用之前清空。
   2）fscanf函数，每次在调用时都会判断下一次调用是否匹配参数2， 如果不匹配提前结束读文件。（feof(fp) 为真）。

## 练习：文件版排序

生成随机数，写入文件。将文件内乱序随机数读出，排好序再写回文件。

fgetc --- fputc
fgets --- fputs
fprintf -- fscanf默认处理文本文件。

## fwrite()函数

既可处理以文本文件。也处理二进制文件。
写出数据到文件中。

```c
stu_t stu[4] = { ...... };
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
```

参1：待写出的数据的地址
参2：待写出数据的大小
参3：写出的个数-- 参2 x 参3 = 写出数据的总大小。
参4：文件
返回值： 成功：永远是 参3 的值。 --- 通常将参2 传 1. 将参3传实际写出字节数。
			 失败：0 

## fread()函数

从文件fp中读出数据。

```c
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
```

参1：读取到的数据存储的位置
参2：一次读取的字节数
参3：读取的次数-- 参2 x 参3 = 读出数据的总大小
参4：文件
返回值： 成功：参数3.--- 通常将参2 传 1. 将参3传欲读出的字节数。
    0：读失败 -- 到达文件结尾 -- feof(fp)为真。 

## 练习：大文件拷贝

已知一个任意类型的文件，对该文件复制，产生一个相同的新文件。

1. 打开两个文件， 一个“r”， 另一“w”
2. 从r中 fread ， fwrite到 w 文件中。
3. 判断到达文件结尾 终止。  
4. 关闭。
   注意： 在windows下，打开二进制文件（mp3、mp4、avi、jpg...）时需要使用“b”。如：“rb”、“wb”

## 随机位置 读：

文件读写指针。在一个文件内只有一个。

```c
fseek():
int fseek(FILE *stream, long offset, int whence);
```

参1：文件
参2：偏移量（矢量： + 向后， - 向前）
参3：SEEK_SET：文件开头位置
SEEK_CUR：当前位置
SEEK_END：文件结尾位置
返回值： 成功：0， 失败： -1

## ftell()

获取文件读写指针位置。

```c
long ftell(FILE *stream);
```

返回：从文件当前读写位置到起始位置的偏移量。

借助`ftell(fp)` + `fseek(fp, 0, SEEK_END);` 来获取文件大小。

## rewind()

回卷文件读写指针。 将读写指针移动到起始位置。

```c
void rewind(FILE *stream);
```

## Linux和windows文件区别

1）对于二进制文件操作， Windows 使用“b”， Linux下二进制和文本没区别。
2）windows下，回车 \r, 换行 \n。 \r\n  , Linux下 回车换行\n

3) 对文件指针，先写后读。windows和Linux效果一致。
   先读后写。Linux无需修改。windows下需要在写操作之前添加 fseek(fp, 0, SEEK_CUR); 来获取文件读写指针，使之生效。

## 获取文件状态

打开文件，对于系统而言，系统资源消耗较大。

```c
int stat(const char *path, struct stat *buf);
```

参1： 访问文件的路径
参2： 文件属性结构体
返回值： 成功： 0， 失败： -1；

## 删除、重命名文件

```c
int remove(const char *pathname); 		// 删除文件。
int rename(const char *oldpath, const char *newpath); 		// 重名文件
```

## 缓冲区刷新

标准输出-- stdout -- 标准输出缓冲区。   写给屏幕的数据，都是先存缓冲区中，由缓冲区一次性刷新到物理设备（屏幕）

标准输入 -- stdin -- 标准输入缓冲区。从键盘读取的数据，直接读到 缓冲区中， 由缓冲区给程序提供数据。

预读入、缓输出。

行缓冲：`printf();` 遇到`\n`就会将缓冲区中的数据刷新到物理设备上。

全缓冲：文件。 缓冲区存满， 数据刷新到物理设备上。

无缓冲：`perror`。 缓冲区中只要有数据，就立即刷新到物理设备。

文件关闭时， 缓冲区会被自动刷新。  隐式回收：关闭文件、刷新缓冲区、释放malloc

手动刷新缓冲区： 实时刷新。

```c
int fflush(FILE *stream);
```

成功：0
失败：-1


# Day10_文件上

## 共用体和联合体

```c
union test {
  char ch;
  short sh;
  int var;
};
```

联合体，内部所有成员变量地址一致。等同于整个联合体的地址。
联合体的大小，是内部成员变量中，最大的那个成员变量的大小。（对齐）
修改其中任意一个成员变量的值，其他成员变量会随之修改。

## 枚举

```c
enum  color { 枚举常量 };
enum  color { red, green, blue, black, pink, yellow };
```

枚举常量: 是整型常量。不能是浮点数。可以是负值。 默认初值从 0 开始，后续常量较前一个常量 +1.
可以给任意一个常量赋任意初值。后续常量较前一个常量 +1

## 读写文件与printf、scanf关联

printf -- 屏幕 -- 标准输出
scanf -- 键盘 -- 标准输入
perror -- 屏幕 -- 标准错误

系统文件：
标准输入 -- stdin -- 0
标准输出 -- stdout -- 1
标准错误 -- stderr -- 2

应用程序启动时，自动被打开，程序执行结束时，自动被关闭。 ---- 隐式回收。

1s = 1000ms 
1ms = 1000us
1us == 1000ns

## 文件指针和普通指针区别

```c
FILE *fp = NULL;
```

借助文件操作函数来改变 fp 为空、野指针的状况。`fopen();`  --> 相当于 `fp = malloc();`

操作文件， 使用文件读写函数来完成。 `fputc`、`fgetc`、`fputs`、`fgets`、`fread`、`fwrite`

## 文件分类

设备文件：
屏幕、键盘、磁盘、网卡、声卡、显卡、扬声器...

磁盘文件：

文本文件： ASCII

二进制文件：0101 二进制编码

## 文件操作一般步骤

1. 打开文件 `fopen()`  --》 `FILE *fp;`
2. 读写文件 `fputc`、`fgetc`、`fputs`、`fgets`、`fread`、`fwrite`
3. 关闭文件 `fclose()`  

## 打开、关闭文件函数

```c
FILE * fopen(const char * filename, const char * mode);
```

参1：待打开文件的文件名（访问路径）
参2：文件打开权限：
    "r": 只读方式打开文件， 文件不存在，报错。存在，以只读方式打开。
    "w": 只写方式打开文件， 文件不存在，创建一个空文件。文件如果存在，清空并打开。
    "w+":读、写方式打开文件，文件不存在，创建一个空文件。文件如果存在，清空并打开。
    "r+":读、写方式打开文件, 文件不存在，报错。存在，以读写方式打开。
    "a": 以追加的方式打开文件。
    "b": 操作的文件是一个二进制文件（Windows）
返回值：成功：返回打开文件的文件指针；失败：NULL

```c
int fclose(FILE * stream);
```

参1：打开文件的fp（fopen的返回值）
返回值：成功 ：0， 失败： -1;

## 文件访问路径

绝对路径：
从系统磁盘的 根盘符开始，找到待访问的文件路径
Windows书写方法：
1）`C:\\Users\\afei\\Desktop\\06-文件分类.avi`
2）`C:/Users/afei/Desktop/06-文件分类.avi`  --- 也使用于Linux。

相对路径：
1）如果在VS环境下，编译执行（Ctrl+F5），文件相对路径是指相对于 day10.vcxproj 所在目录位置。
2）如果是双击 xxx.exe 文件执行，文件的相对路径是相对于 xxx.exe 所在目录位置。 

## 按字符写文件 fputc

```c
int fputc(int ch, FILE * stream);
```

参1：待写入的 字符
参2：打开文件的fp（fopen的返回值）
返回值： 成功： 写入文件中的字符对应的ASCII码；失败： -1

## 练习

写26个英文字符到文件中

```c

```

## 按字符读文件 fgetc

```c
int fgetc(FILE * stream);
```

参1：待读取的文件fp（fopen的返回值）
返回值： 成功：读到的字符对应的ASCII码；失败： -1

文本文件的结束标记： EOF ---》 -1 

## feof()函数

```c
int feof(FILE * stream);
```

参1： fopen的返回值
返回值： 到达文件结尾--》非0【真】
			 没到达文件结尾--》0【假】
作用：
用来判断到达文件结尾。 既可以判断文本文件。也可以判断 二进制文件。

特性：
要想使用feof()检测文件结束标记，必须在该函数调用之前，使用读文件函数。

feof()调用之前，必须有读文件函数调用。

## fgets()函数

获取一个字符串， 以\n作为结束标记。自动添加 \0. 空间足够大 读\n, 空间不足舍弃\n, 必须有\0。

```c
char * fgets(char * str, int size, FILE * stream);

char buf[10];		// hello --> hello\n\0
```

返回值： 成功： 读到的字符串；失败： NULL

## fputs()函数

写出一个字符串，如果字符串中没有\n， 不会写\n。

```c
int fputs(const char * str, FILE * stream);
```

返回值： 成功： 0；失败： -1

## 练习

获取用户键盘输入，写入文件。假定：用户写入“:wq”终止接收用户输入，将之前的数据保存成一个文件。

```c
FILE *fp = fopen("test07.txt", "w");
if (fp == NULL)
{
	perror("fopen error");
	return -1;
}
char buf[4096] = {0};

while (1)
{
	fgets(buf, 4096, stdin);
	if (strcmp(buf, ":wq\n") == 0)		// 实际 fgets 读到的是“:wq\n”
	{
		break;
	}
	fputs(buf, fp);
}

fclose(fp);
```

## 练习

文件版四则运算

1. 封装 write_file 函数，将4则运算表达式写入。

```c
FILE * fp = fopen（"w"）;
fputs("10/4=\n", fp);
fputs("10+4=\n", fp);
....
fputs("10*4=\n", fp);
```

2. 封装 read_file 函数, 将4则运算表达式读出，拆分，运算，写回。
   1） 读出：

```c
FILE * fp = fopen（"r"）;
while （1） {
	fgets(buf, sizeof(buf), fp);		// buf中存储的 4则运算表达式
}
```

​	2） 拆分：

```c
sscanf(buf, "%d%c%d=\n", &a, &ch, &b);		// 得到运算数， 运算符
```

​	3） 根据运算符，得到运算结果

```c
switch(ch) {
  case '+':
  	a+b;
}
```

4) 拼接 结果到  运算式 上

```c
char result[1024];
sprintf(reuslt, "%d%c%d=%d\n", a, ch, b, a+b);		// reuslt 中包含带有结果的 运算式。
```

5）将 多个带有结果的运算 拼接成一个字符串。

```c
char sum_ses[4096];		// 存总的字符串  -- "10/2=5\n10*3=30\n4+3=7\n8-6=2\n"
strcat(sum_ses，reuslt);		// 在while中循环拼接
```

6) 重新打开文件， 清空原有 4则运算表达式

```c
fclose(fp);
fp = fopen（"w"）;
```

7) 将 拼接成一个字符串。写入到空的文件中

```c
fputs（sum_res）;
```


# Day11_文件下

## printf、sprintf 和 fprintf： 

变参函数：参数形参中 有“...”, 最后一个固参通常是格式描述串（包含格式匹配符）， 函数的参数个数、类型、顺序由这个固参决定。

```c
printf("hello");
printf("%s", "hello");
printf("ret = %d+%d\n", 10, 5);
printf("%d = %d%c%d\n", 10+5, 10, '+', 5);		// --> 屏幕

char buf[1024];   //缓冲区  
sprintf(buf, "%d = %d%c%d\n", 10+5, 10, '+', 5);		// --> buf 中

FILE * fp = fopen();
fprintf(fp, "%d = %d%c%d\n", 10+5, 10, '+', 5);		// --> fp 对应的文件中
```

## scanf、sscanf 和 fscanf

```c
scanf("%d", &m);键盘 --> m

char str[] = "98";
sscanf(str, "%d", &m);str --> m

FILE * fp = fopen("r");
fscanf(fp, "%d", &m);fp指向的文件中 --> m
```

## fprintf()函数

写

```c
int fprintf(FILE * stream, const char * format, ...);
```

## fscanf()函数

读

```c
int fscanf(FILE * stream, const char * format, ...);
```

成功：正确匹配的个数。失败： -1

1) 边界溢出。 存储读取的数据空间。在使用之前清空。
   2）fscanf函数，每次在调用时都会判断下一次调用是否匹配参数2， 如果不匹配提前结束读文件。（feof(fp) 为真）。

##  练习

文件版排序：生成随机数，写入文件。将文件内乱序随机数读出，排好序再写回文件。

fgetc --- fputc
fgets --- fputs
fprintf -- fscanf默认处理文本文件。

## fwrite()函数

既可处理以文本文件。也处理二进制文件。
写出数据到文件中。

```c
stu_t stu[4] = { ...... };
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
```

参1：待写出的数据的地址
参2：待写出数据的大小
参3：写出的个数-- 参2 x 参3 = 写出数据的总大小。
参4：文件
返回值： 成功：永远是 参3 的值。 --- 通常将参2 传 1. 将参3传实际写出字节数。
失败：0 

## fread()函数：

从文件fp中读出数据。

```c
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
```

参1：读取到的数据存储的位置
参2：一次读取的字节数
参3：读取的次数-- 参2 x 参3 = 读出数据的总大小
参4：文件
返回值： 成功：参数3.--- 通常将参2 传 1. 将参3传欲读出的字节数。
 0：读失败 -- 到达文件结尾 -- feof(fp)为真。 

## 练习

大文件拷贝：已知一个任意类型的文件，对该文件复制，产生一个相同的新文件。

1. 打开两个文件， 一个“r”， 另一“w”
2. 从r中 fread ， fwrite到 w 文件中。
3. 判断到达文件结尾 终止。  
4. 关闭。

注意： 在windows下，打开二进制文件（mp3、mp4、avi、jpg...）时需要使用“b”。如：“rb”、“wb”

## 随机位置 读：

文件读写指针。在一个文件内只有一个。

### fseek()

```c
int fseek(FILE *stream, long offset, int whence);
```

参1：文件
参2：偏移量（矢量： + 向后， - 向前）
参3：SEEK_SET：文件开头位置
SEEK_CUR：当前位置
SEEK_END：文件结尾位置
返回值： 成功：0， 失败： -1

### ftell()

获取文件读写指针位置。

```c
long ftell(FILE *stream);
```

返回：从文件当前读写位置到起始位置的偏移量。

借助 `ftell(fp)` + `fseek(fp, 0, SEEK_END);` 来获取文件大小。

## rewind()

回卷文件读写指针。 将读写指针移动到起始位置。

```c
void rewind(FILE *stream);
```

## Linux和windows文件区别

1）对于二进制文件操作， Windows 使用“b”， Linux下二进制和文本没区别。
2）windows下，回车 \r, 换行 \n。 \r\n  , Linux下 回车换行\n

3) 对文件指针，先写后读。windows和Linux效果一致。
       先读后写。Linux无需修改。windows下需要在写操作之前添加 fseek(fp, 0, SEEK_CUR); 来获取文件读写指针，使之生效。

## 获取文件状态

打开文件，对于系统而言，系统资源消耗较大。

```c
int stat(const char *path, struct stat *buf);
```

参1： 访问文件的路径
参2： 文件属性结构体
返回值： 成功： 0， 失败： -1；

## 删除、重命名文件

```c
int remove(const char *pathname);		// 删除文件。
int rename(const char *oldpath, const char *newpath);		// 重名文件
```

## 缓冲区刷新

标准输出-- stdout -- 标准输出缓冲区。   写给屏幕的数据，都是先存缓冲区中，由缓冲区一次性刷新到物理设备（屏幕）
标准输入 -- stdin -- 标准输入缓冲区。从键盘读取的数据，直接读到 缓冲区中， 由缓冲区给程序提供数据。

## 预读入、缓输出

行缓冲：printf(); 遇到\n就会将缓冲区中的数据刷新到物理设备上。
全缓冲：文件。 缓冲区存满， 数据刷新到物理设备上。
无缓冲：perror。 缓冲区中只要有数据，就立即刷新到物理设备。

文件关闭时， 缓冲区会被自动刷新。  隐式回收：关闭文件、刷新缓冲区、释放malloc

手动刷新缓冲区： 实时刷新。

```c
int fflush(FILE *stream);
```

成功：0
失败：-1


# Day12_贪吃蛇小游戏

1. 定义蛇对象、食物对象

2. 初始化蛇、初始化食物

3. 控制流程：
   1） 蛇头和墙壁的碰撞
   2） 蛇头和蛇身体的碰撞
   3） 蛇头和食物的碰撞
   1> 蛇身增长
   2> 食物消失 -- 新食物产生
   3> 分数累加
   4> 移动速度增大
   4） 蛇的移动
   自动移动
   手动控制移动： ASWD --- 左下上右
   5）显示分数
   排行榜 

4. 图形界面。


## 定义蛇对象:

```c
struct BODY {
  int x;
  int Y;
};

struct SNAKE {
  struct BODY body[20*60];// 蛇身 。 body[0] -- 蛇头
  int size;// 蛇的大小
}snake;
```

## 食物对象：

```c
struct FOOD {
  int X;
  int Y;
}food;
```

分数： 

```c
int score;
```

## 初始化蛇：

封装一个函数 完成蛇的初始：

```c
void initSnake(void)
{
  snake.size = 2;

  snake.body[0].X = WIDE/2;// 初始化好了蛇头
  snake.body[0].Y = HiGH/2;

  snake.body[1].X = WIDE/2 - 1;// 初始化一节蛇身
  snake.body[1].Y = HIGH/2;
}
```

## 初始化食物：

```c
void initFood(void)
{
  food.X = rand() % WIDE;  // 0-59
  food.Y = rand() % HIGH;  // 0-59

  return;
}
```

## 修改控制台光标位置：

```c
#include <conio.h> <Windows.h>

COORD coord;// COORD  --> 结构体， 有两个成员变量：x，y 坐标

coord.X = snake.body[0].X;
coord.Y = snake.body[0].Y;

setConsoleCursorPositon(GetStdHandle(STD_OUTPUT_HANDLE), coord);
```

会将光标位置，定位到 初始化好的蛇头位置（WIDE/2， HIGH/2）. 屏幕中间 


## 画出蛇和食物： 

封装函数，

```c
initUI()

COORD coord = {0};// 光标移动的位置。

// 画蛇
for (size_t i = 0; i < snake.size; i++)
{
coord.X = snake.body[i].X;
coord.Y = snake.body[i].Y;

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

if (i == 0)
putchar('@');
else
putchar('*');
}

// 画食物
coord.X = food.X;
coord.Y = food.Y;

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

putchar('#');
```

蛇的移动控制：

W：（0， -1）  --> 影响蛇头。
S：（0， +1）
A：（-1， 0）
D：（+1， 0）


不回显：
getch()接收用户输入。

```c
char key = getch();
```

编译时出错，尝试使用` _getch();`


不阻塞：
`kbhit(); `不阻塞判断用户输入。
有用户输入，返回 “真”， 否则返回“假”值。
编译时出错，尝试使用` _kbhit();`

## 开始游戏：

```c
void playGame（void）
{
  char key = 'd'; // 默认蛇向右移动
  // 蛇头和墙壁的碰撞：
  while ( 判断是否撞墙 ) {
    // 重画蛇身 intiUI
    // 接收用户键盘输入。
    在全局 添加：kx， ky --》 根据 asdw 按键得不同坐标，影响蛇头
    // 蛇头和身体的碰撞
    // 蛇与食物的碰撞
    // 蛇身体移动 ： 前一节给后一节赋值，蛇头收 kx ky 的影响。
    system("cls");  清屏 -- 去除蛇尾。
  }
}
```

## 蛇头和墙壁的碰撞：

```c
snake.body[0].X > 0 && snake.body[0].X < WIDE 
&&
snake.body[0].Y > 0 && snake.body[0].Y < HIGH
```

蛇头和身体的碰撞：蛇头的坐标 和 任意一节身体的坐标 完全一致。

```c
for（i = 1; i < snake.size; i++）
{
    if (snake.body[0].X == snake.body[i].X && snake.body[0].Y == snake.body[i].Y )
  {
    终止游戏。
    return ;
  }
}
```

## 蛇头和食物的碰撞：

```c
if （snake.body[0].X == food.X && snake.body[0].Y == food.Y）
{
  蛇身增长： snake.size++;
  食物消失：（产生一个新食物）initFood（）
  加分：score += 10;
  加速：sleepSecond -= 20;
}
```

## 蛇移动：

前一节身体给后一节身体赋值。 蛇头按照 aswd 换算的坐标值 进行变换。

```c
for (size_t i = snake.size-1; i > 0; i--)
{
  snake.body[i].X = snake.body[i - 1].X;
  snake.body[i].Y = snake.body[i - 1].Y;
}
snake.body[0].X += kx;// 蛇头坐标根据用户按键，修改。
snake.body[0].Y += ky;
```

## 画墙：

```c
void initWall(void)
{
	for (size_t i = 0; i <= HIGH; i++)// 多行
	{
		for (size_t j = 0; j <= WIDE; j++)// 一行中的多列
		{
			if (j == WIDE)
			{
				printf("|");
			}
			else if (i == HIGH)
			{
				printf("_");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
```

## 去除蛇尾：

蛇移动之前保存蛇尾坐标。
定义全局变量 ：lastX， lastY；

```c
lastX = snake.body[snake.size-1].X ;
lastY = snake.body[snake.size-1].Y ;
```

在initUI中， 将蛇尾 替换为 ' '

```c
coord.X = lastX;
coord.Y = lastY;
setConsoleCursorPosition(GetSTDHandler(STD_OUTPUT_HANDLE), coord);
putchar(' ');
```

## 去除光标：

```c
typedef struct _CONSOLE_CURSOR_INFO {
    DWORD  dwSize;// 大小
    BOOL   bVisible;// 是否可见。
} CONSOLE_CURSOR_INFO;
```

定义结构体变量：

```c
CONSOLE_CURSOR_INFO  cci;
cci.dwSize = sizeof(cci);
cci.bVisible = FALSE; //  0 假 --- 不可见
```

## 设置光标不可见生效：

```
setConsoleCursorInfo(GetSTDHandler(STD_OUTPUT_HANDLE), &cci);
```

在main函数中，调用一次即可生效。

## 显示分数

playGame调用结束时，打印 全局score 值。

## 加速：

全局定义变量： `sleepSecond = 400;`

```c
Sleep(sleepSecond);
```

成功吃食物，`sleepSecond -= 20;`