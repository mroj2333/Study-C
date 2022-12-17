#include <float.h>
#include <stdio.h>

int main(void) {
    double a = 1.0 / 3.0;
    float b = 1.0 / 3.0;

    printf("double a = %.6f, float b = %.6f\n", a, b);
    printf("double a = %.12f, float b = %.12f\n", a, b);
    printf("double a = %.16f, float b = %.16f\n", a, b);

    printf("\nFLT_DIG = %d, DBL_DIG = %d\n", FLT_DIG, DBL_DIG);

    return 0;
}