/*
Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.
*/

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void perm(int* nums, int k, int N, int* ans) {
	if (k == N) {
		*ans = *ans + 1;
		return;
	}
	for (int i = k; i < N; i++) {
		swap(&nums[i], &nums[k]);
		if (nums[k] % (k + 1) == 0 || (k + 1) % nums[k] == 0)
			perm(nums, k + 1, N, ans);
		swap(&nums[i], &nums[k]);
	}
}

int countArrangement(int N) {
	int ans = 0;
	int nums[15];
	for (int i = 0; i < N; i++)
		nums[i] = i + 1;
	perm(nums, 0, N, &ans);
	return ans;
}