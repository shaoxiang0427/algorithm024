class Solution {
public:
    string reverseWords(string s) {
        if (s.size()==0) {
            return "";
        }

        vector<string> str;

        string tmp = "";
        
        for(int i = 0;i<s.size();i++) {
            if (s[i] == ' ') {
                str.push_back(tmp);
                tmp = "";
            } else {
                tmp += s[i];
            }

            if (i == s.size()-1) {
                if (tmp!="") {
                    str.push_back(tmp);
                }
            }
        }

        string result = "";

        for (int i = 0;i<str.size();i++) {
            reverse(str[i].begin(),str[i].end());

            result += str[i];
            if (i!=str.size()-1) {
                result += ' ';
            }
        }

        return result;

    }
};