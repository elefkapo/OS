#include <stdio.h>

void add(int *a, int *b, int *c, int *result) {
    *result = *a + *b + *c;
}

int main() {
    int x = 7, y = 13, z = 21, sum = 0;
    add(&x, &y, &z, &sum);
    printf("The sum of %d, %d, and %d is %d\n", x, y, z, sum);
    return 0;
}
