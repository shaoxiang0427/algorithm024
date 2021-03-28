class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while(n) {
        //方法一：逐位计数
        //    sum += n&1;
        //    n = n>>1;
        //方法二：将n对应二进制最后一位1变为0（并非最低位）
        n = n&(n-1);
        sum++;
        }
    return sum;  
    }
};