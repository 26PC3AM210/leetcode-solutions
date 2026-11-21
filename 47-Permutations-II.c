#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, int* used, int* curr, int currSize, int*** res, int* resSize, int** colSizes) {
    if (currSize == numsSize) {
        (*res)[*resSize] = (int*)malloc(sizeof(int) * numsSize);
        memcpy((*res)[*resSize], curr, sizeof(int) * numsSize);
        (*colSizes)[*resSize] = numsSize;
        (*resSize)++;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
        used[i] = 1;
        curr[currSize] = nums[i];
        backtrack(nums, numsSize, used, curr, currSize + 1, res, resSize, colSizes);
        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int maxSize = 10000;
    int** res = (int**)malloc(sizeof(int*) * maxSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxSize);
    int* used = (int*)calloc(numsSize, sizeof(int));
    int* curr = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    backtrack(nums, numsSize, used, curr, 0, &res, returnSize, returnColumnSizes);
    free(used);
    free(curr);
    return res;
}