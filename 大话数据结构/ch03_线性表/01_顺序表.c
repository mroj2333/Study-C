// 头文件引入
#include <stdio.h>
#include <stdlib.h>

typedef int Status;
// 函数结果状态码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 26
typedef char ElemType;

// 定义顺序表的数据结构
typedef struct {
  ElemType *data;
  int length;
} SeqList;

// 初始化顺序表
Status Initlist(SeqList *list);

// 求顺序表长度
int LengthList(const SeqList *list);

// 按值查找
int Locate(const SeqList *list, const ElemType e);

// 获得第i个元素
int GetData(const SeqList *list, int i, ElemType *e);

// 在第i个位置插入一个元素
Status InsertData(SeqList *list, int i, const ElemType e);

// 删除第i个元素
Status DeleteData(SeqList *list, int i, ElemType *e);

// 销毁顺序表
void DestroyList(SeqList *list);

// 清空顺序表
void ClearList(SeqList *list);

// 判断顺序表是否为空表
int IsNullList(const SeqList *list);

// 遍历顺序表，即输出表中所有元素
void PrintList(const SeqList *list);

int main(void) {
  SeqList L;
  Initlist(&L);

  for (int i = 0; i < 26; i++) {
    L.data[i] = 65 + i;
    L.length++;
  }
  ElemType e;
  DeleteData(&L, 2, &e);
  PrintList(&L);
  InsertData(&L, 26, e);
  PrintList(&L);

  return 0;
}

Status Initlist(SeqList *list) {
  list->data =
      (ElemType *)malloc(sizeof(ElemType) * MAXSIZE); // 申请顺序表的空间
  if (list->data == NULL)
    return OVERFLOW;
  list->length = 0;
  return OK;
}

void DestroyList(SeqList *list) {
  if (list->data != NULL) {
    free(list->data);
    list->data = NULL; // 将顺序表的内存清空
  }
}

void ClearList(SeqList *list) {
  list->length = 0; // 将顺序表的长度设置为0
}

int LengthList(const SeqList *list) { return list->length; }

int IsNullList(const SeqList *list) {
  if (list->length == 0) {
    return TRUE;
  }
  return FALSE;
}

int GetData(const SeqList *list, int i, ElemType *e) {
  if (i < 1 || i > list->length) {
    return ERROR;
  }
  *e = list->data[i - 1];
  return OK;
}

int Locate(const SeqList *list, const ElemType e) {
  for (int i = 0; i < list->length; i++) {
    if (list->data[i] == e) {
      return i + 1;
    }
  }
  return 0;
}

Status InsertData(SeqList *list, int i, const ElemType e) {
  // 判断i是否合法
  if (i > (list->length) + 1 || i < 1) {
    return ERROR;
  }
  // 判断存储空间有没有空余
  if (list->length == MAXSIZE) {
    return ERROR;
  }
  // 将第i个元素后面的元素都向后移动一个元素的位置
  for (int j = list->length; j >= i - 1; j--) {
    list->data[j + 1] = list->data[j];
  }
  list->data[i - 1] = e;
  list->length++;
  return OK;
}

Status DeleteData(SeqList *list, int i, ElemType *e) {
  if (i < 1 || i > list->length) {
    return ERROR;
  }
  if (list->length == 0) {
    return ERROR;
  }
  *e = list->data[i - 1];
  for (int j = i; j < list->length; j++) {
    list->data[j - 1] = list->data[j];
  }
  list->data[list->length - 1] = '\0';
  list->length--;
  return OK;
}

void PrintList(const SeqList *list) {
  for (int i = 0; i < list->length; i++) {
    printf("%c ", list->data[i]);
  }
  printf("\n");
}