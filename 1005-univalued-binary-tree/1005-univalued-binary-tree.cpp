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
    bool solve(TreeNode* &root, int value) {
        if(root == NULL) return true;
        if(root -> val != value) return false;
        return (solve(root -> left, value) && solve(root -> right, value));
    }
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL) return true;
        if(root -> left == NULL && root -> right == NULL) return true;
        return solve(root, root -> val);
    }
};