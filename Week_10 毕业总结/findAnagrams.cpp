class Solution {
public:
/*
    bool yiwen(string s1,string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if (n1!=n2) {
            return false;
        }

        unordered_map<char,int> hash;

        for(int i = 0;i<n1;i++) {
            hash[s1[i]]++;
            hash[s2[i]]--;
        }

        for(auto e : hash) {
            if (e.second != 0) {
                return false;
            }
        }
        return true;
    }
    */
    bool arrisequal(vector<int> &arr1,vector<int> &arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();

        if (n1!=n2) {
            return false;
        }

        for (int i = 0;i<n1;i++) {
            if (arr1[i]!=arr2[i]) {
                return false;
            }
        }

        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int np = p.size();
        int ns = s.size();
        vector<int> result;

        if (ns<np) {
            return {};
        }

        vector<int> nums(26,0);
        vector<int> nump(26,0);

        for(int i = 0;i<np;i++) {
            nump[p[i]-'a']++;
            nums[s[i]-'a']++;
        }

        if (arrisequal(nums,nump)) {
            result.push_back(0);
        }

        for(int i = np;i<ns;i++) {
            nums[s[i-np]-'a']--;
            nums[s[i]-'a']++;
            if (arrisequal(nums,nump)) {
                result.push_back(i-np+1);
            }
        }

        return result;
        /*
        for (int i = 0;i<ns-np+1;i++) {
            if (yiwen(s.substr(i,np),p)) {
                result.push_back(i);
            }
        }

        return result;
        */
    }
};