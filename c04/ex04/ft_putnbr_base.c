#include <unistd.h>

// Helper function to get string length
int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return (len);
}

// Function to validate base string
int is_valid_base(char *base)
{
    int i = 0;
    int j;
    
    // Check if base has at least 2 characters
    while (base[i])
        i++;
    if (i < 2)
        return (0);
    
    i = 0;
    while (base[i])
    {
        // Check for forbidden characters '+' and '-'
        if (base[i] == '+' || base[i] == '-')
            return (0);
            
        // Check for duplicate characters
        j = i + 1;
        while (base[j])
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

// Main function to print number in given base
void ft_putnbr_base(int nbr, char *base)
{
    int base_len;
    long long n;
    
    // Validate base first
    if (!is_valid_base(base))
        return;
    
    base_len = ft_strlen(base);
    n = nbr;
    
    // Handle negative numbers
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;  // Convert to positive
    }
    
    // Recursive conversion
    if (n >= base_len)
        ft_putnbr_base(n / base_len, base);
    
    // Write the current digit
    write(1, &base[n % base_len], 1);
}

// Test function (for demonstration - not part of submission)
#ifdef TEST_MODE
#include <stdio.h>

int main()
{
    printf("=== ft_putnbr_base Test Cases ===\n\n");
    
    printf("Test 1 - Binary (42): ");
    ft_putnbr_base(42, "01");
    printf(" (Expected: 101010)\n");
    
    printf("Test 2 - Binary (-42): ");
    ft_putnbr_base(-42, "01");
    printf(" (Expected: -101010)\n");
    
    printf("Test 3 - Hexadecimal (255): ");
    ft_putnbr_base(255, "0123456789ABCDEF");
    printf(" (Expected: FF)\n");
    
    printf("Test 4 - Decimal (42): ");
    ft_putnbr_base(42, "0123456789");
    printf(" (Expected: 42)\n");
    
    printf("Test 5 - Octal (64): ");
    ft_putnbr_base(64, "01234567");
    printf(" (Expected: 100)\n");
    
    printf("Test 6 - Custom base (42): ");
    ft_putnbr_base(42, "ponveyvif");
    printf(" (Expected: 57)\n");
    
    printf("Test 7 - Zero: ");
    ft_putnbr_base(0, "0123456789");
    printf(" (Expected: 0)\n");
    
    printf("Test 8 - Invalid base (empty): ");
    ft_putnbr_base(42, "");
    printf(" (Expected: nothing)\n");
    
    printf("Test 9 - Invalid base (single char): ");
    ft_putnbr_base(42, "a");
    printf(" (Expected: nothing)\n");
    
    printf("Test 10 - Invalid base (duplicate): ");
    ft_putnbr_base(42, "0123456789AA");
    printf(" (Expected: nothing)\n");
    
    printf("Test 11 - Invalid base (+ char): ");
    ft_putnbr_base(42, "0123456789+");
    printf(" (Expected: nothing)\n");
    
    printf("Test 12 - Invalid base (- char): ");
    ft_putnbr_base(42, "0123456789-");
    printf(" (Expected: nothing)\n");
    
    return (0);
}
#endif