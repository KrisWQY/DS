#include <stdio.h>

int maxSubArray(int *nums, int numsSize)
{
    int CurSum = 0;
    int MaxSum = nums[0];
    int i;
    for (i = 0; i < numsSize; i++)
    {
        CurSum += nums[i];
        if (CurSum > MaxSum)
        {
            MaxSum = CurSum;
        }
        else if (CurSum < 0)
        {
            CurSum = 0;
        }
    }

    return MaxSum;
}

int main()
{
    int nums[] = {-3, -2, 0, -1};
    int result;

    result = maxSubArray(nums, 4);
    printf("result:%d\n", result);
    return 0;
}