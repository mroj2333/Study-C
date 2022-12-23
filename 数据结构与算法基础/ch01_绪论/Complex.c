// P10 抽象数据类型“复数”的实现
#include <stdio.h>

typedef struct {
    float Realpart;
    float Imagepart;
} Complex;

// 构造一个复数
void Create(Complex* C, float x, float y) {
    C->Imagepart = y;
    C->Realpart = x;
}

// 取得复数的实部
float GetReal(Complex C) { return C.Realpart; }

// 取得复数的虚部
float GetImage(Complex C) { return C.Imagepart; }

// 求两个复数C1和C2的和sum
Complex Add(Complex C1, Complex C2) {
    Complex sum;
    sum.Imagepart = C1.Imagepart + C2.Imagepart;
    sum.Realpart = C1.Realpart + C2.Realpart;
    return sum;
}

// 求两个复数C1和C2的差difference
Complex Sub(Complex C1, Complex C2) {
    Complex sub;
    sub.Imagepart = C1.Imagepart - C2.Imagepart;
    sub.Realpart = C1.Realpart - C2.Realpart;
    return sub;
}

int main(void) {
    Complex C1, C2;
    Create(&C1, 9, 15);
    Create(&C2, 5, 7);
    Complex C3 = Add(C1, C2);
    Complex C4 = Sub(C1, C2);

    printf("复数C1为：C = %.2f + %.2fi\n", C1.Realpart, C1.Imagepart);
    printf("复数C2为：C = %.2f + %.2fi\n", C2.Realpart, C2.Imagepart);
    printf("复数的和为：C = %.2f + %.2fi\n", C3.Realpart, C3.Imagepart);
    printf("复数的差为：C = %.2f + %.2fi\n", C4.Realpart, C4.Imagepart);

    return 0;
}