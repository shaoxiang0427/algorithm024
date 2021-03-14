class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1));

        //初始化边界值
        dp[0][0] = 0;
        //dp[0][1] = 1;
        //dp[1][0] = 1;

        for(int i = 1;i<=m;i++)
        {
            dp[i][0] = dp[i-1] [0]+ 1;
        }
        for(int j = 1; j<=n;j++)
        {
            dp[0][j] = dp[0][j-1] + 1;
        }
        

        for(int i = 1;i<=m;i++)
            for(int j = 1;j<=n;j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(min(dp[i-1][j] + 1,dp[i-1][j-1] + 1),dp[i][j-1] + 1);
                }
            }

        return dp[m][n];
    // int n1 = word1.length();
    // int n2 = word2.length();
    // //int[][] dp = new int[n1 + 1][n2 + 1];
    // vector<vector<int>> dp(n1+1,vector<int>(n2+1));
    // // dp[0][0...n2]的初始值
    // for (int j = 1; j <= n2; j++) 
    //     dp[0][j] = dp[0][j - 1] + 1;
    // // dp[0...n1][0] 的初始值
    // for (int i = 1; i <= n1; i++) dp[i][0] = dp[i - 1][0] + 1;
    //     // 通过公式推出 dp[n1][n2]
    // for (int i = 1; i <= n1; i++) {
    //     for (int j = 1; j <= n2; j++) {
    //           // 如果 word1[i] 与 word2[j] 相等。第 i 个字符对应下标是 i-1
    //         if (word1[i-1] == word2[j-1]){
    //             dp[i][j] = dp[i - 1][j - 1];
    //         }else {
    //            dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
    //         }         
    //     }
    // }
    // return dp[n1][n2];  
    }
};