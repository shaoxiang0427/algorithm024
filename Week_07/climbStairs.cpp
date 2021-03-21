class Solution {
public:
    int climbStairs(int n) {

        if(n<=2)
        {
            return n;
        }
        int a = 1,b = 2,c;

        for(int i = 3;i<=n;i++)
        {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
        /*
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
        */
    }
};