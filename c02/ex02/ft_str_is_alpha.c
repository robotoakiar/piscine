#include <stdio.h> // สำหรับ printf

// ต้องมีคำจำกัดความของ ft_str_is_alpha ที่นี่
// หาก ft_str_is_alpha อยู่ในไฟล์อื่น คุณจะต้องรวมไฟล์นั้น
// เช่น #include "ft_str_is_alpha.c" หรือประกาศ prototype ของมัน
int ft_str_is_alpha(char *str)
{
    int i;

    i = 0;
    if (str[i] == '\0')
    {
        return 1;
    }

    while (str[i] != '\0')
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
        {
            return 0;
        }
        i++;
    }

    return 1;
    
}

int main(void)
{
    printf("'%s': %d (Expected: 1)\n", "HelloWorld", ft_str_is_alpha("HelloWorld"));

}






// int main()
// {
//     // กรณีทดสอบ
//     printf("--- ft_str_is_alpha Tests ---\n");

//     // 1. สตริงที่มีแต่ตัวอักษร
//     printf("'%s': %d (Expected: 1)\n", "HelloWorld", ft_str_is_alpha("HelloWorld"));
//     printf("'%s': %d (Expected: 1)\n", "abcdefg", ft_str_is_alpha("abcdefg"));
//     printf("'%s': %d (Expected: 1)\n", "ABCDEFG", ft_str_is_alpha("ABCDEFG"));
//     printf("'%s': %d (Expected: 1)\n", "MixEdCaSe", ft_str_is_alpha("MixEdCaSe"));

//     // 2. สตริงที่มีอักขระที่ไม่ใช่ตัวอักษร
//     printf("'%s': %d (Expected: 0)\n", "Hello World", ft_str_is_alpha("Hello World")); // มีช่องว่าง
//     printf("'%s': %d (Expected: 0)\n", "Hello123", ft_str_is_alpha("Hello123"));       // มีตัวเลข
//     printf("'%s': %d (Expected: 0)\n", "Hello!", ft_str_is_alpha("Hello!"));           // มีเครื่องหมายวรรคตอน
//     printf("'%s': %d (Expected: 0)\n", "12345", ft_str_is_alpha("12345"));             // มีแต่ตัวเลข
//     printf("'%s': %d (Expected: 0)\n", "!@#$", ft_str_is_alpha("!@#$"));               // มีแต่เครื่องหมายพิเศษ

//     // 3. สตริงว่างเปล่า (กรณีเฉพาะ)
//     printf("'%s': %d (Expected: 1)\n", "", ft_str_is_alpha(""));

//     // 4. สตริง NULL (ควรหลีกเลี่ยงหรือจัดการในฟังก์ชันจริงเพื่อความปลอดภัย)
//     // การส่ง NULL เข้าไปอาจทำให้โปรแกรมพังได้หากไม่มีการตรวจสอบ
//     // สำหรับแบบฝึกหัดนี้ โดยทั่วไปจะถือว่าสตริงที่ส่งมาจะไม่ใช่ NULL
//     // หากต้องการทดสอบ NULL คุณต้องเพิ่มการตรวจสอบ NULL ใน ft_str_is_alpha
//     // เช่น: if (str == NULL) return 0; // หรืออะไรก็ตามที่คุณต้องการให้เกิดขึ้น

//     return 0;
// }