#include <unistd.h>

void ft_rev_int_tab(int *tab, int size)
{
    int start;
    int end;
    int temp;

    start = 0;
    end = size - 1;
    while (start < end)
    {
        temp = tab[start];
        tab[start] = tab[end];
        tab[end] = temp;

        start++;
        end--;
    }   
}

#include <stdio.h>

int main(void)
{
    int arr_num[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr_num) / sizeof(arr_num[0]);

    ft_rev_int_tab(arr_num, size);
    
    for (int i = 0; i < size; i++)
    printf("%d ", arr_num[i]);

    return 0;

}