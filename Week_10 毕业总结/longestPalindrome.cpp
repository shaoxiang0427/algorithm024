class Solution {
public:
    /*
    bool isPalindromic(string s) {
        int n = s.size();
        if (n<=1) {
            return true;
        }

        for(int i = 0;i<n/2;i++) {
            if (s[i]!=s[n-1-i]) {
                return false;
            }
        }
        return true;
    }
    */
    string longestPalindrome(string s) {
        //方法二：动态规划
        int n = s.size();

        vector<vector<int>> dp(n,vector<int>(n));
        //dp[i][j]表示从起始坐标i到终点坐标j是否是回文字符串，如果是dp[i][j] = 1，否则dp[i][j]=0;

        string result = s.substr(0,1);//默认情况下

        //length表示回文字符串的长度-1；
        //left表示回文字符串起始坐标
        //right表示回文字符串终点坐标
        for (int length = 0;length < n;length++) {
            for (int left = 0;left + length<n;left++) {
                int right = left + length;

                if (length == 0) {
                    dp[left][right] = 1;//字符串中单个字符都是回文字符串；
                } else if (length == 1) {
                    //当字符串的长度为2时，只有两个字母相等时才是回文字符串
                    dp[left][right] = (s[left] == s[right]);
                } else {
                    //当字符串长度大于2，仅当s[left] == s[right]且dp[left+1][right-1]为1时是回文字符串
                    dp[left][right] = (dp[left + 1][right-1]&&(s[left] == s[right]));
                }

                if (dp[left][right]&&(length+1>result.size())) {
                    result = s.substr(left,length+1);
                }
            }
        }
        return result; 

        //方法一：暴力法
        /*
        int n = s.size();
        if (n<=1) {
            return s;
        }

        string str = s.substr(0,1);
        int minlen = 1;

        for (int i = 0;i<n;i++) {
            for(int j = i+1;j<n;j++) {
                if (isPalindromic(s.substr(i,j-i+1))) {
                    if (j-i+1>minlen) {
                        minlen = j-i+1;
                        str = s.substr(i,j-i+1);
                    }
                }
            }
        }

        return str;
        */
    }
};