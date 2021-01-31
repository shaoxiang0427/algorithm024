class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) {
			return 0;
		}
		int i = 0;

		for (int j = 1; j < n; j++) {
			if (nums[j] != nums[i]) {
				i++;
				nums[i] = nums[j];
			}

		}
		return (i + 1);
	}
};
//时间复杂度:O(n)
//空间复杂度：O(1)