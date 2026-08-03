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
        //Let's just do recursive first and go from there
        if(root == nullptr){
            return 0;
        }

        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }

        if(root->left == nullptr){ //there is no left child
            return 1 + maxDepth(root->right);
        } else if(root->right == nullptr){ //there is no right child
            return 1 + maxDepth(root->left);
        } else {//there are two children
            int mDepthL = maxDepth(root->left);
            int mDepthR = maxDepth(root->right);
            if(mDepthL > mDepthR ){ //if left value is > right
                return 1 + mDepthL;
            } else {
                return 1 + mDepthR;
            }
        }
    }
};