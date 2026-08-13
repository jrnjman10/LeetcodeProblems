
  //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

#include <vector>
#include <queue>
#include <iostream>

using std::vector;
using std::queue ;
using std::cout;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        queue<TreeNode*> q;
        if(!root){
            return rightView;
        }
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                if(size-1 == i){
                    rightView.push_back(curr->val);
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                q.pop();
            }
        }


        return rightView;
    }
};

int main() {
        // Build tree:      1
    //                 / \
    //                2   3
    //                 \    \
    //                  5    4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    cout << "Right side view: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}