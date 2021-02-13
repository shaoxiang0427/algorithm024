class Solution {
public:
    vector<vector<int>> res;//最终结果；
    vector<int> tmp;//其中一种结果；

    void dfs(int n,int k,int begin) {
        //预剪枝：数据的个数不足k个时，直接退出
        if (tmp.size() + (n-begin+1) < k) {
            return ;
        }

        //当选取的数量 == k时，将结果保存到res中
        if (tmp.size() == k) {
            res.push_back(tmp);
            return ;
        }

        //选取当前数据时；
        tmp.push_back(begin);
        dfs(n,k,begin + 1);
        //不选取当前数据时；
        tmp.pop_back();
        dfs(n,k,begin + 1);
    }
    vector<vector<int>> combine(int n, int k) {
        //处理非常规情况
        if (k == 0 || n<k) {
            return res;
        }
        dfs(n,k,1);
        return res;
    }
};

// class Solution {
// private :
// 	void dfs(int n, int k, int index, vector<int>& path, vector<vector<int>>& res) {
// 		if (path.size() == k) {
// 			res.push_back(path);
// 			return;
// 		}

// 		// 搜索起点的上界 + 接下来要选择的元素个数 - 1 = n
// 		// 接下来要选择的元素个数 = k - path.size()
// 		// 搜索起点的上界 = n - (k - path.size()) + 1
// 		for (int i = index; i <= n - (k - path.size()) + 1; ++i) {
// 			path.push_back(i);
// 			dfs(n, k, i + 1, path, res);
// 			path.pop_back();
// 		}
// 	}

// public:
// 	vector<vector<int>> combine(int n, int k) {
// 		vector<vector<int>> res;
// 		if (k <= 0 || n < k) {
// 			return res;
// 		}
// 		vector<int> path;
// 		dfs(n, k, 1, path, res);
// 		return res;
// 	}
// };