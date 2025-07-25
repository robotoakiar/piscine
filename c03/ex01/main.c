#include <stdio.h> // สำหรับ printf
#include <string.h> // สำหรับ strncmp เพื่อเปรียบเทียบผลลัพธ์กับฟังก์ชันมาตรฐาน

// โปรโตไทป์ของฟังก์ชัน ft_strncmp ที่คุณเขียน
int ft_strncmp(char *s1, char *s2, unsigned int n);

int main() {
    // กรณีทดสอบต่างๆ
    char *s1;
    char *s2;
    unsigned int n;
    int ft_result;
    int std_result;

    printf("--- Testing ft_strncmp ---\n\n");

    // Test Case 1: สตริงเหมือนกันทั้งหมด n ตัวอักษร
    s1 = "hello world";
    s2 = "hello there";
    n = 5;
    ft_result = ft_strncmp(s1, s2, n);
    std_result = strncmp(s1, s2, n);
    printf("Test 1: s1=\"%s\", s2=\"%s\", n=%d\n", s1, s2, n);
    printf("ft_strncmp result: %d (Expected: %d)\n", ft_result, std_result);
    printf("%s\n\n", (ft_result == std_result) ? "PASSED" : "FAILED");

    // Test Case 2: สตริงต่างกันก่อน n ตัวอักษร
    s1 = "hello world";
    s2 = "hellow there"; // ตัว 'w' ต่างกัน
    n = 10;
    ft_result = ft_strncmp(s1, s2, n);
    std_result = strncmp(s1, s2, n);
    printf("Test 2: s1=\"%s\", s2=\"%s\", n=%d\n", s1, s2, n);
    printf("ft_strncmp result: %d (Expected: %d)\n", ft_result, std_result);
    // เนื่องจากผลลัพธ์อาจเป็นค่าบวก/ลบต่างกันแต่เครื่องหมายเหมือนกัน เราจะตรวจสอบเครื่องหมาย
    printf("%s\n\n", ((ft_result < 0 && std_result < 0) || (ft_result > 0 && std_result > 0) || (ft_result == 0 && std_result == 0)) ? "PASSED" : "FAILED");


    // Test Case 3: หนึ่งในสตริงสั้นกว่า n
    s1 = "apple";
    s2 = "apply";
    n = 10; // n มากกว่าความยาวของสตริง
    ft_result = ft_strncmp(s1, s2, n);
    std_result = strncmp(s1, s2, n);
    printf("Test 3: s1=\"%s\", s2=\"%s\", n=%d\n", s1, s2, n);
    printf("ft_strncmp result: %d (Expected: %d)\n", ft_result, std_result);
    printf("%s\n\n", ((ft_result < 0 && std_result < 0) || (ft_result > 0 && std_result > 0) || (ft_result == 0 && std_result == 0)) ? "PASSED" : "FAILED");

    // Test Case 4: สตริงเหมือนกันแต่มี null terminator อยู่ข้างใน (ไม่ควรเกิดขึ้นกับสตริงปกติ)
    // สำหรับการทดสอบลักษณะ strncmp โดยเฉพาะ
    char s3[] = {'a', 'b', '\0', 'c'};
    char s4[] = {'a', 'b', '\0', 'd'};
    n = 4;
    ft_result = ft_strncmp(s3, s4, n);
    std_result = strncmp(s3, s4, n);
    printf("Test 4: s1=\"a b \\0 c\", s2=\"a b \\0 d\", n=%d\n", n);
    printf("ft_strncmp result: %d (Expected: %d)\n", ft_result, std_result);
    printf("%s\n\n", (ft_result == std_result) ? "PASSED" : "FAILED");

    // Test Case 5: n = 0
    s1 = "test";
    s2 = "different";
    n = 0;
    ft_result = ft_strncmp(s1, s2, n);
    std_result = strncmp(s1, s2, n);
    printf("Test 5: s1=\"%s\", s2=\"%s\", n=%d\n", s1, s2, n);
    printf("ft_strncmp result: %d (Expected: %d)\n", ft_result, std_result);
    printf("%s\n\n", (ft_result == std_result) ? "PASSED" : "FAILED");

    // Test Case 6: สตริงว่างเปล่า
    s1 = "";
    s2 = "abc";
    n = 3;
    ft_result = ft_strncmp(s1, s2, n);
    std_result = strncmp(s1, s2, n);
    printf("Test 6: s1=\"%s\", s2=\"%s\", n=%d\n", s1, s2, n);
    printf("ft_strncmp result: %d (Expected: %d)\n", ft_result, std_result);
    printf("%s\n\n", ((ft_result < 0 && std_result < 0) || (ft_result > 0 && std_result > 0) || (ft_result == 0 && std_result == 0)) ? "PASSED" : "FAILED");

    // Test Case 7: สตริงว่างเปล่าทั้งคู่
    s1 = "";
    s2 = "";
    n = 1;
    ft_result = ft_strncmp(s1, s2, n);
    std_result = strncmp(s1, s2, n);
    printf("Test 7: s1=\"%s\", s2=\"%s\", n=%d\n", s1, s2, n);
    printf("ft_strncmp result: %d (Expected: %d)\n", ft_result, std_result);
    printf("%s\n\n", ((ft_result < 0 && std_result < 0) || (ft_result > 0 && std_result > 0) || (ft_result == 0 && std_result == 0)) ? "PASSED" : "FAILED");

    // Test Case 8: สตริงต่างกันในอักขระตัวแรก
    s1 = "zpple";
    s2 = "apple";
    n = 5;
    ft_result = ft_strncmp(s1, s2, n);
    std_result = strncmp(s1, s2, n);
    printf("Test 8: s1=\"%s\", s2=\"%s\", n=%d\n", s1, s2, n);
    printf("ft_strncmp result: %d (Expected: %d)\n", ft_result, std_result);
    printf("%s\n\n", ((ft_result < 0 && std_result < 0) || (ft_result > 0 && std_result > 0) || (ft_result == 0 && std_result == 0)) ? "PASSED" : "FAILED");

    // Test Case 9: สตริงต่างกันที่ n
    s1 = "abcdef";
    s2 = "abcdeg";
    n = 6;
    ft_result = ft_strncmp(s1, s2, n);
    std_result = strncmp(s1, s2, n);
    printf("Test 9: s1=\"%s\", s2=\"%s\", n=%d\n", s1, s2, n);
    printf("ft_strncmp result: %d (Expected: %d)\n", ft_result, std_result);
    printf("%s\n\n", ((ft_result < 0 && std_result < 0) || (ft_result > 0 && std_result > 0) || (ft_result == 0 && std_result == 0)) ? "PASSED" : "FAILED");


    return 0;
}

// **ใส่โค้ด ft_strncmp ของคุณไว้ด้านล่างนี้**
/*
int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int i;

    i = 0;
    if (n == 0)
        return (0);

    while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
        i++;

    if (i == n)
        return (0);

    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
*/