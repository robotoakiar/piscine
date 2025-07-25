#include <stdio.h> // สำหรับ printf

char    *ft_strupcase(char *str);

int main()
{
    // Test Case 1: สตริงที่มีทั้งตัวพิมพ์เล็ก, ตัวพิมพ์ใหญ่, ตัวเลข, และสัญลักษณ์
    char test_string1[] = "Hello World! 123 C Program.";
    printf("Original 1: %s\n", test_string1);
    ft_strupcase(test_string1);
    printf("Uppercase 1: %s\n", test_string1); // ควรเป็น: HELLO WORLD! 123 C PROGRAM.
    printf("---------------------------\n");

    // Test Case 2: สตริงที่มีแต่ตัวพิมพ์เล็ก
    char test_string2[] = "this is a test.";
    printf("Original 2: %s\n", test_string2);
    ft_strupcase(test_string2);
    printf("Uppercase 2: %s\n", test_string2); // ควรเป็น: THIS IS A TEST.
    printf("---------------------------\n");

    // Test Case 3: สตริงที่มีแต่ตัวพิมพ์ใหญ่ (ควรไม่มีการเปลี่ยนแปลง)
    char test_string3[] = "ALREADY UPPERCASE!";
    printf("Original 3: %s\n", test_string3);
    ft_strupcase(test_string3);
    printf("Uppercase 3: %s\n", test_string3); // ควรเป็น: ALREADY UPPERCASE!
    printf("---------------------------\n");

    // Test Case 4: สตริงว่าง (Empty string)
    char test_string4[] = "";
    printf("Original 4: \"%s\"\n", test_string4);
    ft_strupcase(test_string4);
    printf("Uppercase 4: \"%s\"\n", test_string4); // ควรเป็น: ""
    printf("---------------------------\n");

    // Test Case 5: สตริงที่มีแต่ตัวเลขและสัญลักษณ์
    char test_string5[] = "12345 !@#$%^&*()_+";
    printf("Original 5: %s\n", test_string5);
    ft_strupcase(test_string5);
    printf("Uppercase 5: %s\n", test_string5); // ควรเป็น: 12345 !@#$%^&*()_+
    printf("---------------------------\n");

    // Test Case 6: สตริงที่มีตัวอักษรเฉพาะ 'a' และ 'z' (กรณีขอบ)
    char test_string6[] = "aBcDeFz";
    printf("Original 6: %s\n", test_string6);
    ft_strupcase(test_string6);
    printf("Uppercase 6: %s\n", test_string6); // ควรเป็น: ABCDEFZ
    printf("---------------------------\n");

    return 0;
}