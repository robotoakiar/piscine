void   ft_sort_int_tab(int *tab, int size)
{
    int i;
    int j;
    int swap;
    int temp;

    swap = 1;
    i = 0;
    while (swap == 1 && i < size - 1)
    {
        swap = 0;
        j = 0;
        while (j < size - 1 - i)
        {
            if (tab[j] > tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;

                swap = 1;
            }
            j++;
            
        }
        i++;
        
    }
    
}

#include <stdio.h>

int main(void)
{
    int arr0[] = {10, 9, 8, 7, 6, 5, 4};
    int arr1[] = {123, 742, 852, 45, 857, 7895, 859, 45, 8585};
    int size0 = sizeof(arr0) / sizeof(arr0[0]);
    int size1 = sizeof(arr1) / sizeof(arr1[5]);


    ft_sort_int_tab(arr0, size0);
    for (int i = 0; i < size0; i++)
    {
        printf("%d, ", arr0[i]);
    }
    printf("\n");

    ft_sort_int_tab(arr1, size1);
    for (int i = 0; i < size1; i++)
    {
        printf("%d, ", arr1[i]);
    }
    
    printf("\n");

    return (0);
}
