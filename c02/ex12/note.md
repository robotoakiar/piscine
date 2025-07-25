#include <unistd.h> // สำหรับฟังก์ชัน write()

// ฟังก์ชันช่วยเหลือ: พิมพ์อักขระเดียวออกทาง Standard Output
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// ฟังก์ชันช่วยเหลือ: แปลงและพิมพ์ค่า byte เป็นเลขฐานสิบหก 2 หลัก
void ft_print_hex(unsigned char byte)
{
    // อาร์เรย์สำหรับแปลงตัวเลข 0-15 เป็นอักขระฐานสิบหก
    char hex[] = "0123456789abcdef";
    // พิมพ์หลักแรก (ค่าหารด้วย 16)
    ft_putchar(hex[byte / 16]);
    // พิมพ์หลักที่สอง (ค่า modulo 16)
    ft_putchar(hex[byte % 16]);
}

// ฟังก์ชันช่วยเหลือ: พิมพ์ที่อยู่หน่วยความจำในรูปแบบเลขฐานสิบหก 16 หลัก
void ft_print_address(void *addr)
{
    // แปลงพอยน์เตอร์เป็น unsigned long เพื่อให้สามารถจัดการกับที่อยู่ขนาดใหญ่ได้
    unsigned long address = (unsigned long)addr;
    char hex[] = "0123456789abcdef"; // อักขระฐานสิบหก
    int i = 15; // เริ่มต้นจากบิตสูงสุด (64 บิต / 4 บิตต่อหลัก hex = 16 หลัก)

    // วนลูปเพื่อพิมพ์แต่ละหลักฐานสิบหกจากซ้ายไปขวา
    // โดยใช้ bit shift และ bitwise AND เพื่อดึงค่า 4 บิต (nibble) ออกมา
    while (i >= 0)
    {
        ft_putchar(hex[(address >> (i * 4)) & 0xF]);
        i--;
    }
    // เพิ่ม ": " หลังที่อยู่ตามข้อกำหนด
    write(1, ": ", 2);
}

// ฟังก์ชันช่วยเหลือ: พิมพ์หนึ่งบรรทัดของข้อมูลหน่วยความจำ (16 ไบต์)
void ft_print_line(void *addr, unsigned int size)
{
    unsigned char *ptr = (unsigned char *)addr; // แปลงพอยน์เตอร์เป็น unsigned char เพื่อเข้าถึงไบต์
    unsigned int i = 0; // ตัวนับสำหรับไบต์ในบรรทัดปัจจุบัน

    // คอลัมน์ที่ 2: พิมพ์เนื้อหาในรูปแบบเลขฐานสิบหก
    while (i < 16) // วนลูป 16 ครั้งสำหรับ 16 ไบต์ในหนึ่งบรรทัด
    {
        if (i < size) // ตรวจสอบว่ายังมีข้อมูลให้พิมพ์ในบรรทัดนี้หรือไม่ (กรณีบรรทัดสุดท้าย)
            ft_print_hex(ptr[i]); // พิมพ์ค่าไบต์เป็นเลขฐานสิบหก 2 หลัก
        else
            write(1, "  ", 2); // ถ้าเกินขนาด ให้พิมพ์ช่องว่าง 2 ตัวแทน (สำหรับ padding)

        // เพิ่มช่องว่าง 1 ตัวหลังทุกๆ 2 ไบต์ (4 หลัก hex) ตามข้อกำหนด "a space every two characters"
        if (i % 2 == 1)
            ft_putchar(' ');
        i++;
    }
    ft_putchar(' '); // เพิ่มช่องว่าง 1 ตัวคั่นระหว่างคอลัมน์ hex และ char

    // คอลัมน์ที่ 3: พิมพ์เนื้อหาในรูปแบบอักขระที่พิมพ์ได้
    i = 0; // รีเซ็ตตัวนับ
    while (i < 16 && i < size) // วนลูป 16 ครั้ง หรือจนกว่าจะหมดข้อมูล
    {
        // ตรวจสอบว่าเป็นอักขระที่พิมพ์ได้ (ASCII 32-126)
        if (ptr[i] >= 32 && ptr[i] <= 126)
            ft_putchar(ptr[i]); // พิมพ์อักขระนั้น
        else
            ft_putchar('.'); // ถ้าไม่สามารถพิมพ์ได้ ให้พิมพ์จุด '.'
        i++;
    }
    ft_putchar('\n'); // ขึ้นบรรทัดใหม่เมื่อจบบรรทัด
}

// ฟังก์ชันหลัก: แสดงผลพื้นที่หน่วยความจำ
void *ft_print_memory(void *addr, unsigned int size)
{
    unsigned char *ptr = (unsigned char *)addr; // พอยน์เตอร์สำหรับวนลูปผ่านหน่วยความจำ
    unsigned int i = 0; // ตัวนับสำหรับตำแหน่งปัจจุบันในหน่วยความจำ
    unsigned int line_size; // ขนาดของข้อมูลในบรรทัดปัจจุบัน

    // ถ้าขนาดเป็น 0 ให้คืนค่า addr ทันทีโดยไม่แสดงผลอะไรเลย
    if (size == 0)
        return (addr);

    // วนลูปผ่านหน่วยความจำทีละ 16 ไบต์ (หนึ่งบรรทัด)
    while (i < size)
    {
        // กำหนดขนาดของข้อมูลในบรรทัดปัจจุบัน
        if (size - i >= 16) // ถ้าข้อมูลที่เหลือมากกว่าหรือเท่ากับ 16 ไบต์
            line_size = 16; // ให้แสดง 16 ไบต์เต็ม
        else // ถ้าข้อมูลที่เหลือน้อยกว่า 16 ไบต์ (บรรทัดสุดท้าย)
            line_size = size - i; // ให้แสดงข้อมูลที่เหลือทั้งหมด

        ft_print_address(ptr + i); // พิมพ์ที่อยู่เริ่มต้นของบรรทัดนี้
        ft_print_line(ptr + i, line_size); // พิมพ์เนื้อหา hex และ char ของบรรทัดนี้
        i += 16; // เลื่อนไปยังจุดเริ่มต้นของบรรทัดถัดไป
    }
    return (addr); // คืนค่าพอยน์เตอร์เริ่มต้นตามข้อกำหนด
}

// ฟังก์ชันทดสอบการทำงาน
int main(void)
{
    // ตัวอย่างสตริงสำหรับทดสอบ
    char str[] = "Bonjour les*amis\t\t\n\tLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    
    // เรียกใช้ ft_print_memory โดยส่งสตริงและขนาดของสตริง (ลบ 1 สำหรับ null terminator)
    ft_print_memory(str, sizeof(str) - 1); 
    return (0);
}
