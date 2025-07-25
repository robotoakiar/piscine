#include <stdio.h> // สำหรับ printf
#include <string.h> // สำหรับ strstr (เพื่อเปรียบเทียบกับฟังก์ชันมาตรฐาน)

// จำลองการประกาศฟังก์ชัน ft_strstr ของคุณ
// ในโปรเจกต์จริง คุณจะ #include "ft_strstr.h" หรือคอมไพล์ ft_strstr.c พร้อมกับ main.c
char *ft_strstr(char *str, char *to_find);

int main()
{
    char str1[] = "Hello World";
    char to_find1[] = "World";
    char to_find2[] = "hello"; // ตัวพิมพ์เล็ก/ใหญ่ต่างกัน
    char to_find3[] = "o W";
    char to_find4[] = "xyz";
    char to_find5[] = ""; // สตริงว่าง
    char str2[] = "aaaaa";
    char to_find6[] = "aa";
    char str3[] = "";
    char to_find7[] = "abc";

    char *result_ft;
    char *result_std;

    printf("--- Test Case 1: Found substring ---\n");
    result_ft = ft_strstr(str1, to_find1);
    result_std = strstr(str1, to_find1);
    printf("ft_strstr(\"%s\", \"%s\"): %s (Expected: %s)\n", str1, to_find1, result_ft ? result_ft : "NULL", result_std ? result_std : "NULL");

    printf("\n--- Test Case 2: Not found (case sensitive) ---\n");
    result_ft = ft_strstr(str1, to_find2);
    result_std = strstr(str1, to_find2);
    printf("ft_strstr(\"%s\", \"%s\"): %s (Expected: %s)\n", str1, to_find2, result_ft ? result_ft : "NULL", result_std ? result_std : "NULL");

    printf("\n--- Test Case 3: Substring in middle ---\n");
    result_ft = ft_strstr(str1, to_find3);
    result_std = strstr(str1, to_find3);
    printf("ft_strstr(\"%s\", \"%s\"): %s (Expected: %s)\n", str1, to_find3, result_ft ? result_ft : "NULL", result_std ? result_std : "NULL");

    printf("\n--- Test Case 4: Not found ---\n");
    result_ft = ft_strstr(str1, to_find4);
    result_std = strstr(str1, to_find4);
    printf("ft_strstr(\"%s\", \"%s\"): %s (Expected: %s)\n", str1, to_find4, result_ft ? result_ft : "NULL", result_std ? result_std : "NULL");

    printf("\n--- Test Case 5: Empty search string ---\n");
    result_ft = ft_strstr(str1, to_find5);
    result_std = strstr(str1, to_find5);
    printf("ft_strstr(\"%s\", \"%s\"): %s (Expected: %s)\n", str1, to_find5, result_ft ? result_ft : "NULL", result_std ? result_std : "NULL");

    printf("\n--- Test Case 6: Overlapping substrings ---\n");
    result_ft = ft_strstr(str2, to_find6);
    result_std = strstr(str2, to_find6);
    printf("ft_strstr(\"%s\", \"%s\"): %s (Expected: %s)\n", str2, to_find6, result_ft ? result_ft : "NULL", result_std ? result_std : "NULL");

    printf("\n--- Test Case 7: Empty main string ---\n");
    result_ft = ft_strstr(str3, to_find7);
    result_std = strstr(str3, to_find7);
    printf("ft_strstr(\"%s\", \"%s\"): %s (Expected: %s)\n", str3, to_find7, result_ft ? result_ft : "NULL", result_std ? result_std : "NULL");

    printf("\n--- Test Case 8: Both empty strings ---\n");
    result_ft = ft_strstr(str3, to_find5); // str3 is empty, to_find5 is empty
    result_std = strstr(str3, to_find5);
    printf("ft_strstr(\"%s\", \"%s\"): %s (Expected: %s)\n", str3, to_find5, result_ft ? result_ft : "NULL", result_std ? result_std : "NULL");


    return (0);
}

// โค้ด ft_strstr ของคุณจะอยู่ในไฟล์ ft_strstr.c
// หรือคุณสามารถวางไว้ที่นี่เพื่อทดสอบแบบรวดเร็วได้
/*
char *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;

    if (to_find[0] == '\0')
        return (str);

    i = 0;
    while (str[i] != '\0')
    {
        j = 0;
        while (str[i + j] == to_find[j] && to_find[j] != '\0')
            j++;
        
        if (to_find[j] == '\0')
            return (&str[i]);
        
        i++;
    }
    
    return (0);
}
*/