#include <stdio.h>

void countdown(int n) {
    printf("%d\n", n);
    if (n > 1) {
        countdown(n-1); // เรียกตัวเองแต่ค่าลดลง
    }
    printf("จบ %d\n", n);
}

int main()
{
    countdown(3);
    return 0;

}