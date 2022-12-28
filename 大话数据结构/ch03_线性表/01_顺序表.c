#include <stdio.h>
#define MAXSIZE 20
typedef int ElemType;

// 定义顺序表的数据结构
typedef struct {
  ElemType data[MAXSIZE];
  int length;
} SeqList;

// 初始化顺序表
_Bool Initlist(SeqList *list);

// 求顺序表长度
int LengthList(const SeqList *list);

// 按值查找
int Locate(const SeqList *list, const ElemType *e);

// 获得第i个元素
_Bool GetData(const SeqList *list, int i, ElemType *e);

// 在第i个元素之前插入一个元素
_Bool InsertData(SeqList *list, int i, const ElemType e);

// 删除第i个元素
_Bool DeleteData(SeqList *list, int i, ElemType *e);

// 销毁顺序表
_Bool DestoryList(SeqList *list);

// 清空顺序表
_Bool ClearList(SeqList *list);

// 判断顺序表是否为空表
_Bool IsNullList(const SeqList *list);

// 遍历顺序表，即输出表中所有元素
_Bool PrintList(const SeqList *list);