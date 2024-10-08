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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root1);
        q2.push(root2);

        while(!q1.empty() || !q2.empty()) {
            TreeNode* curr1 = q1.front();
            TreeNode* curr2 = q2.front();
            q1.pop();
            q2.pop();

            curr1 -> val += curr2 -> val;

            if(curr1 -> left != NULL) {
                q1.push(curr1 -> left);
                if(curr2 -> left != NULL) q2.push(curr2 -> left);
                else {
                    curr2 -> left = new TreeNode(0);
                    q2.push(curr2 -> left);
                }
            }
            else if(curr2 -> left != NULL) {
                q2.push(curr2 -> left);
                if(curr1 -> left != NULL) q1.push(curr1 -> left);
                else {
                    curr1 -> left = new TreeNode(0);
                    q1.push(curr1 -> left);
                }
            }

            if(curr1 -> right != NULL) {
                q1.push(curr1 -> right);
                if(curr2 -> right != NULL) q2.push(curr2 -> right);
                else {
                    curr2 -> right = new TreeNode(0);
                    q2.push(curr2 -> right);
                }
            }
            else if(curr2 -> right != NULL) {
                q2.push(curr2 -> right);
                if(curr1 -> right != NULL) q1.push(curr1 -> right);
                else {
                    curr1 -> right = new TreeNode(0);
                    q1.push(curr1 -> right);
                }
            }
        }
        return root1;
    }
};