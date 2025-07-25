#include <stdio.h> // สำหรับ printf

int main() {
    // --- ตัวอย่างสำหรับ char * (ชี้ไปที่ตัวอักษร / string) ---
    char my_char_array[] = "Hello"; // อาร์เรย์ของ char
    char *char_ptr = my_char_array; // char_ptr ชี้ไปที่ 'H'

    printf("--- ทดสอบ char * ---\n");
    printf("String: \"%s\"\n", my_char_array);
    printf("ขนาดของ char: %lu ไบต์\n", sizeof(char)); // โดยทั่วไปคือ 1 ไบต์
    printf("ที่อยู่เริ่มต้นของ char_ptr: %p (อักขระ '%c')\n", (void *)char_ptr, *char_ptr);

    // เลื่อน char_ptr ไป 1 ตำแหน่ง
    char_ptr++;
    printf("หลังจาก char_ptr++ ครั้งที่ 1: %p (อักขระ '%c')\n", (void *)char_ptr, *char_ptr); // ควรชี้ไปที่ 'e'

    // เลื่อน char_ptr ไปอีก 1 ตำแหน่ง
    char_ptr++;
    printf("หลังจาก char_ptr++ ครั้งที่ 2: %p (อักขระ '%c')\n", (void *)char_ptr, *char_ptr); // ควรชี้ไปที่ 'l'

    printf("\n");

    // --- ตัวอย่างสำหรับ int * (ชี้ไปที่จำนวนเต็ม) ---
    int my_int_array[] = {10, 20, 30, 40, 50}; // อาร์เรย์ของ int
    int *int_ptr = my_int_array; // int_ptr ชี้ไปที่ 10

    printf("--- ทดสอบ int * ---\n");
    printf("อาร์เรย์ Int: {%d, %d, %d, %d, %d}\n", my_int_array[0], my_int_array[1], my_int_array[2], my_int_array[3], my_int_array[4]);
    printf("ขนาดของ int: %lu ไบต์\n", sizeof(int)); // โดยทั่วไปคือ 4 ไบต์ (บนระบบส่วนใหญ่)
    printf("ที่อยู่เริ่มต้นของ int_ptr: %p (ค่า %d)\n", (void *)int_ptr, *int_ptr);

    // เลื่อน int_ptr ไป 1 ตำแหน่ง
    int_ptr++;
    printf("หลังจาก int_ptr++ ครั้งที่ 1: %p (ค่า %d)\n", (void *)int_ptr, *int_ptr); // ควรชี้ไปที่ 20

    // เลื่อน int_ptr ไปอีก 1 ตำแหน่ง
    int_ptr++;
    printf("หลังจาก int_ptr++ ครั้งที่ 2: %p (ค่า %d)\n", (void *)int_ptr, *int_ptr); // ควรชี้ไปที่ 30

    printf("\n");

    // --- การเปรียบเทียบขนาดของพอยน์เตอร์เอง ---
    // (ไม่เกี่ยวกับสิ่งที่พอยน์เตอร์ชี้ แต่เป็นขนาดของตัวแปรพอยน์เตอร์เอง)
    printf("--- ขนาดของตัวแปรพอยน์เตอร์ ---\n");
    printf("ขนาดของ char *: %lu ไบต์\n", sizeof(char *)); // โดยทั่วไป 8 ไบต์ (บนระบบ 64-bit) หรือ 4 ไบต์ (บนระบบ 32-bit)
    printf("ขนาดของ int *: %lu ไบต์\n", sizeof(int *));   // โดยทั่วไป 8 ไบต์ (บนระบบ 64-bit) หรือ 4 ไบต์ (บนระบบ 32-bit)
    printf("ขนาดของ void *: %lu ไบต์\n", sizeof(void *)); // ขนาดของพอยน์เตอร์จะเท่ากันหมด ไม่ว่ามันจะชี้ไปที่อะไร
    
    return 0;
}