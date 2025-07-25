int ft_atoi(char *str)
{
    int i;
    int s;
    int r;

    i = 0;
    s = 1;
    r = 0;

    while (str[i] == ' ' || str[i] == 'f' || str[i] == 'n' || str[i] == 'r' || str[i] == 't' || str[i] == 'v')
    {
        i++;
    }
    
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
        {
            s = s * - 1;
        }

        i++;
    }

    while (str[i] >= '0' && str[i] <= '9')
    {
        r = r * 10 + (str[i] - '0');
        i++;
    }

    return (r + s);
    
    
}


// ตัวอย่างการใช้งานและทดสอบ
#include <stdio.h>

int main(void)
{
    char *test_strings[] = {
        "42",
        "-42",
        "   42",
        "   -42",
        "++42",
        "--42",
        "---42",
        "+--+42",
        "   ----+-1234ab567",
        "0",
        "   +0",
        "   -0",
        "123abc456",
        "   +123   456",
        "",
        "abc123"
    };
    
    int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);
    
    printf("การทดสอบฟังก์ชัน ft_atoi:\n");
    printf("========================\n");
    
    for (int i = 0; i < num_tests; i++)
    {
        int result = ft_atoi(test_strings[i]);
        printf("Input: \"%s\" -> Output: %d\n", test_strings[i], result);
    }
    
    return 0;
}