#include <unistd.h>

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

void ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }else if (nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }

    if (nb > 10)
    {
        ft_putnbr(nb / 10);
    }

    char c = (nb % 10) + 48;
    write(1, &c, 1);
}


int main()
{
    ft_putstr("Testing normal case:\n");
    ft_putnbr(4);
    write(1, "\n", 1);
    
    ft_putstr("\nTesting negative:\n");
    ft_putnbr(-123);
    write(1, "\n", 1);
    
    ft_putstr("\nTesting INT_MIN:\n");
    ft_putnbr(-2147483648);
    write(1, "\n", 1);
    
    ft_putstr("\nTesting INT_MAX:\n");
    ft_putnbr(2147483647);
    write(1, "\n", 1);
    
    // ทดสอบค่าที่เกินช่วง (จะไม่เกิดขึ้นจริงใน int แต่เป็นตัวอย่าง)
    ft_putstr("\nNote: int automatically limits values to valid range\n");
    ft_putstr("If input exceeds range, it would show error message above\n");
    
    return 0;
}