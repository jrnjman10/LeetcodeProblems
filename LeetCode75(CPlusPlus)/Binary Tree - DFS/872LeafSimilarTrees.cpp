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


void getLeafNodes(TreeNode* root, vector<int>& leafNodes);

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
    

        vector<int> leafNode_root1, leafNode_root2;
        getLeafNodes(root1, leafNode_root1);
        getLeafNodes(root2, leafNode_root2);
        return leafNode_root1 == leafNode_root2;

        /*
        What is our base case?
        passed to roots with no children
        they are the same
        */
    }
};

void getLeafNodes(TreeNode* root, vector<int>& leafNodes){
    if(!root){
        return;
    }

    if(!root->left && !root->right){
        leafNodes.push_back(root->val);
        return;
    }

    getLeafNodes(root->left,leafNodes);
    getLeafNodes(root->right,leafNodes);
    
}