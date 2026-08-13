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
    TreeNode* searchBST(TreeNode* root, int val) {
        queue<TreeNode*> q;
        q.push(root);
        int size;
        TreeNode* curr;
        while(!q.empty()){
            size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                if(curr->val == val) return curr;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                q.pop(); 
            }
        }
        return nullptr;
    }
};