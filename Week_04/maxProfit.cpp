class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //dp[i][j]:i表示第几天，j表示持有现金0或者股票1；dp[i][j]表示到第i天时最大的利润（持有股票或者现金
        vector<vector<int>> dp(n,vector<int>(2));
        //确定初始条件
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        //状态转移方程
        for (int i = 1;i<n;i++) {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i]);
        }

        return dp[n-1][0];
    }
};