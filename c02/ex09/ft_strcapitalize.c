#include <stdio.h>

// ฟังก์ชันที่ 1: ตรวจสอบว่าเป็นตัวอักษรหรือตัวเลขหรือไม่
int is_alphanumeric(char c)
{
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'))
        return (1);
    return (0);
}

// ฟังก์ชันที่ 2: แปลงตัวพิมพ์เล็กเป็นพิมพ์ใหญ่
char to_uppercase(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

// ฟังก์ชันที่ 3: แปลงตัวพิมพ์ใหญ่เป็นพิมพ์เล็ก
char to_lowercase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

// ฟังก์ชันที่ 4: ประมวลผลตัวอักษรแต่ละตัว
char process_character(char c, int is_word_start)
{
    if (!is_alphanumeric(c))
        return (c);
        
    if (is_word_start)
        return (to_uppercase(c));
    else
        return (to_lowercase(c));
}

// ฟังก์ชันที่ 5: ฟังก์ชันหลัก ft_strcapitalize
char *ft_strcapitalize(char *str)
{
    int i;
    int is_start_of_word;
    
    i = 0;
    is_start_of_word = 1;
    
    while (str[i] != '\0')
    {
        if (is_alphanumeric(str[i]))
        {
            str[i] = process_character(str[i], is_start_of_word);
            is_start_of_word = 0;
        }
        else
        {
            is_start_of_word = 1;
        }
        i++;
    }
    return (str);
}

// // ฟังก์ชันทดสอบ
// void test_strcapitalize(char *input, char *description)
// {
//     printf("=== %s ===\n", description);
//     printf("Input:  \"%s\"\n", input);
//     ft_strcapitalize(input);
//     printf("Output: \"%s\"\n", input);
//     printf("---------------------\n");
// }

// // ฟังก์ชัน main สำหรับทดสอบ
// int main(void)
// {
//     // Test case 1: ตัวอย่างพื้นฐาน
//     char test1[] = "hello world";
//     test_strcapitalize(test1, "Basic Test");
    
//     // Test case 2: มีตัวเลขและเครื่องหมาย
//     char test2[] = "hello world! 42school is+nice";
//     test_strcapitalize(test2, "Original Example");
    
//     // Test case 3: ตัวพิมพ์ใหญ่ผสม
//     char test3[] = "HELLO WORLD ABC def";
//     test_strcapitalize(test3, "Mixed Cases");
    
//     // Test case 4: เครื่องหมายหลายตัว
//     char test4[] = "one!!two??three";
//     test_strcapitalize(test4, "Multiple Separators");
    
//     // Test case 5: เริ่มด้วยตัวเลข
//     char test5[] = "123abc 456def ghi789";
//     test_strcapitalize(test5, "Numbers and Letters");
    
//     // Test case 6: สตริงว่าง
//     char test6[] = "";
//     test_strcapitalize(test6, "Empty String");
    
//     // Test case 7: เฉพาะเครื่องหมาย
//     char test7[] = "!!!???@@@";
//     test_strcapitalize(test7, "Only Symbols");
    
//     return (0);
// }