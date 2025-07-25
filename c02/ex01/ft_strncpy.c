#include <unistd.h> // สำหรับ NULL หากจำเป็นต้องใช้ แต่โดยทั่วไป strncpy ไม่ได้ใช้

char *ft_strncpy(char *dest, const char *src, unsigned int n)
{
    unsigned int i;

    i = 0;
    while (src[i] != '\0' && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }

    return (dest);
    
}

#include <stdio.h>

int main()
{
    char    dest1[90];
    char    dest2[20];
    char    src[] = "Hello World";

    ft_strncpy(dest1, src, 15);
    printf("%s\n", dest1);

    // // ตัวอย่างที่อันตราย
    // char small_dest[5];
    // ft_strncpy(small_dest, "Hello World", 11); // Overflow!
    // printf("%s\n", small_dest);

    // char dest[10];
    // ft_strncpy(dest, "Hello World", 10); // ไม่มี null terminator
    // printf("%s\n", dest); // อาจพิมพ์ garbage data

    // char dest3[20];
    // ft_strncpy(dest3, "Hi", 5); // dest[2-4] = '\0', dest[5-19] = uninitialized
    // printf("%s\n", dest3);

    return 0;
}





// // ---------------------------------------------------------------------------
// // ตัวอย่างการใช้งาน (สำหรับทดสอบเท่านั้น ไม่ต้องรวมอยู่ในไฟล์ส่งงาน ft_strncpy.c)

// #include <stdio.h>
// #include <string.h> // สำหรับเทียบกับ strncpy ของระบบ

// int main()
// {
//     char    dest1[20];
//     char    dest2[20];
//     char    src[] = "Hello World";

//     // ทดสอบกรณี n < ความยาวของ src
//     printf("--- Test Case 1: n < strlen(src) ---\n");
//     memset(dest1, 'A', 20); // เติมด้วย 'A' เพื่อดูว่ามีการเขียนทับแค่ไหน
//     memset(dest2, 'A', 20);
//     ft_strncpy(dest1, src, 5);
//     strncpy(dest2, src, 5);
//     printf("ft_strncpy result: '%s'\n", dest1); // ควรจะเป็น "HelloAAAAAAAAAAAAAAA"
//     printf("strncpy result:    '%s'\n", dest2); // ควรจะเป็น "HelloAAAAAAAAAAAAAAA"
//     printf("Comparison: %s\n", strcmp(dest1, dest2) == 0 ? "MATCH" : "MISMATCH");
//     printf("Length check (ft_strncpy): %lu\n", strlen(dest1)); // อาจจะน้อยกว่า 20 หรือเท่ากับ 5 ถ้าเป็น "Hello"
//     printf("Length check (strncpy): %lu\n", strlen(dest2));

//     printf("\n");

//     // ทดสอบกรณี n > ความยาวของ src (และควรเติม '\0')
//     printf("--- Test Case 2: n > strlen(src) ---\n");
//     memset(dest1, 'A', 20);
//     memset(dest2, 'A', 20);
//     ft_strncpy(dest1, src, 15);
//     strncpy(dest2, src, 15);
//     printf("ft_strncpy result: '%s'\n", dest1); // ควรจะเป็น "Hello World\0\0\0..."
//     printf("strncpy result:    '%s'\n", dest2); // ควรจะเป็น "Hello World\0\0\0..."
//     printf("Comparison: %s\n", memcmp(dest1, dest2, 20) == 0 ? "MATCH" : "MISMATCH"); // ใช้ memcmp เพราะอาจมี '\0' กลางสาย
//     printf("Length check (ft_strncpy): %lu\n", strlen(dest1)); // ควรจะเป็น 11
//     printf("Length check (strncpy): %lu\n", strlen(dest2)); // ควรจะเป็น 11

//     printf("\n");

//     // ทดสอบกรณี n = ความยาวของ src
//     printf("--- Test Case 3: n = strlen(src) ---\n");
//     memset(dest1, 'A', 20);
//     memset(dest2, 'A', 20);
//     ft_strncpy(dest1, src, strlen(src));
//     strncpy(dest2, src, strlen(src));
//     printf("ft_strncpy result: '%s'\n", dest1); // ควรเป็น "Hello WorldAAAAAAAA"
//     printf("strncpy result:    '%s'\n", dest2); // ควรเป็น "Hello WorldAAAAAAAA"
//     printf("Comparison: %s\n", memcmp(dest1, dest2, 20) == 0 ? "MATCH" : "MISMATCH");
//     printf("Length check (ft_strncpy): %lu\n", strlen(dest1)); // ควรเป็น 11
//     printf("Length check (strncpy): %lu\n", strlen(dest2)); // ควรเป็น 11

//     printf("\n");

//     // ทดสอบกรณี src เป็นสตริงว่าง
//     printf("--- Test Case 4: Empty src string ---\n");
//     char empty_src[] = "";
//     memset(dest1, 'A', 20);
//     memset(dest2, 'A', 20);
//     ft_strncpy(dest1, empty_src, 5);
//     strncpy(dest2, empty_src, 5);
//     printf("ft_strncpy result: '%s'\n", dest1); // ควรจะเป็น "\0\0\0\0\0AAAAAAAAAAAAAAA"
//     printf("strncpy result:    '%s'\n", dest2); // ควรจะเป็น "\0\0\0\0\0AAAAAAAAAAAAAAA"
//     printf("Comparison: %s\n", memcmp(dest1, dest2, 20) == 0 ? "MATCH" : "MISMATCH");
//     printf("Length check (ft_strncpy): %lu\n", strlen(dest1)); // ควรเป็น 0
//     printf("Length check (strncpy): %lu\n", strlen(dest2)); // ควรเป็น 0

//     return 0;
//}