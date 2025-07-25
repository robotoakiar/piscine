#include <stdio.h> // สำหรับ printf

// ฟังก์ชัน ft_str_is_alpha
int ft_str_is_alpha(char *str)
{
    int i;

    i = 0;
    // 1. จัดการกรณีสตริงว่างเปล่า
    // ถ้าสตริงว่างเปล่า (อักขระตัวแรกคือ '\0') ให้คืนค่า 1 ตามข้อกำหนด
    if (str[i] == '\0')
    {
        return 1;
    }

    // 2. วนลูปตรวจสอบทุกอักขระในสตริง
    // ลูปจะทำงานตราบเท่าที่ยังไม่เจอ null terminator (สิ้นสุดสตริง)
    while (str[i] != '\0')
    {
        // 3. ตรวจสอบว่าอักขระปัจจุบันเป็นตัวอักษรหรือไม่
        // เงื่อนไขที่ถูกต้อง:
        // (str[i] >= 'a' && str[i] <= 'z')  <-- ตรวจสอบตัวพิมพ์เล็ก (ระหว่าง 'a' ถึง 'z')
        // ||                                <-- หรือ
        // (str[i] >= 'A' && str[i] <= 'Z')  <-- ตรวจสอบตัวพิมพ์ใหญ่ (ระหว่าง 'A' ถึง 'Z')
        //
        // ถ้าเงื่อนไขนี้เป็นจริง (คือเป็นตัวอักษร)
        // แต่เราต้องการตรวจสอบว่า 'ไม่เป็น' ตัวอักษร จึงใช้ '!' นำหน้าทั้งก้อน
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
        {
            // ถ้า 'str[i]' ไม่ใช่ตัวอักษร (เงื่อนไข '!' เป็นจริง)
            // ก็แสดงว่าพบอักขระที่ไม่ใช่ตัวอักษรแล้ว
            return 0; // คืนค่า 0 ทันที และจบฟังก์ชัน
        }
        i++; // ถ้าเป็นตัวอักษร ก็เลื่อนไปยังอักขระถัดไป
    }

    // 4. ถ้าลูปทำงานจนจบโดยไม่เคยเจออักขระที่ไม่ใช่ตัวอักษรเลย
    // (นั่นคือ ไม่มี 'return 0;' ถูกเรียกใช้)
    // แสดงว่าสตริงนี้มีแต่ตัวอักษรทั้งหมด
    return 1; // คืนค่า 1
}

int main(void)
{
    // เพิ่มการทดสอบหลากหลายกรณีเพื่อให้มั่นใจว่าฟังก์ชันทำงานถูกต้อง
    printf("--- ft_str_is_alpha Tests ---\n");

    // 1. สตริงที่มีแต่ตัวอักษร
    printf("'%s': %d (Expected: 1)\n", "HelloWorld", ft_str_is_alpha("HelloWorld"));
    printf("'%s': %d (Expected: 1)\n", "abcdefg", ft_str_is_alpha("abcdefg"));
    printf("'%s': %d (Expected: 1)\n", "ABCDEFG", ft_str_is_alpha("ABCDEFG"));
    printf("'%s': %d (Expected: 1)\n", "MixEdCaSe", ft_str_is_alpha("MixEdCaSe"));

    // 2. สตริงที่มีอักขระที่ไม่ใช่ตัวอักษร
    printf("'%s': %d (Expected: 0)\n", "Hello World", ft_str_is_alpha("Hello World")); // มีช่องว่าง
    printf("'%s': %d (Expected: 0)\n", "Hello123", ft_str_is_alpha("Hello123"));       // มีตัวเลข
    printf("'%s': %d (Expected: 0)\n", "Hello!", ft_str_is_alpha("Hello!"));           // มีเครื่องหมายวรรคตอน
    printf("'%s': %d (Expected: 0)\n", "12345", ft_str_is_alpha("12345"));             // มีแต่ตัวเลข
    printf("'%s': %d (Expected: 0)\n", "!@#$", ft_str_is_alpha("!@#$"));               // มีแต่เครื่องหมายพิเศษ

    // 3. สตริงว่างเปล่า
    printf("'%s': %d (Expected: 1)\n", "", ft_str_is_alpha(""));

    return 0;
}