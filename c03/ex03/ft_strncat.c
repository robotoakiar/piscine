char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    char *original_dest = dest;
    
    // หาตำแหน่งสิ้นสุดของ dest (หา null terminator)
    while (*dest != '\0')
    {
        dest++;
    }
    
    // คัดลอกตัวอักษรจาก src ไป dest สูงสุด nb ตัวอักษร
    while (nb > 0 && *src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
        nb--;
    }
    
    // เพิ่ม null terminator ที่ท้าย
    *dest = '\0';
    
    // คืนค่าตำแหน่งเริ่มต้นของ dest
    return (original_dest);
}