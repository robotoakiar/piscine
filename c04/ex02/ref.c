#include <unistd.h> // Required for write()
#include <limits.h> // Required for INT_MIN

void ft_putnbr(int nb)
{
    if (nb == INT_MIN) // Special case for the smallest negative integer
    {
        // INT_MIN is -2147483648. Its positive counterpart 2147483648 cannot be stored in an int.
        // We can handle this by printing "-2" and then the rest of the digits of 147483648.
        write(1, "-", 1);
        write(1, "2", 1);
        nb = 147483648; // Now handle the rest as positive
    }
    else if (nb < 0)
    {
        write(1, "-", 1);
        nb = -nb; // Make the number positive
    }

    if (nb >= 10)
    {
        ft_putnbr(nb / 10); 
    }
    char digit = (nb % 10) + '0'; 
    write(1, &digit, 1); 
}

int main()
{
    ft_putnbr(42);
    write(1, "\n", 1); 
    ft_putnbr(-123);
    write(1, "\n", 1);
    ft_putnbr(0);
    write(1, "\n", 1);
    ft_putnbr(2147483647); 
    write(1, "\n", 1);
    ft_putnbr(-2147483648); 
    write(1, "\n", 1);
    return 0;
}