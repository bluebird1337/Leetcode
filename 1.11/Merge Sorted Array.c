/*

https://leetcode.com/problems/merge-sorted-array/

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
Constraints:

0 <= n, m <= 200
1 <= n + m <= 200
nums1.length == m + n
nums2.length == n
-109 <= nums1[i], nums2[i] <= 109
*/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	while (m > 0 && n > 0) {
		if (nums1[m-1] > nums2[n-1]) {
			nums1[nums1Size - 1] = nums1[m - 1];
			nums1Size--;
			m--;
		}
		else {
			nums1[nums1Size - 1] = nums2[n - 1];
			nums1Size--;
			n--;
		}
	}
	while (n > 0) { // m == 0 need to add nums2 to nums1, but if n == 0, nothing to add
		nums1[nums1Size - 1] = nums2[n - 1];
		nums1Size--;
		n--;
	}
}