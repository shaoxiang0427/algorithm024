class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int> &nums, int n,int depth,vector<int> &used) {
        if (depth == n) {
            res.push_back(path);
            return ;
        }

        for (int i = 0;i<n;i++) {
            if (used[i] == 1 || (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0)) {
                continue;
            } else {
                path.push_back(nums[i]);
                used[i] = 1;
                dfs(nums,n,depth + 1,used);

                //回溯到上一层状态
                path.pop_back();
                used[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return res;
        }

        sort(nums.begin(),nums.end());
        vector<int> used(n,0);
        dfs(nums,n,0,used);

        return res;
    }
};