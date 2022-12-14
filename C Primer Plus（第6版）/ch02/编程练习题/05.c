#include <stdio.h>

void br(void);
void ic(void);

int main(void) {
    br();
    printf(", ");
    ic();
    putchar('\n');

    ic();
    putchar('\n');

    br();
    putchar('\n');

    return 0;
}

void br(void) { printf("Brazil, Russia"); }
void ic(void) { printf("India, China"); }