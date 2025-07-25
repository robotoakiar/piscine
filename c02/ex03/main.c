#include <stdio.h> // สำหรับ printf

// ประกาศโปรโตไทป์ของฟังก์ชันที่คุณกำลังจะสร้าง
// ต้องแน่ใจว่าได้รวมไฟล์ .c ที่มีฟังก์ชันนี้ หรือวางฟังก์ชันนี้ไว้ด้านบน
int ft_str_is_numeric(char *str);

int main() {
    // ตัวอย่างสตริงสำหรับทดสอบ
    char *test_str1 = "12345";       // มีแต่ตัวเลข
    char *test_str2 = "0";           // มีแต่ตัวเลข
    char *test_str3 = "abc123";      // มีตัวอักษรและตัวเลข
    char *test_str4 = "hello";       // มีแต่ตัวอักษร
    char *test_str5 = "";            // สตริงว่าง
    char *test_str6 = "123a";        // มีตัวเลขและตัวอักษร
    char *test_str7 = "12 34";       // มีช่องว่าง

    printf("Testing ft_str_is_numeric:\n");
    printf("----------------------------------\n");

    // ทดสอบ test_str1: "12345"
    printf("'%s' is numeric: %d (Expected: 1)\n", test_str1, ft_str_is_numeric(test_str1));

    // ทดสอบ test_str2: "0"
    printf("'%s' is numeric: %d (Expected: 1)\n", test_str2, ft_str_is_numeric(test_str2));

    // ทดสอบ test_str3: "abc123"
    printf("'%s' is numeric: %d (Expected: 0)\n", test_str3, ft_str_is_numeric(test_str3));

    // ทดสอบ test_str4: "hello"
    printf("'%s' is numeric: %d (Expected: 0)\n", test_str4, ft_str_is_numeric(test_str4));

    // ทดสอบ test_str5: "" (สตริงว่าง)
    printf("'%s' is numeric: %d (Expected: 1)\n", test_str5, ft_str_is_numeric(test_str5));

    // ทดสอบ test_str6: "123a"
    printf("'%s' is numeric: %d (Expected: 0)\n", test_str6, ft_str_is_numeric(test_str6));

    // ทดสอบ test_str7: "12 34"
    printf("'%s' is numeric: %d (Expected: 0)\n", test_str7, ft_str_is_numeric(test_str7));

    printf("----------------------------------\n");

    return 0;
}