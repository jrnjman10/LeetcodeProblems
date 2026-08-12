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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        /*
        We wanna do something where we recurse edge leafs are compared.
        We need to ensure that these leaves are compared in sequence.
        We could just start with the leftmost leaf
        */

        //deal with the null case
        /*
            We could pass the node back to the function if it's null leaves
        */
    

        if(root1->left == nullptr && root1->right == nullptr && root2->left == nullptr && root2->right == nullptr){
            return root1->val == root2->val;
        }else if(root1->left == nullptr && root1->right == nullptr){
            return leafSimilar(root1,root2->left);
        } else if (root2->left == nullptr && root2->right == nullptr){
            return leafSimilar(root1->left,root2);
        } 
        return leafSimilar(root1->left,root2->left);

        /*
        What is our base case?
        passed to roots with no children
        they are the same
        */
    }
};