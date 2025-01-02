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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL) return root;
        if(root -> left == NULL && root -> right == NULL) return root;
        int level = 0;
        queue<TreeNode*> q;
        queue<TreeNode*> q2;
        q.push(root);
        TreeNode* head = new TreeNode(root -> val);
        q2.push(head);
        stack<TreeNode*> st;
        while(q.size() > 0) {
            int size = q.size();
            level++;
            for(int i = 0 ; i < size ; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // If the level is odd
                if(level % 2 != 0) {
                    if(curr -> left != NULL) st.push(curr -> left);
                    if(curr -> right != NULL) st.push(curr -> right);
                }
                if(curr -> left != NULL) q.push(curr -> left);
                if(curr -> right != NULL) q.push(curr -> right);
            }
            if(q.size() == 0) {
                for(int i = 0 ; i < size ; i++) {
                    TreeNode* newCurr = q2.front();
                    q2.pop();

                    newCurr -> left = NULL;
                    newCurr -> right = NULL;
                }
                return head;
            }
            // If level is odd then reverse that level 
            if(level % 2 != 0) {
                for(int i = 0 ; i < size ; i++) {
                    TreeNode* newCurr = q2.front();
                    q2.pop();

                    TreeNode* currLeft = st.top();
                    st.pop();
                    q2.push(currLeft);

                    TreeNode* currRight = st.top();
                    st.pop();
                    q2.push(currRight);

                    newCurr -> left = currLeft;
                    newCurr -> right = currRight;
                }
            }
            else {
                for(int i = 0 ; i < size ; i++) {
                    TreeNode* newCurr = q2.front();
                    q2.pop();

                    TreeNode* currLeft = q.front();
                    q.pop();
                    q.push(currLeft);
                    q2.push(currLeft);

                    TreeNode* currRight = q.front();
                    q.pop();
                    q.push(currRight);
                    q2.push(currRight);

                    newCurr -> left = currLeft;
                    newCurr -> right = currRight;
                }
            }
        }
        return head;
    }
};