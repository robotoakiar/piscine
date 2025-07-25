#include <stdio.h>

void check_size(int *arr)
{
    printf("sizeof(arr) = %lu bytes\n", sizeof(arr));
    printf("sizeof(arr[0]) = %lu bytes\n", sizeof(arr[0]));
}

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5};
    printf("sizeof(nums) = %lu bytes\n", sizeof(nums));
    printf("sizeof(nums[0]) = %lu bytes\n", sizeof(nums[0]));
    printf("array size = %lu elements\n", sizeof(nums) / sizeof(nums[0]));

    check_size(nums); // ส่งไปฟังก์ชัน จะเห็นว่า sizeof(arr) ไม่เท่ากับ sizeof(nums)

    return 0;
}
