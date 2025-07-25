// main.c
#include <stdio.h>
#include "ft_strlen.h"

int main()
{
    // เพิ่ม 'const' เพื่อบอก compiler ว่า String นี้ไม่สามารถแก้ไขได้
    // ซึ่งมักจะทำให้ compiler วาง String Literal ไว้ในส่วน .rodata ที่เหมาะสม
    const char *a = "hello, world"; 
    int len = ft_strlen((char *)a); // ต้อง cast เป็น (char *) เพราะ ft_strlen รับ char *

    printf("%d\n", len);
    return 0;
}