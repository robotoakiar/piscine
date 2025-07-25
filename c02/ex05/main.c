#include <stdio.h> // สำหรับ printf
#include <string.h> // สำหรับ strlen (หากจำเป็นสำหรับการทดสอบเพิ่มเติม)

// ประกาศ prototype ของฟังก์ชัน ft_str_is_uppercase
// คุณจะต้องใส่โค้ดของฟังก์ชันนี้ในไฟล์ ft_str_is_uppercase.c
int ft_str_is_uppercase(char *str);

int main() {
    // --- กรณีทดสอบปกติ ---

    // 1. สตริงที่มีแต่ตัวพิมพ์ใหญ่
    char str1[] = "HELLOWORLD";
    printf("Testing \"%s\": %d (Expected: 1)\n", str1, ft_str_is_uppercase(str1));

    // 2. สตริงที่มีตัวพิมพ์เล็กปนอยู่
    char str2[] = "HelloWorld";
    printf("Testing \"%s\": %d (Expected: 0)\n", str2, ft_str_is_uppercase(str2));

    // 3. สตริงที่มีตัวเลขปนอยู่
    char str3[] = "HELLO123WORLD";
    printf("Testing \"%s\": %d (Expected: 0)\n", str3, ft_str_is_uppercase(str3));

    // 4. สตริงที่มีสัญลักษณ์พิเศษปนอยู่
    char str4[] = "HELLO!WORLD?";
    printf("Testing \"%s\": %d (Expected: 0)\n", str4, ft_str_is_uppercase(str4));

    // 5. สตริงผสม (ตัวพิมพ์ใหญ่, ตัวพิมพ์เล็ก, ตัวเลข, สัญลักษณ์)
    char str5[] = "ABCdef123!@#";
    printf("Testing \"%s\": %d (Expected: 0)\n", str5, ft_str_is_uppercase(str5));

    // --- กรณีทดสอบพิเศษ ---

    // 6. สตริงว่างเปล่า (ตามโจทย์ควรคืนค่า 1)
    char str6[] = "";
    printf("Testing \"%s\" (empty string): %d (Expected: 1)\n", str6, ft_str_is_uppercase(str6));

    // 7. สตริงที่มีแค่ตัวพิมพ์ใหญ่หนึ่งตัว
    char str7[] = "A";
    printf("Testing \"%s\": %d (Expected: 1)\n", str7, ft_str_is_uppercase(str7));

    // 8. สตริงที่มีแค่ตัวพิมพ์เล็กหนึ่งตัว
    char str8[] = "a";
    printf("Testing \"%s\": %d (Expected: 0)\n", str8, ft_str_is_uppercase(str8));

    // 9. สตริงที่มีแค่ตัวเลขหนึ่งตัว
    char str9[] = "5";
    printf("Testing \"%s\": %d (Expected: 0)\n", str9, ft_str_is_uppercase(str9));

    // 10. สตริงที่มีแค่ช่องว่าง (space)
    char str10[] = " ";
    printf("Testing \"%s\": %d (Expected: 0)\n", str10, ft_str_is_uppercase(str10));


    return 0;
}