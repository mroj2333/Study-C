#include <stdio.h>

int main(void) {
    printf("Please enter your name and weight.\n");
    char name[40];
    float weight = 0;
    scanf("%s %f", name, &weight);

    printf("%s, you are %.3f feet tall\n", name, weight);

    return 0;
}