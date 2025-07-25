int ft_str_is_numeric(char *str)
{
    if (*str == '\0')
    {
        return 1;
    }
    
    while (*str != '\0')
    {
        if (!(*str >= '0' && *str <= '9'))
        {
            return 0;
        }
        str++;
    }
    return 1;
}


// Feature	str	                           *str
// ความหมาย	ที่อยู่หน่วยความจำ (memory address)	ค่าที่เก็บอยู่ที่ที่อยู่นั้น (value at address)