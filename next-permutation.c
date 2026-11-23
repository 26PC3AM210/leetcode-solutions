// LeetCode 31. Next Permutation
// https://leetcode.com/problems/next-permutation/

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;

    // Step 1: Pivot vetuku -> nums[i] < nums[i+1]
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Step 2: Pivot kanna pedda number tho swap
        int j = numsSize - 1;
        while (j >= 0 && nums[j] <= nums[i]) {
            j--;
        }
        swap(&nums[i], &nums[j]);
    }

    // Step 3: Migilina part reverse
    reverse(nums, i + 1, numsSize - 1);
}