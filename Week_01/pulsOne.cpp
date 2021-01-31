	class Solution {
	public:
		vector<int> plusOne(vector<int>& digits) {
			int n = digits.size();
			bool flag = true;//最高位溢出

			if (digits[n - 1] != 9)
			{
				digits[n - 1] = digits[n - 1] + 1;
				return digits;
			}
			else
			{
				digits[n - 1] = 0;
			}

			for (int i = digits.size() - 2; i >= 0; i--)
			{
				if (digits[i] != 9)
				{
					flag = false;
					digits[i] = digits[i] + 1;
					return digits;
				}
				else
				{
					digits[i] = 0;
				}
			}
			vector<int> result(n + 1, 0);
			result[0] = 1;
			return result;

		}
};

