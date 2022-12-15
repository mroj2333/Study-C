#include <stdio.h>

int main(void) {
    printf("Enter a floating-point value: ");
    float a = 0;
    scanf("%f", &a);
    printf("fixed-point notation: %.6f\n", a);
    printf("exponential notation: %e\n", a);
    printf("p notation: %a\n", a);

    return 0;
}