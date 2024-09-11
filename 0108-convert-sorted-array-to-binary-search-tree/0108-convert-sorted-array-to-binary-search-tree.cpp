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
    void generateTree(TreeNode* &root, int start, int end, vector<int> &nums) {
        if(start <= end) {
            int mid = ((start) + ((end - start) / 2));
            root = new TreeNode(nums[mid]);
            generateTree(root -> left, start, mid - 1, nums);
            generateTree(root -> right, mid + 1, end, nums);
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = new TreeNode(0);
        generateTree(root, 0, nums.size() - 1, nums);
        return root;
    }
};