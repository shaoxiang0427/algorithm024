class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;
        unordered_map<string,vector<string>> hash;

        for (auto s : strs) {
            string tmp = s;
            sort(tmp.begin(),tmp.end());
            hash[tmp].push_back(s);
        }

        for(auto e : hash) {
            result.push_back(e.second);
        }

        return result;
    }
};