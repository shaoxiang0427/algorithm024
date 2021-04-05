class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());

        if(n==1)
        {
            return intervals;
        }
        int a = intervals[0][0];
        int b = intervals[0][1];
        for(int i = 0;i<n-1;i++)
        {
            if(b<intervals[i+1][0])
            {
                result.push_back({a,b});
                a = intervals[i+1][0];
                b = intervals[i+1][1];
            }
            else if(b>=intervals[i+1][0]&&b<intervals[i+1][1])
            {
                b = intervals[i+1][1];
            }
            else
            {

            }
                if(i == n-2)
                {
                    result.push_back({a,b});
                }
        }

        return result;

    }
};