#include <stdio.h>

int main()
{
    int x = 5;
    if (x) // เหมือนกับ if (x != 0)
        printf("จริง");

    char *ptr = "Hello";
    if (ptr) // เหมือนกับ if (ptr != NULL)
        printf("pointer ไม่ใช่ NULL");
}