char *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;

    // ถ้า to_find เป็นสตริงว่าง ให้คืนค่า str
    if (to_find[0] == '\0')
        return (str);

    i = 0;
    while (str[i] != '\0')
    {
        j = 0;
        // ตรวจสอบว่าตัวอักษรตรงกันหรือไม่
        while (str[i + j] == to_find[j] && to_find[j] != '\0')
            j++;
        
        // ถ้าเจอสตริงที่ต้องการแล้ว
        if (to_find[j] == '\0')
            return (&str[i]);
        
        i++;
    }
    
    // ไม่เจอสตริงที่ต้องการ
    return (0);
}