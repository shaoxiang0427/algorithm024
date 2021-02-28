class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        if (n == 0 || bills[0]!=5) {
            return false;
        }

        int n5 = 0;
        int n10 = 0;

        for(int i = 0;i<n;i++) {
            if (bills[i] == 5) {
                n5++;
            } else if(bills[i] == 10) {
                n10++;
                n5--;
                if (n5<0) {
                    return false;
                }
            } else {
                if (n10>0&&n5>0) {
                    n10--;
                    n5--;
                } else if (n5>=3) {
                    n5 = n5 - 3;
                } else {
                    return false;
                }
            }
        }
        return true;

    }
};