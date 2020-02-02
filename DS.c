#include "Include/Stack.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
#include <math.h>

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int idx;
    int cnt = 0;
    int max = 0;
    for (idx = 0; idx < numsSize; idx++) {
        if (nums[idx]) {
            cnt++;
        } else {
            max = cnt > max ? cnt : max;
            cnt = 0;
        }
    }
    
    return max > cnt ? max : cnt;
}

int* sortedSquares(int* A, int ASize, int* returnSize) {
    int idx;
    int idx2;
    int temp;

    for (idx = 0; idx < ASize; idx++) {
        A[idx] = (int)pow(A[idx], 2);
    }

    for (idx = 0; idx < ASize - 1; idx++) {
        for (idx2 = 0; idx2 < ASize - idx - 1; idx2++) {
            if (A[idx2] > A[idx2 + 1]) {
                temp = A[idx2];
                A[idx2] = A[idx2 + 1];
                A[idx2 + 1] = temp;
            }
        }
    }

    *returnSize = ASize;
    return A;
}

int main()
{
    int nums[] = {-4, -1, 0, 3, 10};
    int *result;
    int resultSize = 0;
    int size = sizeof(nums) / sizeof(nums[0]);
    result = sortedSquares(nums, size, &resultSize);

    for (int idx = 0; idx < resultSize; idx++) {
        printf ("%d ", result[idx]);
    }
    
    return 0;
}