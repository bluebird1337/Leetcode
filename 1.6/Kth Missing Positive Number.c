/*
* https://leetcode.com/problems/kth-missing-positive-number/
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Find the kth positive integer that is missing from this array.

Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
arr[i] < arr[j] for 1 <= i < j <= arr.length
*/

int findKthPositive(int* arr, int arrSize, int k) {
	int count = 1, Idx = 0, i = 0;

	while (Idx < k) {
		if (i == arrSize) {
			Idx++;
			count++;
		}
		else {
			if (count == arr[i]) {
				count++;
				i++;
			}
			else {
				count++;
				Idx++;
			}
		}
	}
	return count - 1;
}