/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return {};
        }

        stack<TreeNode*> sk;
        sk.push(root);

        while (!sk.empty()) {
            TreeNode *cur = sk.top();
            sk.pop();
            res.push_back(cur->val);

            if (cur->right!=NULL) {
                sk.push(cur->right);
            }
            if (cur->left!=NULL) {
                sk.push(cur->left);
            }
        }

        return res;

    }
};