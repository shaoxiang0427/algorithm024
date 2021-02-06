class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //方法二：哈希表，时间复杂度O(N)，空间复杂度O(N)
        unordered_map<int,int> hash;
        for (int i = 0;i<nums.size();i++) {
            //unordered_map<int,int>::iterator it = hash.find(target - nums[i]);
            auto it = hash.find(target - nums[i]);
            if (it != hash.end()) {
                return {i,hash[target-nums[i]]};
            }

            hash[nums[i]] = i;
        }

        return {};
        //方法一：暴力，时间复杂度：O(N^2)，空间复杂度O(1)
        // for (int i = 0;i<nums.size()-1;i++) {
        //     for (int j = i + 1;j<nums.size();j++) {
        //         if (nums[i] + nums[j] == target) {
        //             return {i,j};
        //         }
        //     }
        // }

        // return {};

    }
};