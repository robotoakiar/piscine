char    *ft_strupcase(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        i++;  
    }  
    return (str); 
}

// char *ft_strupcase(char *str)
// {
//     char *orig = str; // เก็บจุดเริ่มต้นของสตริง

//     // วนลูปโดยการเลื่อนตัวชี้ str ไปข้างหน้า
//     while (*str != '\0') // ตรวจสอบอักขระที่ str ชี้อยู่
//     {
//         if (*str >= 'a' && *str <= 'z') // เข้าถึงอักขระด้วย *str
//         {
//             *str = *str - 32; // แก้ไขอักขระด้วย *str
//         }
//         str++; // เลื่อนตัวชี้ str ไปยังอักขระตัวถัดไป
//     }
//     return (orig); // คืนค่าจุดเริ่มต้นเดิม
// }