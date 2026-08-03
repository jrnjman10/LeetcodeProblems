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
    int maxDepth(TreeNode* root) {
        /*
        there are a few scenarios
        you arrive at a node
        1. it has no children
        2. it has one child (L/R)
        3. it has two children

        Right now we are deciding between breadth first and depth first search
        DFS
        1. return 1
        2. return 1 + maxDepth(Child)
        3. return 1 + maxDepth(ChildL) > 1 + maxDepth(ChildR)

        That would work with recursion
        How can I turn a recursive answer into 2 for loops?
        */
        if(root == nullptr) return 0;
        int L = maxDepth(root->left);
        int R = maxDepth(root->right);
        return max(L,R)+1;
    }
};