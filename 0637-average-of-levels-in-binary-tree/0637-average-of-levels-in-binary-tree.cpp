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
    vector<double> ans;
    void LevelOrderTraversal(TreeNode* &root) {
        if(root == NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        double sum = 0, ct = 0;
        while(q.size() > 1) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL) {
                ans.push_back(sum / ct);
                q.push(NULL);
                sum = 0;
                ct = 0;
                continue;
            }
            sum += (double)(curr -> val);
            ct++;
            if(curr -> left != NULL) 
            q.push(curr -> left);
            if(curr -> right != NULL) 
            q.push(curr -> right);
        }
        ans.push_back(sum / ct);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        LevelOrderTraversal(root);
        return ans;
    }
};