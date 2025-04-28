// this program is to test phase_4

#include <stdio.h>

int binary_search(int low, int high, int target)
{
    int mid = (low + high) / 2;
    if (mid == target)
        return mid;
    else if (mid > target)
        return binary_search(low, mid - 1, target) + mid;
    else
        return binary_search(mid + 1, high, target) + mid;
}

int main()
{
    int low = 0, high = 14, target = 6;
    int result = binary_search(low, high, target);
    printf("The result is: %d\n", result);
    return 0;
}