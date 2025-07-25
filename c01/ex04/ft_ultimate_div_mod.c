#include <unistd.h>

void    ft_ultimate_div_mod(int *a, int *b)
{
    int val_a = *a;

    *a = val_a / *b;
    *b = val_a % *b;
}

#include <stdio.h>

int main()
{
    int num1 = 10;
    int num2 = 3;

    printf("ก่อนเรียกใช้ฟังก์ชัน:\n");
    printf("num1 (ตัวตั้งหาร): %d\n", num1); // คาดหวัง: 10
    printf("num2 (ตัวหาร): %d\n", num2);  // คาดหวัง: 3

    ft_ultimate_div_mod(&num1, &num2);

    printf("\nหลังเรียกใช้ฟังก์ชัน:\n");
    printf("num1 (ผลหาร): %d\n", num1); // คาดหวัง: 3 (10 / 3)
    printf("num2 (เศษ): %d\n", num2); // คาดหวัง: 1 (10 %% 3)

    int num3 = 20;
    int num4 = 5;

    printf("\nก่อนเรียกใช้ฟังก์ชัน:\n");
    printf("num3 (ตัวตั้งหาร): %d\n", num3); // คาดหวัง: 20
    printf("num4 (ตัวหาร): %d\n", num4);  // คาดหวัง: 5

    ft_ultimate_div_mod(&num3, &num4);

    printf("\nหลังเรียกใช้ฟังก์ชัน:\n");
    printf("num3 (ผลหาร): %d\n", num3); // คาดหวัง: 4 (20 / 5)
    printf("num4 (เศษ): %d\n", num4); // คาดหวัง: 0 (20 %% 5)

    // ตัวอย่างกับตัวเลขติดลบ (พฤติกรรมของ / และ % กับตัวเลขติดลบอาจแตกต่างกัน
    // ใน C ก่อน C99 แต่มีการกำหนดไว้อย่างชัดเจนตั้งแต่ C99 เป็นต้นไปให้ตัดทศนิยมเข้าหาศูนย์)
    int num5 = -10;
    int num6 = 3;

    printf("\nก่อนเรียกใช้ฟังก์ชัน:\n");
    printf("num5 (ตัวตั้งหาร): %d\n", num5); // คาดหวัง: -10
    printf("num6 (ตัวหาร): %d\n", num6);  // คาดหวัง: 3

    ft_ultimate_div_mod(&num5, &num6);

    printf("\nหลังเรียกใช้ฟังก์ชัน:\n");
    printf("num5 (ผลหาร): %d\n", num5); // คาดหวัง: -3 (-10 / 3)
    printf("num6 (เศษ): %d\n", num6); // คาดหวัง: -1 (-10 %% 3)

    return 0;
}