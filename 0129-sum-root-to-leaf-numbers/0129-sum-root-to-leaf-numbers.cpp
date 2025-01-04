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
    int getSum(TreeNode* &root, int sum, int num) {
        if(root -> left == NULL && root -> right == NULL) {
            num = (num * 10) + (root -> val);
            sum += num;
            return sum;
        }
        else if(root -> left == NULL && root -> right != NULL) {
            num = (num * 10) + (root -> val);
            return getSum(root -> right, sum, num);
        }
        else if(root -> left != NULL && root -> right == NULL) {
            num = (num * 10) + (root -> val);
            return getSum(root -> left, sum, num);
        }
        num = (num * 10) + (root -> val);
        int leftSum = getSum(root -> left, sum, num);
        int rightSum = getSum(root -> right, sum, num);
        num = num % 10;

        return (leftSum + rightSum);
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        int sum = 0, num = 0;
        return getSum(root, sum, num);
    }
};