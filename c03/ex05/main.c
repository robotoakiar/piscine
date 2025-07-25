#include <stdio.h> // สำหรับ printf
#include <string.h> // สำหรับ strcpy (ใช้แค่คัดลอกสตริงเริ่มต้น)

// ต้องรวมไฟล์ ft_strlcat.c ของคุณที่นี่
// หรือคอมไพล์พร้อมกับมัน
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int main(void)
{
    // --- ทดสอบที่ 1: กรณีปกติ มีพื้นที่เพียงพอ ---
    char dest1[20] = "Hello";
    char src1[] = " World!";
    unsigned int size1 = sizeof(dest1);
    unsigned int result_ft_1;

    printf("--- Test Case 1: Normal Concatenation (Enough Space) ---\n");
    printf("Initial dest1: \"%s\"\n", dest1);
    printf("src1: \"%s\"\n", src1);
    printf("Size limit: %u\n", size1);

    result_ft_1 = ft_strlcat(dest1, src1, size1);
    printf("ft_strlcat result: \"%s\" (Return: %u)\n", dest1, result_ft_1);
    printf("Expected return (dest_len + src_len): %lu + %lu = %lu\n", strlen("Hello"), strlen(" World!"), strlen("Hello") + strlen(" World!"));
    printf("--------------------------------------------------\n\n");

    // --- ทดสอบที่ 2: กรณีพื้นที่จำกัด (ตัดบางส่วน) ---
    char dest2[10] = "abc";
    char src2[] = "defghijkl";
    unsigned int size2 = sizeof(dest2);
    unsigned int result_ft_2;

    printf("--- Test Case 2: Limited Space (Truncation) ---\n");
    printf("Initial dest2: \"%s\"\n", dest2);
    printf("src2: \"%s\"\n", src2);
    printf("Size limit: %u\n", size2);

    result_ft_2 = ft_strlcat(dest2, src2, size2);
    printf("ft_strlcat result: \"%s\" (Return: %u)\n", dest2, result_ft_2);
    printf("Expected return (dest_len + src_len): %lu + %lu = %lu\n", strlen("abc"), strlen("defghijkl"), strlen("abc") + strlen("defghijkl"));
    printf("--------------------------------------------------\n\n");

    // --- ทดสอบที่ 3: กรณีไม่มีพื้นที่เลย (size <= dest_len) ---
    char dest3[5] = "abc"; // dest_len = 3
    char src3[] = "de";    // src_len = 2
    unsigned int size3 = sizeof(dest3); // size = 5
    unsigned int result_ft_3;

    printf("--- Test Case 3: No Space At All (Size <= dest_len) ---\n");
    printf("Initial dest3: \"%s\"\n", dest3);
    printf("src3: \"%s\"\n", src3);
    printf("Size limit: %u\n", size3);

    result_ft_3 = ft_strlcat(dest3, src3, size3);
    printf("ft_strlcat result: \"%s\" (Return: %u)\n", dest3, result_ft_3);
    // ตาม spec strlcat ถ้า size <= dest_len, คืนค่า size + src_len
    printf("Expected return (size + src_len): %u + %lu = %lu\n", size3, strlen("de"), size3 + strlen("de"));
    printf("--------------------------------------------------\n\n");

    // --- ทดสอบที่ 4: dest เป็นสตริงว่างเปล่า ---
    char dest4[10] = "";
    char src4[] = "HelloWorld";
    unsigned int size4 = sizeof(dest4);
    unsigned int result_ft_4;

    printf("--- Test Case 4: Empty Destination String ---\n");
    printf("Initial dest4: \"%s\"\n", dest4);
    printf("src4: \"%s\"\n", src4);
    printf("Size limit: %u\n", size4);

    result_ft_4 = ft_strlcat(dest4, src4, size4);
    printf("ft_strlcat result: \"%s\" (Return: %u)\n", dest4, result_ft_4);
    printf("Expected return (dest_len + src_len): %lu + %lu = %lu\n", strlen(""), strlen("HelloWorld"), strlen("") + strlen("HelloWorld"));
    printf("--------------------------------------------------\n\n");

    // --- ทดสอบที่ 5: src เป็นสตริงว่างเปล่า ---
    char dest5[10] = "Prefix";
    char src5[] = "";
    unsigned int size5 = sizeof(dest5);
    unsigned int result_ft_5;

    printf("--- Test Case 5: Empty Source String ---\n");
    printf("Initial dest5: \"%s\"\n", dest5);
    printf("src5: \"%s\"\n", src5);
    printf("Size limit: %u\n", size5);

    result_ft_5 = ft_strlcat(dest5, src5, size5);
    printf("ft_strlcat result: \"%s\" (Return: %u)\n", dest5, result_ft_5);
    printf("Expected return (dest_len + src_len): %lu + %lu = %lu\n", strlen("Prefix"), strlen(""), strlen("Prefix") + strlen(""));
    printf("--------------------------------------------------\n\n");

    // --- ทดสอบที่ 6: size = 0 ---
    char dest6[10] = "Test";
    char src6[] = "String";
    unsigned int size6 = 0;
    unsigned int result_ft_6;

    printf("--- Test Case 6: Size = 0 ---\n");
    printf("Initial dest6: \"%s\"\n", dest6);
    printf("src6: \"%s\"\n", src6);
    printf("Size limit: %u\n", size6);

    result_ft_6 = ft_strlcat(dest6, src6, size6);
    printf("ft_strlcat result: \"%s\" (Return: %u)\n", dest6, result_ft_6);
    // ตาม spec strlcat ถ้า size = 0, ควรคืนค่า src_len (หรือ dest_len + src_len)
    // ในกรณีนี้ dest_len จะเป็น 0 (เพราะ while loop dest_len < size) ดังนั้น 0 + src_len
    printf("Expected return (dest_len + src_len with dest_len limited by size): 0 + %lu = %lu\n", strlen("String"), strlen("String"));
    printf("--------------------------------------------------\n\n");


    return (0);
}