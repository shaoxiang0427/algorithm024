/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> res;

    void traveral(Node *root) {
		//时间复杂度：O(N)；空间复杂度O(N)
        if (root ==NULL) {
            return ;
        }
        res.push_back(root->val);

        for(int i = 0;i<root->children.size();i++) {
            traveral(root->children[i]);
        }
    }
    vector<int> preorder(Node* root) {
        traveral(root);
        return res;
    }
};