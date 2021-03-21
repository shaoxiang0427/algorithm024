class Solution {
public:
    vector<string> res;
    void dfs(int left,int right,int n,string s) {
        if (left == n && right == n) {
            res.push_back(s);
            return ;
        }

        if (left < n) {
            dfs(left + 1,right,n,s + '(');
        }
        if (right < left) {
            dfs(left,right + 1,n,s + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(0,0,n,"");
        return res;
    }
};