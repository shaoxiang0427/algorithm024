学习笔记

一、dfs模板
//C/C++//递归写法：
map<int, int> visited;
void dfs(Node* root) {  
	// terminator  
	if (!root) return ; 
	
	if (visited.count(root->val)) {    
	// already visited    
	return ;  
	}  

	visited[root->val] = 1;  
	// process current node here.   
	// ...  
	for (int i = 0; i < root->children.size(); ++i) {    
	dfs(root->children[i]);  
	}  
	return ;
}

//C/C++//非递归写法：
void dfs(Node* root) {
	map<int, int> visited; 
	if(!root) return ;  
	
	stack<Node*> stackNode;  
	stackNode.push(root);  
	
	while (!stackNode.empty()) {    
		Node* node = stackNode.top();    
		stackNode.pop();    
		if (visited.count(node->val)) continue;    
		visited[node->val] = 1;   
		
		//倒序加入stack
		for (int i = node->children.size() - 1; i >= 0; --i) {        
			stackNode.push(node->children[i]);    
		}  
	}  
	
	return ;
}

二、bfs模板
// C/C++
void bfs(Node* root) {  
	map<int, int> visited;  
	if(!root) return ;  
	
	queue<Node*> queueNode;  
	queueNode.push(root);  
	
	while (!queueNode.empty()) {    
		Node* node = queueNode.top();    
		queueNode.pop();    
		if (visited.count(node->val)) continue;   
		visited[node->val] = 1; 
		  
		for (int i = 0; i < node->children.size(); ++i) {        
			queueNode.push(node->children[i]);    
		} 
	} 
	
	return ;
}

三、贪心算法
所谓贪心算法是指，在对问题求解时，总是做出在当前看来是最好的选择。也就是说，不从整体最优上加以考虑，它所做出的仅仅是在某种意义上的局部最优解。
贪心算法没有固定的算法框架，算法设计的关键是贪心策略的选择。必须注意的是，贪心算法不是对所有问题都能得到整体最优解，选择的贪心策略必须具备无后效性（即某个状态以后的过程不会影响以前的状态，只与当前状态有关。）
所以，对所采用的贪心策略一定要仔细分析其是否满足无后效性。

四、二分查找：前提是有序
C/C++模板
int binarySearch(const vector<int>& nums, int target) {	
	int left = 0, right = (int)nums.size()-1;
	
	while (left <= right) {		
		int mid = left + (right - left)/ 2;		
		if (nums[mid] == target) return mid;		
		else if (nums[mid] < target) left = mid + 1;		
		else right = mid - 1;	
	}		
	return -1;
	}
