class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return true;
        }
        int maxlen = 0;
        for (int i = 0;i<n-1;i++) {
            if (i<=maxlen) {
                maxlen = max(maxlen,i+nums[i]) ;
                if (maxlen >=n-1) {
                    return true;
                }
            }
        }
        return false;
    }
};