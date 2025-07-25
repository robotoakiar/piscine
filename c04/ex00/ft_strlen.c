int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return (len);   
}

#include <stdio.h>

int main()
{
    char *x = "asdf"; // Corrected string declaration (pointer to string literal)
    // Or: char x[] = "asdf"; // If you need a mutable string

    int length = ft_strlen(x); // Store the returned length
    printf("The length of \"%s\" is: %d\n", x, length); // Print the length
    printf("%d \n", ft_strlen("12345"));
    return 0;
}