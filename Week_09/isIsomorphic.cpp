class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() == 0) {
            return true;
        }
        unordered_map<char,char> s2t;
        unordered_map<char,char> t2s;

        for(int i = 0;i<s.size();i++) {
            //表示s2t哈希表中存在s[i]，且映射关系s2t[s[i]]!=t[i]（当前值）；           
            if ((s2t.count(s[i])&&s2t[s[i]]!=t[i])||(t2s.count(t[i])&&t2s[t[i]]!=s[i])) {
                return false;
            }
            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        }

        return true;

    }
};