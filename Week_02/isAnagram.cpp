class Solution {
public:
    bool isAnagram(string s, string t) {
        //方法一：哈希表，时间复杂度O(N)，空间复杂度O(N)
        int ns = s.size();
        int nt = t.size();

        if(ns != nt) {
            return false;
        } else if (ns == nt &&ns == 0) {
            return true;
        } else {
            ;
        }

        unordered_map<int,int> hash;

        for (int i = 0;i<ns;i++) {
            hash[s[i] - 'a']++;
            hash[t[i] - 'a']--;
        }

        for (auto e : hash) {
            if (e.second!=0) {
                return false;
            }
        }

        return true;

        //方法二：排序，时间复杂度O(Nlog(N))，空间复杂度O(1)
        // int ns = s.size();
        // int nt = t.size();

        // if(ns == nt &&ns == 0)
        // {
        //     return true;
        // }

        // if(ns!= nt)
        // {
        //     return false;
        // }

        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());

        // return s == t;
    }
};