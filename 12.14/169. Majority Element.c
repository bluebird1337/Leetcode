/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/


int majorityElement(int* nums, int numsSize) {
    int major = nums[0];
    int count = 1;
    int i;
    for (i = 1; i < numsSize; i++) {
        if (count == 0) {
            major = nums[i];
            count = 1;
            continue;
        }
        if (major == nums[i])
            count++;
        else
            count--;
    }

    return major;
}