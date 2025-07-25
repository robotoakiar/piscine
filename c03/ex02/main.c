#include <stdio.h> // สำหรับ printf
#include <string.h> // สำหรับ strlen (ถ้าต้องการใช้เปรียบเทียบหรือตรวจสอบความยาว)

// ประกาศ prototype ของฟังก์ชัน ft_strcat ของคุณ
char	*ft_strcat(char *dest, char *src);

int main() {
    // Test Case 1: สตริงปลายทางว่างเปล่า
    char dest1[50] = ""; // ต้องกำหนดขนาดเผื่อไว้
    char src1[] = "Hello";
    printf("Test Case 1:\n");
    printf("ก่อน strcat: dest = \"%s\", src = \"%s\"\n", dest1, src1);
    ft_strcat(dest1, src1);
    printf("หลัง strcat: dest = \"%s\"\n", dest1);
    printf("-----------------------------------\n");

    // Test Case 2: สตริงปลายทางมีข้อมูลอยู่แล้ว
    char dest2[50] = "World";
    char src2[] = "!";
    printf("Test Case 2:\n");
    printf("ก่อน strcat: dest = \"%s\", src = \"%s\"\n", dest2, src2);
    ft_strcat(dest2, src2);
    printf("หลัง strcat: dest = \"%s\"\n", dest2);
    printf("-----------------------------------\n");

    // Test Case 3: สตริงต้นทางว่างเปล่า
    char dest3[50] = "Testing";
    char src3[] = "";
    printf("Test Case 3:\n");
    printf("ก่อน strcat: dest = \"%s\", src = \"%s\"\n", dest3, src3);
    ft_strcat(dest3, src3);
    printf("หลัง strcat: dest = \"%s\"\n", dest3);
    printf("-----------------------------------\n");

    // Test Case 4: สตริงต้นทางและปลายทางยาว
    char dest4[100] = "This is a very long string for the destination.";
    char src4[] = " And this is a moderately long source string.";
    printf("Test Case 4:\n");
    printf("ก่อน strcat: dest = \"%s\"\n", dest4);
    printf("             src = \"%s\"\n", src4);
    ft_strcat(dest4, src4);
    printf("หลัง strcat: dest = \"%s\"\n", dest4);
    printf("-----------------------------------\n");

    // Test Case 5: การทำงานกับตัวอักษรพิเศษ (ถ้าจำเป็นต้องทดสอบ)
    char dest5[50] = "Special Chars: ";
    char src5[] = "~!@#$%^&*()_+";
    printf("Test Case 5:\n");
    printf("ก่อน strcat: dest = \"%s\", src = \"%s\"\n", dest5, src5);
    ft_strcat(dest5, src5);
    printf("หลัง strcat: dest = \"%s\"\n", dest5);
    printf("-----------------------------------\n");

    // Test Case 6: ทดสอบการคืนค่า (return value)
    char dest6[50] = "Return Value";
    char src6[] = " Test";
    char *result_ptr = ft_strcat(dest6, src6);
    printf("Test Case 6:\n");
    printf("หลัง strcat: dest = \"%s\"\n", dest6);
    printf("ค่าที่คืน:   result_ptr = \"%s\"\n", result_ptr);
    if (result_ptr == dest6) {
        printf("  (ถูกต้อง: พอยน์เตอร์ที่คืนชี้ไปยัง dest)\n");
    } else {
        printf("  (ผิดพลาด: พอยน์เตอร์ที่คืนไม่ชี้ไปยัง dest)\n");
    }
    printf("-----------------------------------\n");

    return 0;
}