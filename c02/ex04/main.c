#include <stdio.h> // สำหรับ printf
#include <string.h> // สำหรับ strlen (ถ้าคุณต้องการใช้)

// ประกาศ prototype ของฟังก์ชัน ft_str_is_lowercase
// ให้แน่ใจว่าคุณใส่ไฟล์ .c ของคุณ (ft_str_is_lowercase.c) ในการคอมไพล์
int ft_str_is_lowercase(char *str);

int main() {
    printf("--- Test Cases for ft_str_is_lowercase ---\n\n");

    // Test Case 1: สตริงที่มีแต่ตัวพิมพ์เล็กทั้งหมด
    char *test1 = "hello";
    printf("Testing \"%s\": Expected 1, Got %d\n", test1, ft_str_is_lowercase(test1));

    // Test Case 2: สตริงที่มีตัวพิมพ์ใหญ่ผสมอยู่
    char *test2 = "HelloWorld";
    printf("Testing \"%s\": Expected 0, Got %d\n", test2, ft_str_is_lowercase(test2));

    // Test Case 3: สตริงที่มีตัวเลขผสมอยู่
    char *test3 = "hello123world";
    printf("Testing \"%s\": Expected 0, Got %d\n", test3, ft_str_is_lowercase(test3));

    // Test Case 4: สตริงที่มีอักขระพิเศษผสมอยู่
    char *test4 = "hello_world!";
    printf("Testing \"%s\": Expected 0, Got %d, (Expected 0 because of '_' and '!')\n", test4, ft_str_is_lowercase(test4));

    // Test Case 5: สตริงว่างเปล่า
    char *test5 = "";
    printf("Testing \"%s\" (empty string): Expected 1, Got %d\n", test5, ft_str_is_lowercase(test5));

    // Test Case 6: สตริงที่มีแต่ช่องว่าง
    char *test6 = "   ";
    printf("Testing \"%s\" (spaces only): Expected 0, Got %d\n", test6, ft_str_is_lowercase(test6));

    // Test Case 7: สตริงที่มีตัวพิมพ์เล็กผสมกับช่องว่าง (ควรเป็น 0 เพราะมีช่องว่าง)
    char *test7 = "hello world";
    printf("Testing \"%s\": Expected 0, Got %d\n", test7, ft_str_is_lowercase(test7));

    // Test Case 8: สตริงที่มีแต่ตัวพิมพ์ใหญ่ทั้งหมด
    char *test8 = "UPPERCASE";
    printf("Testing \"%s\": Expected 0, Got %d\n", test8, ft_str_is_lowercase(test8));

    // Test Case 9: สตริงที่มี NULL character ตรงกลาง (ไม่ควรเจอในกรณีปกติ)
    char test9_arr[] = {'a', 'b', '\0', 'c'};
    char *test9 = test9_arr;
    printf("Testing \"abc\\0c\": Expected 1, Got %d (assuming function stops at null terminator)\n", ft_str_is_lowercase(test9));


    printf("\n--- End of Tests ---\n");

    return 0;
}