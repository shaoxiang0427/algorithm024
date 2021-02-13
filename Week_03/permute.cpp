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
            if (used[i] == 1) {
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
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return res;
        }

        vector<int> used(n,0);
        dfs(nums,n,0,used);

        return res;
    }
};