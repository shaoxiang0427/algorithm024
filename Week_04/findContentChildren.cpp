class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ng = g.size();
        int ns = s.size();
        if(ns == 0) {
            return 0;
        }
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int index_g = 0;
        int index_s = 0;
        int sum = 0;

        while(index_g<ng&&index_s<ns) {
            if (s[index_s]>=g[index_g]) {
                sum++;
                index_s++;
                index_g++;
            } else 
            {
                index_s++;
            }
        }
        return sum;

    }
};