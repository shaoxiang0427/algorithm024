class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxlen = 0;

        if ( matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row,vector<int>(col));

        //确定边界条件
        for(int i = 0;i<row;i++) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                maxlen = 1;
            }
            else {
                dp[i][0] = 0;
            }
        }

            for(int i = 0;i<col;i++) {
            if (matrix[0][i] == '1') {
                dp[0][i] = 1;
                maxlen = 1;
            }
            else {
                dp[0][i] = 0;
            }
        }

        for ( int i = 1;i<row;i++) {
            for(int j = 1;j<col;j++) {
                if (matrix[i][j] == '1') {
                    //状态转移方程
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                    maxlen = max(maxlen,dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }

        return maxlen*maxlen;

    }
};