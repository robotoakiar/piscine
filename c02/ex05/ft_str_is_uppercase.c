int ft_str_is_uppercase(char *str)
{
    if (*str == '\0')
    {
        return 1;
    }

    while (*str != '\0')
    {
        if (!(*str >= 'A' && *str <= 'Z'))
        {
            return 0;
        }
        str++;  
    }
    
    return 1;
}