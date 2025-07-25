#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr_non_printable(char *str)
{
    int i;
    char hex_digits[] = "0123456789abcdef";
    
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 32 && str[i] <= 126)
        {
            // ตัวอักษรที่สามารถพิมพ์ได้ (ASCII 32-126)
            ft_putchar(str[i]);
        }
        else
        {
            // ตัวอักษรที่ไม่สามารถพิมพ์ได้
            ft_putchar('\\');
            ft_putchar(hex_digits[(unsigned char)str[i] / 16]);
            ft_putchar(hex_digits[(unsigned char)str[i] % 16]);
        }
        i++;
    }
}

int main(void)
{
    // Test 1: Basic example from exercise
    printf("Test 1 - Basic example:\n");
    printf("Input: \"Hello\\nHow are you?\"\n");
    printf("Output: ");
    ft_putstr_non_printable("Hello\nHow are you?");
    printf("\n");
    printf("Expected: Hello\\0aHow are you?\n\n");
    
    // Test 2: Various non-printable characters
    printf("Test 2 - Various non-printable:\n");
    printf("Input: \"Tab\\tNewline\\nCarriage Return\\r\"\n");
    printf("Output: ");
    ft_putstr_non_printable("Tab\tNewline\nCarriage Return\r");
    printf("\n\n");
    
    // Test 3: String with all printable characters
    printf("Test 3 - All printable:\n");
    printf("Input: \"Hello World 123!@#\"\n");
    printf("Output: ");
    ft_putstr_non_printable("Hello World 123!@#");
    printf("\n\n");
    
    // Test 4: String with null character in middle
    printf("Test 4 - With null character:\n");
    printf("Input: \"Hello\\0World\" (will stop at null)\n");
    printf("Output: ");
    char test4[] = "Hello\0World";
    ft_putstr_non_printable(test4);
    printf("\n\n");
    
    // Test 5: Empty string
    printf("Test 5 - Empty string:\n");
    printf("Input: \"\"\n");
    printf("Output: ");
    ft_putstr_non_printable("");
    printf("\n\n");
    
    // Test 6: String with control characters
    printf("Test 6 - Control characters:\n");
    printf("Input: String with ASCII 1, 7, 27\n");
    printf("Output: ");
    char test6[] = "Start\001Bell\007Escape\033End";
    ft_putstr_non_printable(test6);
    printf("\n\n");
    
    // Test 7: High ASCII values (extended ASCII)
    printf("Test 7 - Extended ASCII:\n");
    printf("Input: String with ASCII 200, 255\n");
    printf("Output: ");
    char test7[] = "High\310\377";
    ft_putstr_non_printable(test7);
    printf("\n\n");
    
    return (0);
}