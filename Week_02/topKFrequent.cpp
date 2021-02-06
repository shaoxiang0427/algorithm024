class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> hash;

        for (auto e : nums) {
            hash[e]++;
        }

        priority_queue<pair<int,int> > pq;

        for (auto e : hash)
        {
            pair<int,int> tmp(e.second,e.first);
            pq.push(tmp);
        }

        for (int i = 0;i<k;i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};