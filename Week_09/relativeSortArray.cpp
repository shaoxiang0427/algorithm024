class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> hash1,hash2;
        vector<int> result,tmp;

        for(int j = 0;j<arr2.size();j++) {
            hash2[arr2[j]]++;
        }

        for(int i = 0;i<arr1.size();i++) {
            if (hash2[arr1[i]]==0) {
                tmp.push_back(arr1[i]);
            } else {
                hash1[arr1[i]]++;
            }
        }
    
        for(int i = 0;i<arr2.size();i++) {
            for(int j = 0;j<hash1[arr2[i]];j++) {
                result.push_back(arr2[i]);
            }
        }

        sort(tmp.begin(),tmp.end());

        for(int i = 0;i<tmp.size();i++) {
            result.push_back(tmp[i]);
        }

        return result;

    }
};