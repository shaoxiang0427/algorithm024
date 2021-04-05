学习笔记
1、并查集模板
//C/C++
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }
//递归
    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

二、排序初级代码
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//方法一：冒泡排序
void bubblesort(vector<int> &arr) {
	int n = arr.size();

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

//方法二：选择排序
void selectionsort(vector<int> &arr) {
	int n = arr.size();
	int minindex, tmp;

	for (int i = 0; i < n - 1; i++) {
		minindex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[minindex] > arr[j]) {
				minindex = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[minindex];
		arr[minindex] = tmp;
	}
}

//方法三：插入排序
void insertsort(vector<int> &arr) {
	int n = arr.size();

	int index, current;

	for (int i = 1; i < n; i++) {
		index = i - 1;
		current = arr[i];

		while (index >= 0 && arr[index] > current) {
			arr[index + 1] = arr[index];
			index--;
		}
		arr[index + 1] = current;
	}
}

//方法四：希尔排序
void shellsort(vector<int> &arr) {
	int n = arr.size();

	for (int gap = n / 2; gap > 0; gap = gap / 2) {
		for (int i = gap; i < n; i++) {
			int j = i;
			int current = arr[i];
			while ((j - gap) >= 0 && arr[j - gap] > current) {
				arr[j] = arr[j - gap];
				j = j - gap;
			}
			arr[j] = current;
		}
	}
}

//方法五：归并排序
void merge(vector<int> &arr, int left, int mid, int right) {
	vector<int> tmp(right - left + 1);
	int i = left, j = mid + 1;
	int k = 0;

	while (i <= mid&&j <= right) {
		tmp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	}

	while (i <= mid) {
		tmp[k++] = arr[i++];
	}
	while (j <= right) {
		tmp[k++] = arr[j++];
	}

	for (i = left, k = 0; i <= right;) {
		arr[i++] = tmp[k++];
	}
}

void mergesort(vector<int> &arr, int left, int right) {
	if (left >= right) {
		return;
	}

	int mid = left + (right - left) / 2;
	mergesort(arr, left, mid);
	mergesort(arr, mid + 1, right);

	merge(arr, left, mid, right);
}

int main() {
	//int n;
	//vector<int> arr;
	//cin >> n;
	//while (n--) {
	//	int a;
	//	cin >> a;
	//	arr.push_back(a);
	//}

	int a[10] = { 3, 0, 5, 7, 9, 4, 2, 1, 8, 6 };

	vector<int> arr(a, a + 10);

	//bubblesort(arr);
	//selectionsort(arr);
	//insertsort(arr);
	//shellsort(arr);
	mergesort(arr,0,arr.size()-1);

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}

	system("pause");
	return 0;
}