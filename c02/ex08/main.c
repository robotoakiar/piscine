#include <stdio.h> // Required for printf

// Function prototype for ft_strlowcase
// You will implement this function in ft_strlowcase.c
char *ft_strlowcase(char *str);

int main() {
    char str1[] = "HELLO WORLD";
    char str2[] = "gOOd MoRniNg";
    char str3[] = "123 ABC def";
    char str4[] = ""; // Empty string
    char str5[] = "aBcDeFg";

    printf("Original string 1: \"%s\"\n", str1);
    printf("Lowercase string 1: \"%s\"\n\n", ft_strlowcase(str1));

    printf("Original string 2: \"%s\"\n", str2);
    printf("Lowercase string 2: \"%s\"\n\n", ft_strlowcase(str2));

    printf("Original string 3: \"%s\"\n", str3);
    printf("Lowercase string 3: \"%s\"\n\n", ft_strlowcase(str3));

    printf("Original string 4: \"%s\"\n", str4);
    printf("Lowercase string 4: \"%s\"\n\n", ft_strlowcase(str4));

    printf("Original string 5: \"%s\"\n", str5);
    printf("Lowercase string 5: \"%s\"\n\n", ft_strlowcase(str5));

    return 0;
}