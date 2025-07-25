#include <stdio.h>

// ฟังก์ชัน ft_swap ที่ใช้พอยน์เตอร์ (ทำงานได้)
void ft_swap(int *a, int *b) {
    printf("\n=== ภายในฟังก์ชัน ft_swap ===\n");
    printf("ที่อยู่ของพอยน์เตอร์ a: %p\n", (void*)&a);
    printf("ค่าของพอยน์เตอร์ a (ชี้ไปที่): %p\n", (void*)a);
    printf("ค่าที่ a ชี้ไป (*a): %d\n", *a);
    printf("ที่อยู่ของพอยน์เตอร์ b: %p\n", (void*)&b);
    printf("ค่าของพอยน์เตอร์ b (ชี้ไปที่): %p\n", (void*)b);
    printf("ค่าที่ b ชี้ไป (*b): %d\n", *b);
    
    printf("\n--- เริ่มการสลับ ---\n");
    int temp;
    printf("1. สร้างตัวแปร temp\n");
    
    temp = *a;
    printf("2. temp = *a → temp = %d\n", temp);
    
    *a = *b;
    printf("3. *a = *b → ตอนนี้ *a = %d\n", *a);
    
    *b = temp;
    printf("4. *b = temp → ตอนนี้ *b = %d\n", *b);
    
    printf("--- การสลับเสร็จสิ้น ---\n");
}

// ฟังก์ชันที่ไม่ทำงาน (Pass by Value)
void wrong_swap(int a, int b) {
    printf("\n=== ภายในฟังก์ชัน wrong_swap (ไม่ทำงาน) ===\n");
    printf("ค่า a ที่ได้รับ: %d (ที่อยู่: %p)\n", a, (void*)&a);
    printf("ค่า b ที่ได้รับ: %d (ที่อยู่: %p)\n", b, (void*)&b);
    
    int temp = a;
    a = b;
    b = temp;
    
    printf("หลังสลับใน wrong_swap: a = %d, b = %d\n", a, b);
    printf("(แต่ไม่ส่งผลต่อตัวแปรต้นฉบับ!)\n");
}

int main() {
    printf("🧪 การทดสอบ ft_swap และพอยน์เตอร์\n");
    printf("==========================================\n");
    
    // ประกาศตัวแปร
    int x = 20;
    int y = 10;
    
    printf("\n📊 ข้อมูลเริ่มต้น:\n");
    printf("ตัวแปร x = %d (ที่อยู่: %p)\n", x, (void*)&x);
    printf("ตัวแปร y = %d (ที่อยู่: %p)\n", y, (void*)&y);
    
    // แสดงความแตกต่างของ operators
    printf("\n🔍 ทดสอบ operators กับตัวแปร x:\n");
    printf("x      = %d    (ค่าของ x)\n", x);
    printf("&x     = %p    (ที่อยู่ของ x)\n", (void*)&x);
    
    // สร้างพอยน์เตอร์เพื่อทดสอบ
    int *ptr = &x;
    printf("\nสร้างพอยน์เตอร์: int *ptr = &x;\n");
    printf("ptr    = %p    (ค่าของ ptr - ชี้ไปที่)\n", (void*)ptr);
    printf("*ptr   = %d    (ค่าที่ ptr ชี้ไป)\n", *ptr);
    printf("&ptr   = %p    (ที่อยู่ของ ptr เอง)\n", (void*)&ptr);
    
    printf("\n" "=" "40\n");
    printf("🧪 ทดสอบที่ 1: ใช้ wrong_swap (Pass by Value)\n");
    printf("ก่อนเรียก wrong_swap: x = %d, y = %d\n", x, y);
    
    wrong_swap(x, y);
    
    printf("หลังเรียก wrong_swap: x = %d, y = %d\n", x, y);
    printf("👎 ผลลัพธ์: ไม่เปลี่ยน! (เพราะ Pass by Value)\n");
    
    printf("\n" "=" "40\n");
    printf("🧪 ทดสอบที่ 2: ใช้ ft_swap (Pass by Reference)\n");
    printf("ก่อนเรียก ft_swap: x = %d, y = %d\n", x, y);
    
    ft_swap(&x, &y);
    
    printf("\nหลังเรียก ft_swap: x = %d, y = %d\n", x, y);
    printf("👍 ผลลัพธ์: สลับสำเร็จ! (เพราะ Pass by Reference)\n");
    
    printf("\n" "=" "40\n");
    printf("🎯 สรุป:\n");
    printf("• ft_swap(&x, &y) ส่งที่อยู่หน่วยความจำ\n");
    printf("• ฟังก์ชันแก้ไขค่าต้นฉบับได้โดยตรง\n");
    printf("• wrong_swap(x, y) ส่งเพียงค่าที่คัดลอกมา\n");
    printf("• ฟังก์ชันแก้ไขแค่สำเนา ไม่กระทบต้นฉบับ\n");
    
    // ทดสอบเพิ่มเติม: แสดงขนาดของตัวแปรต่างๆ
    printf("\n📏 ขนาดของตัวแปรในระบบนี้:\n");
    printf("sizeof(int)   = %lu bytes\n", sizeof(int));
    printf("sizeof(int*)  = %lu bytes\n", sizeof(int*));
    printf("sizeof(int**) = %lu bytes\n", sizeof(int**));
    
    return 0;
}

/* 
💡 วิธีการ Compile และรัน:
gcc -o test_swap pointer_test.c
./test_swap

🔧 หรือใช้คำสั่งเดียว:
gcc pointer_test.c && ./a.out

📝 ผลลัพธ์ที่คาดหวัง:
- wrong_swap จะไม่เปลี่ยนค่า x, y
- ft_swap จะสลับค่า x, y สำเร็จ
- จะเห็นที่อยู่หน่วยความจำต่างๆ ชัดเจน
*/