#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_hex(unsigned char byte)
{
    char hex[] = "0123456789abcdef";
    ft_putchar(hex[byte / 16]);
    ft_putchar(hex[byte % 16]);
}

void ft_print_address(void *addr)
{
    unsigned long address = (unsigned long)addr;
    char hex[] = "0123456789abcdef";
    int i = 15;
    
    while (i >= 0)
    {
        ft_putchar(hex[(address >> (i * 4)) & 0xF]);
        i--;
    }
    write(1, ": ", 2);
}

void ft_print_line(void *addr, unsigned int size)
{
    unsigned char *ptr = (unsigned char *)addr;
    unsigned int i = 0;
    
    // พิมพ์ hex content
    while (i < 16)
    {
        if (i < size)
            ft_print_hex(ptr[i]);
        else
            write(1, "  ", 2);
        if (i % 2 == 1)
            ft_putchar(' ');
        i++;
    }
    ft_putchar(' ');
    
    // พิมพ์ char content
    i = 0;
    while (i < 16 && i < size)
    {
        if (ptr[i] >= 32 && ptr[i] <= 126)
            ft_putchar(ptr[i]);
        else
            ft_putchar('.');
        i++;
    }
    ft_putchar('\n');
}

void *ft_print_memory(void *addr, unsigned int size)
{
    unsigned char *ptr = (unsigned char *)addr;
    unsigned int i = 0;
    unsigned int line_size;
    
    if (size == 0)
        return (addr);
    
    while (i < size)
    {
        if (size - i >= 16)
            line_size = 16;
        else
            line_size = size - i;
        ft_print_address(ptr + i);
        ft_print_line(ptr + i, line_size);
        i += 16;
    }
    return (addr);
}

// ฟังก์ชันทดสอบ
int main(void)
{
    char str[] = "Bonjour les*amis\t\t\n\tLorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    ft_print_memory(str, sizeof(str) - 1);
    return (0);
}