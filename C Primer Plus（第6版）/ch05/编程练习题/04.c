#include <stdio.h>
#define CM_FEET     2.54
#define FEET_INCHES 12

int main(void) {
    float cm, feet;
    int inches;
    printf("Enter a height in centimeters: ");
    scanf("%f", &cm);

    while (cm > 0) {
        feet = cm / 2.54;
        inches = feet / 12;
        feet = feet - 12 * inches;
        printf("%.1f cm = %d feet, %.1f inches\n", cm, inches, feet);
        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf("%f", &cm);
    }
    printf("bye\n");

    return 0;
}