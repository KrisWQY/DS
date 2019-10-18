#include "Include/DS.h"

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int thirdMax(int* nums, int numsSize){
    int result[3] = {0};
    int idx;
    int Flag = 0;
    
    switch (numsSize) {
        case 1: return nums[0];
            break;
        case 2: return MAX(nums[0], nums[1]);
            break;
    }
    
    if (nums[0] > nums[1]) {
        result[0] = nums[0];
        result[1] = nums[1];
    } else if (nums[0] < nums[1]) {
        result[0] = nums[1];
        result[1] = nums[0];
    } else {
        result[0] = nums[0];
    }
    
    for (idx = 2; idx < numsSize; idx++) {
        if (nums[idx] > result[0]) {
            result[2] = result[1];
            result[1] = result[0];
            result[0] = nums[idx]; 
        } else if (nums[idx] > result[1] && nums[idx] != result[0]) {
            result[2] = result[1];
            result[1] = nums[idx];
            Flag = 1;
        } else if (nums[idx] > result[2] && nums[idx] != result[1] && nums[idx] != result[0]) {
            result[2] = nums[idx];
            Flag = 1;
        }
    }
    
    if (result[0] != result[1] && result[1] != result[2] && Flag != 0) {
        return result[2];
    } else {
        return result[0];
    }
}

int main()
{
    int nums[] = {2, 2, 2, 1};
    int result;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    result = thirdMax(nums, numsSize);
    printf("result:%d\n", result);
    return 0;
}