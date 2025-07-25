#include <stdio.h>
void show_first(int *x) {
    printf("%d\n", x[0]);
    printf("%d\n", x[1]);
    printf("%d\n", x[2]);
    printf("%d\n", x[3]);
    printf("%d\n", x[-1]);
    printf("%d\n", x[1000]);
}

int main() {
    int nums[] = {10, 20, 30};
    show_first(nums);       // ✅ nums กลายเป็น pointer โดยอัตโนมัติ
}
