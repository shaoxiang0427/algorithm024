class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        int max = 0;
        for(auto e : nums)
        {
            sum += e;
            if(e>max)
            {
                max = e;
            }
        }

        int left = max;
        int right = sum;
        int mid;

        while(left < right)
        {
            mid = (left + right)/2;
            int cnt = 1;
            int sum_tmp = 0;
            for(int i = 0;i<nums.size();i++)
            {
                sum_tmp += nums[i];
                if(sum_tmp > mid)
                {
                    cnt++;
                    sum_tmp = nums[i];
                }
            }

            if(cnt > m)
            {
                left = mid+1;
            }
            else 
            {
                right = mid;
            }
        }

        return left;

    }
};