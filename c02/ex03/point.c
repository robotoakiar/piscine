// #include <stdio.h>

// int main(void) {
//     char *str = "ABC";

//     while (*str != '\0') {
//         printf("Pointer: %p | Current char: %c\n", str, *str);
//         str++;
//     }

//     return 0;
// }


#include <stdio.h>

int main(void) {
    char *str = "ABC";
    int i = 0;

    while (*str != '\0') {
        printf("Step %d | str addr: %p | *str: %c\n", i, (void *)str, *str);
        str++;
        i++;
    }

    return 0;
}
