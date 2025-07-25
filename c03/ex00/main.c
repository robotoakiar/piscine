#include <stdio.h> // สำหรับ printf
#include <string.h> // สำหรับ strcmp (ใช้เปรียบเทียบกับ ft_strcmp)
#include <stdlib.h> // สำหรับ EXIT_SUCCESS, EXIT_FAILURE

// ต้องแน่ใจว่าไฟล์ ft_strcmp.c อยู่ในโปรเจกต์เดียวกัน
// หรือคุณอาจจะคัดลอกโค้ด ft_strcmp มาวางไว้ที่นี่โดยตรง
int	ft_strcmp(char *s1, char *s2); // Prototype ของฟังก์ชันของคุณ

int main() {
    // --- Test Cases สำหรับ ft_strcmp ---

    printf("--- Testing ft_strcmp ---\n\n");

    // Test Case 1: สตริงเท่ากัน
    char *s1_tc1 = "Hello";
    char *s2_tc1 = "Hello";
    int result_ft_tc1 = ft_strcmp(s1_tc1, s2_tc1);
    int expected_tc1 = 0; // คาดหวัง 0
    printf("Test 1: \"%s\" vs \"%s\"\n", s1_tc1, s2_tc1);
    printf("  ft_strcmp result: %d (Expected: %d) -> %s\n", result_ft_tc1, expected_tc1,
           (result_ft_tc1 == expected_tc1) ? "PASSED" : "FAILED");

    // Test Case 2: s1 น้อยกว่า s2 (ตัวอักษรตัวแรกแตกต่างกัน)
    char *s1_tc2 = "apple";
    char *s2_tc2 = "banana";
    int result_ft_tc2 = ft_strcmp(s1_tc2, s2_tc2);
    // int expected_tc2 = strcmp(s1_tc2, s2_tc2); // ถ้าอยากเทียบกับ strcmp จริงๆ
    printf("Test 2: \"%s\" vs \"%s\"\n", s1_tc2, s2_tc2);
    printf("  ft_strcmp result: %d (Expected: < 0) -> %s\n", result_ft_tc2,
           (result_ft_tc2 < 0) ? "PASSED" : "FAILED");

    // Test Case 3: s1 มากกว่า s2 (ตัวอักษรตัวแรกแตกต่างกัน)
    char *s1_tc3 = "zebra";
    char *s2_tc3 = "yak";
    int result_ft_tc3 = ft_strcmp(s1_tc3, s2_tc3);
    // int expected_tc3 = strcmp(s1_tc3, s2_tc3);
    printf("Test 3: \"%s\" vs \"%s\"\n", s1_tc3, s2_tc3);
    printf("  ft_strcmp result: %d (Expected: > 0) -> %s\n", result_ft_tc3,
           (result_ft_tc3 > 0) ? "PASSED" : "FAILED");

    // Test Case 4: s1 สั้นกว่า s2 แต่เริ่มต้นเหมือนกัน
    char *s1_tc4 = "test";
    char *s2_tc4 = "testing";
    int result_ft_tc4 = ft_strcmp(s1_tc4, s2_tc4);
    // int expected_tc4 = strcmp(s1_tc4, s2_tc4);
    printf("Test 4: \"%s\" vs \"%s\"\n", s1_tc4, s2_tc4);
    printf("  ft_strcmp result: %d (Expected: < 0) -> %s\n", result_ft_tc4,
           (result_ft_tc4 < 0) ? "PASSED" : "FAILED");

    // Test Case 5: s1 ยาวกว่า s2 แต่เริ่มต้นเหมือนกัน
    char *s1_tc5 = "testing";
    char *s2_tc5 = "test";
    int result_ft_tc5 = ft_strcmp(s1_tc5, s2_tc5);
    // int expected_tc5 = strcmp(s1_tc5, s2_tc5);
    printf("Test 5: \"%s\" vs \"%s\"\n", s1_tc5, s2_tc5);
    printf("  ft_strcmp result: %d (Expected: > 0) -> %s\n", result_ft_tc5,
           (result_ft_tc5 > 0) ? "PASSED" : "FAILED");

    // Test Case 6: สตริงว่างเปล่า
    char *s1_tc6 = "";
    char *s2_tc6 = "";
    int result_ft_tc6 = ft_strcmp(s1_tc6, s2_tc6);
    int expected_tc6 = 0;
    printf("Test 6: \"%s\" vs \"%s\"\n", s1_tc6, s2_tc6);
    printf("  ft_strcmp result: %d (Expected: %d) -> %s\n", result_ft_tc6, expected_tc6,
           (result_ft_tc6 == expected_tc6) ? "PASSED" : "FAILED");

    // Test Case 7: สตริงหนึ่งว่าง อีกสตริงไม่ว่าง (s1 ว่าง)
    char *s1_tc7 = "";
    char *s2_tc7 = "hello";
    int result_ft_tc7 = ft_strcmp(s1_tc7, s2_tc7);
    // int expected_tc7 = strcmp(s1_tc7, s2_tc7);
    printf("Test 7: \"%s\" vs \"%s\"\n", s1_tc7, s2_tc7);
    printf("  ft_strcmp result: %d (Expected: < 0) -> %s\n", result_ft_tc7,
           (result_ft_tc7 < 0) ? "PASSED" : "FAILED");

    // Test Case 8: สตริงหนึ่งว่าง อีกสตริงไม่ว่าง (s2 ว่าง)
    char *s1_tc8 = "world";
    char *s2_tc8 = "";
    int result_ft_tc8 = ft_strcmp(s1_tc8, s2_tc8);
    // int expected_tc8 = strcmp(s1_tc8, s2_tc8);
    printf("Test 8: \"%s\" vs \"%s\"\n", s1_tc8, s2_tc8);
    printf("  ft_strcmp result: %d (Expected: > 0) -> %s\n", result_ft_tc8,
           (result_ft_tc8 > 0) ? "PASSED" : "FAILED");

    // Test Case 9: สตริงที่มีตัวอักขระพิเศษ / ตัวเลข
    char *s1_tc9 = "123a";
    char *s2_tc9 = "123A"; // 'a' (97) vs 'A' (65)
    int result_ft_tc9 = ft_strcmp(s1_tc9, s2_tc9);
    // int expected_tc9 = strcmp(s1_tc9, s2_tc9);
    printf("Test 9: \"%s\" vs \"%s\"\n", s1_tc9, s2_tc9);
    printf("  ft_strcmp result: %d (Expected: > 0) -> %s\n", result_ft_tc9,
           (result_ft_tc9 > 0) ? "PASSED" : "FAILED");

    // Test Case 10: ตัวอักขระที่มีค่า ASCII สูง (เพื่อทดสอบ unsigned char cast)
    // โปรดทราบ: การแสดงผลตัวอักขระเหล่านี้อาจขึ้นอยู่กับ Terminal ของคุณ
    char *s1_tc10 = "résumé"; // 'é' (UTF-8 bytes: C3 A9)
    char *s2_tc10 = "resume";
    int result_ft_tc10 = ft_strcmp(s1_tc10, s2_tc10);
    // int expected_tc10 = strcmp(s1_tc10, s2_tc10);
    printf("Test 10: \"%s\" vs \"%s\"\n", s1_tc10, s2_tc10);
    printf("  ft_strcmp result: %d (Expected: > 0 or < 0 depending on locale/encoding, but non-zero) -> %s\n", result_ft_tc10,
           (result_ft_tc10 != 0) ? "PASSED (non-zero)" : "FAILED (zero)"); // ตรวจสอบแค่ว่าไม่เท่ากับ 0
    // ข้อควรระวัง: สำหรับตัวอักขระ multi-byte (UTF-8) strcmp จะเปรียบเทียบทีละ byte ซึ่งอาจไม่ตรงกับการเปรียบเทียบ "ตัวอักษร" ที่คนเข้าใจ
    // แต่สำหรับ exercise นี้คือการทำตาม strcmp ซึ่งเปรียบเทียบทีละไบต์

    printf("\n--- All tests completed ---\n");

    return EXIT_SUCCESS;
}