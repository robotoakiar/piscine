#include <unistd.h>

void ft_putstr(char *str)
{
    
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    
    
}

#include <stdio.h>

int main()
{
    char c[] = "asdfgh\n";

    ft_putstr(c);
    ft_putstr("hi boii2.\n");


    return 0;
}