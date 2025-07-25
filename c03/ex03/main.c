#include <stdio.h> // สำหรับ printf
#include <string.h> // สำหรับ strncat (เปรียบเทียบ) และ strlen (ไม่จำเป็น แต่มีประโยชน์)

// ถ้า ft_strncat ของคุณอยู่ในไฟล์อื่น ให้ #include "ft_strncat.h" หรือประกาศ prototype ที่นี่
// แต่ถ้าโค้ด ft_strncat อยู่ในไฟล์เดียวกันกับ main นี้ ไม่ต้องทำอะไรเพิ่ม
char *ft_strncat(char *dest, char *src, unsigned int nb); // Prototype ของฟังก์ชัน ft_strncat ของคุณ

int main() {
    // Test Case 1: การต่อสตริงปกติ (src สั้นกว่า nb)
    char dest1[50] = "Hello, ";
    char src1[] = "world!";
    unsigned int nb1 = 10;
    printf("--- Test Case 1 ---\n");
    printf("Original dest: \"%s\"\n", dest1);
    printf("Source: \"%s\"\n", src1);
    printf("nb: %u\n", nb1);
    ft_strncat(dest1, src1, nb1);
    printf("Result dest: \"%s\"\n", dest1); // คาดหวัง: "Hello, world!"
    printf("-------------------\n\n");

    // Test Case 2: src ยาวกว่า nb (ควรตัด src ที่ nb ตัวอักษร)
    char dest2[50] = "Programming is ";
    char src2[] = "fun and challenging!";
    unsigned int nb2 = 3; // จะต่อแค่ "fun"
    printf("--- Test Case 2 ---\n");
    printf("Original dest: \"%s\"\n", dest2);
    printf("Source: \"%s\"\n", src2);
    printf("nb: %u\n", nb2);
    ft_strncat(dest2, src2, nb2);
    printf("Result dest: \"%s\"\n", dest2); // คาดหวัง: "Programming is fun"
    printf("-------------------\n\n");

    // Test Case 3: nb เป็น 0 (ไม่ควรต่ออะไรเลย)
    char dest3[50] = "This should not change.";
    char src3[] = "Appended text.";
    unsigned int nb3 = 0;
    printf("--- Test Case 3 ---\n");
    printf("Original dest: \"%s\"\n", dest3);
    printf("Source: \"%s\"\n", src3);
    printf("nb: %u\n", nb3);
    ft_strncat(dest3, src3, nb3);
    printf("Result dest: \"%s\"\n", dest3); // คาดหวัง: "This should not change."
    printf("-------------------\n\n");

    // Test Case 4: src เป็นสตริงว่างเปล่า
    char dest4[50] = "Base string.";
    char src4[] = "";
    unsigned int nb4 = 5;
    printf("--- Test Case 4 ---\n");
    printf("Original dest: \"%s\"\n", dest4);
    printf("Source: \"%s\"\n", src4);
    printf("nb: %u\n", nb4);
    ft_strncat(dest4, src4, nb4);
    printf("Result dest: \"%s\"\n", dest4); // คาดหวัง: "Base string."
    printf("-------------------\n\n");
    
    // Test Case 5: dest เป็นสตริงว่างเปล่า (rare but possible)
    char dest5[50] = "";
    char src5[] = "Hello";
    unsigned int nb5 = 3;
    printf("--- Test Case 5 ---\n");
    printf("Original dest: \"%s\"\n", dest5);
    printf("Source: \"%s\"\n", src5);
    printf("nb: %u\n", nb5);
    ft_strncat(dest5, src5, nb5);
    printf("Result dest: \"%s\"\n", dest5); // คาดหวัง: "Hel"
    printf("-------------------\n\n");

    // Test Case 6: Buffer overflow check (make sure dest array is large enough!)
    // ในสถานการณ์จริง ต้องระวังเรื่อง buffer overflow มากๆ
    // ตัวอย่างนี้ dest6 มีขนาด 10, dest6_orig มีขนาด 10
    // dest6 มี "ABC" (3 chars + 1 null), เหลือ 6 bytes
    // src6 มี "DEFGHIJK" (8 chars + 1 null)
    // nb6 = 7
    // ควรจะต่อ 7 ตัวอักษร ("DEFGHIJ") -> dest6 กลายเป็น "ABCDEFGHIJ" (10 chars + null)
    char dest6[11] = "ABC"; // ขนาดเผื่อ null terminator
    char src6[] = "DEFGHIJK";
    unsigned int nb6 = 7; 
    printf("--- Test Case 6 (Buffer Check) ---\n");
    printf("Original dest: \"%s\" (size %lu)\n", dest6, sizeof(dest6));
    printf("Source: \"%s\" (size %lu)\n", src6, sizeof(src6));
    printf("nb: %u\n", nb6);
    // ตรวจสอบพื้นที่ว่างก่อนต่อ
    // Size of dest6 = 11 bytes. "ABC" takes 4 bytes (3 + null).
    // Remaining space for new chars = 11 - 4 = 7 bytes.
    // If nb6 is 7, it will fill exactly the remaining space.
    // If nb6 were 8, it would be an overflow if dest6 were char dest6[11].
    ft_strncat(dest6, src6, nb6);
    printf("Result dest: \"%s\"\n", dest6); // คาดหวัง: "ABCDEFGHIJ"
    printf("-------------------\n\n");


    return 0;
}