#include <stdio.h>



// return คือคำสั่งในภาษาโปรแกรมที่ใช้เพื่อ ยุติการทำงานของฟังก์ชันทันที 🛑 
// และ ส่งค่า (ถ้ามี) กลับ ไปยังจุดที่เรียกฟังก์ชันนั้นๆ ครับ


// ฟังก์ชันที่ตรวจสอบว่าเลขเป็นบวกหรือไม่
int isPositive(int num) {
    if (num > 0) {
        return 1; // ถ้า num เป็นบวก ให้ส่งค่า 1 กลับทันที
                  // โค้ดข้างล่างนี้จะไม่ถูกประมวลผลเลย
    }
    printf("Number is not positive.\n"); // บรรทัดนี้จะถูกประมวลผลก็ต่อเมื่อ num ไม่ใช่บวก
    return 0; // ถ้า num ไม่เป็นบวก ให้ส่งค่า 0 กลับ
}

int main() {
    int result1 = isPositive(5);  // เรียกใช้ isPositive ด้วย 5
    printf("Result for 5: %d\n", result1); // จะได้ 1 และไม่เห็นข้อความ "Number is not positive."

    printf("\n"); // เพิ่มบรรทัดว่าง

    int result2 = isPositive(-3); // เรียกใช้ isPositive ด้วย -3
    printf("Result for -3: %d\n", result2); // จะได้ 0 และเห็นข้อความ "Number is not positive."

    printf("\n"); // เพิ่มบรรทัดว่าง

    int result3 = isPositive(0);  // เรียกใช้ isPositive ด้วย 0
    printf("Result for 0: %d\n", result3);  // จะได้ 0 และเห็นข้อความ "Number is not positive."

    return 0; // ฟังก์ชัน main คืนค่า 0 บอกว่าโปรแกรมทำงานเสร็จสิ้นปกติ
}