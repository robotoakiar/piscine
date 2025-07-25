int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int i;
    
    i = 0;
    // ถ้า n เท่ากับ 0 ให้คืนค่า 0
    if (n == 0)
        return (0);
    
    // เปรียบเทียบทีละตัวอักษรจนกว่าจะถึง n ตัวอักษร
    while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    
    // ถ้าเปรียบเทียบครบ n ตัวอักษรแล้วและทุกตัวเหมือนกัน
    if (i == n)
        return (0);
    
    // คืนค่าผลต่างของตัวอักษรที่ต่างกัน
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}