#include <unistd.h>
#include <stdio.h>

// ฟังก์ชัน ft_putstr เดิม
void ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

// เวอร์ชันที่อธิบายการทำงานแบบละเอียด
void ft_putstr_explained(char *str)
{
    printf("\n🔍 Analyzing string: \"%s\"\n", str);
    printf("String address: %p\n", (void*)str);
    printf("Character by character:\n");
    
    int i = 0;
    while (str[i] != '\0')
    {
        printf("str[%d] = '%c' (ASCII: %d, Address: %p)\n", 
               i, str[i], (int)str[i], (void*)&str[i]);
        
        write(1, &str[i], 1);  // เขียนทีละตัวอักษร
        i++;
    }
    printf("\nFound null terminator '\\0' at position %d\n", i);
    printf("Total characters written: %d\n", i);
}

// เวอร์ชันที่ใช้ pointer arithmetic
void ft_putstr_pointer(char *str)
{
    printf("\n🎯 Using pointer arithmetic:\n");
    printf("Original pointer: %p\n", (void*)str);
    
    while (*str != '\0')  // ใช้ *str แทน str[i]
    {
        printf("Current char: '%c' at %p\n", *str, (void*)str);
        write(1, str, 1);  // ส่ง pointer ตรงๆ (ไม่ต้อง &)
        str++;             // เลื่อน pointer ไปข้างหน้า
    }
}

// เปรียบเทียบกับ printf
void compare_methods(char *str)
{
    printf("\n📊 เปรียบเทียบวิธีการพิมพ์:\n");
    
    printf("1. ใช้ printf: ");
    printf("%s", str);
    
    printf("2. ใช้ ft_putstr: ");
    ft_putstr(str);
    
    printf("3. ใช้ write ตรงๆ: ");
    write(1, str, 13); // เขียนทั้ง string ครั้งเดียว (ต้องนับตัวอักษร)
    
    printf("\n");
}

// ทดสอบกับ string ต่างๆ
void test_various_strings()
{
    printf("\n🧪 ทดสอบกับ string ต่างๆ:\n");
    
    char str1[] = "Hello";           // Array of char
    char *str2 = "World";            // Pointer to string literal
    char str3[] = {'H', 'i', '\0'};  // Array กำหนดทีละตัว
    char str4[] = "";                // Empty string
    
    printf("\n1. Array of char:\n");
    ft_putstr_explained(str1);
    
    printf("\n2. String literal:\n");  
    ft_putstr_explained(str2);
    
    printf("\n3. Character array:\n");
    ft_putstr_explained(str3);
    
    printf("\n4. Empty string:\n");
    ft_putstr_explained(str4);
}

// แสดงความแตกต่างระหว่าง write และ printf
void write_vs_printf()
{
    printf("\n⚖️  write() vs printf():\n");
    printf("=========================\n");
    
    printf("printf characteristics:\n");
    printf("• Buffered output (เก็บใน buffer ก่อน)\n");
    printf("• Higher level function\n");
    printf("• Supports formatting (%%d, %%s, etc.)\n");
    printf("• Calls write() internally\n\n");
    
    write(1, "write characteristics:\n", 23);
    write(1, "• Direct system call\n", 21);
    write(1, "• Unbuffered (เขียนทันที)\n", 33);
    write(1, "• No formatting support\n", 24);
    write(1, "• Lower level, faster\n", 22);
    write(1, "• Returns bytes written\n\n", 25);
}

int main(void)
{
    printf("🎬 การวิเคราะห์ ft_putstr function\n");
    printf("===================================\n");
    
    // ทดสอบฟังก์ชันเดิม
    printf("\n📝 ทดสอบ ft_putstr เดิม:\n");
    ft_putstr("Hello, World!\n");
    
    // วิเคราะห์การทำงานละเอียด
    ft_putstr_explained("Hello!");
    
    // ทดสอบ pointer arithmetic
    ft_putstr_pointer("Hi!\n");
    
    // เปรียบเทียบวิธีการ
    compare_methods("Test string\n");
    
    // ทดสอบ string ต่างๆ
    test_various_strings();
    
    // เปรียบเทียบ write vs printf
    write_vs_printf();
    
    // แสดงข้อมูล string literal
    printf("🔬 String Literal Analysis:\n");
    char *literal = "Hello, World!\n";
    printf("String: \"%s\"", literal);
    printf("Address: %p\n", (void*)literal);
    printf("Length: %lu characters\n", sizeof("Hello, World!\n") - 1);
    printf("Memory: ");
    for(int i = 0; literal[i]; i++) {
        printf("[%c]", literal[i] == '\n' ? 'n' : literal[i]);
    }
    printf("[\\0]\n");
    
    printf("\n🎯 สรุป ft_putstr:\n");
    printf("1. รับ char* (pointer to string)\n");
    printf("2. วนลูปจนเจอ '\\0' (null terminator)\n");  
    printf("3. ใช้ write() เขียนทีละตัวอักษร\n");
    printf("4. ไม่ใช้ formatting, เขียนตรงๆ\n");
    printf("5. เหมาะสำหรับ low-level programming\n");
    
    return 0;
}