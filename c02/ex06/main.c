#include <stdio.h> // สำหรับ printf
#include <stdbool.h> // สำหรับ bool และ true/false (ไม่จำเป็นต้องใช้ใน C เก่า แต่ดีกว่าสำหรับการอ่าน)
#include <string.h>   // *** เพิ่มบรรทัดนี้เพื่อแก้ไข warning ของ strlen ***

// Prototype ของฟังก์ชันของคุณ (ต้องมีในไฟล์ ft_str_is_printable.c หรือรวมอยู่ใน main.c นี้)
int ft_str_is_printable(char *str);

int main() {
    char *test_strings[] = {
        "Hello World!",       // มีอักขระที่พิมพ์ได้ทั้งหมด
        "12345",              // มีตัวเลขที่พิมพ์ได้ทั้งหมด
        "!@#$%^&*()",         // มีสัญลักษณ์ที่พิมพ์ได้ทั้งหมด
        "  ",                 // มีช่องว่างที่พิมพ์ได้ทั้งหมด
        "",                   // สตริงว่าง
        "Hello\nWorld",       // มี newline (ไม่พิมพ์ได้)
        "Hello\tWorld",       // มี tab (ไม่พิมพ์ได้)
        "Hello\x01World",     // มี SOH (Start of Heading) (ไม่พิมพ์ได้)
        "~",                  // ขอบบนของอักขระที่พิมพ์ได้
        " "                   // ขอบล่างของอักขระที่พิมพ์ได้
    };

    int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    printf("--- Testing ft_str_is_printable ---\n");

    for (int i = 0; i < num_tests; i++) {
        int result = ft_str_is_printable(test_strings[i]);
        printf("String: \"%s\" (Length: %lu) -> Is Printable: %s\n",
               test_strings[i],
               strlen(test_strings[i]), // ต้อง include <string.h> ถ้าจะใช้ strlen
               result ? "True" : "False");
    }

    return 0;
}