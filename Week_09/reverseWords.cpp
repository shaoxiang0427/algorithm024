class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        if (n == 0) {
            return "";
        }

        vector<string> result;
        string tmp = "";

        for(int i = 0;i<n;i++) {
            if (s[i] == ' ') {
                if(tmp!="") {
                    result.push_back(tmp);
                }
                tmp = "";
            } else {
                tmp += s[i];
            } 

            if(i == n-1) {
                if (tmp!="") {
                    result.push_back(tmp);
                }
            }
        }

        string t = "";

        for(int i = result.size()-1;i>=0;i--) {
            if (i == 0) {
                t += result[i];
            } else {
                t += result[i];
                t += " ";
            }
        }

        return t;

    }
};