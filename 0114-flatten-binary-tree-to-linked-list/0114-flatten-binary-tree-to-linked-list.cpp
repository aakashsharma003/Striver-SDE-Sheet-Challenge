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
   void solve(TreeNode* node){
    if(!node) return;

     solve(node->right);
      solve(node->left);
     TreeNode* rightmost = node->left;
     while(rightmost != nullptr && rightmost->right != nullptr){
         rightmost = rightmost->right;
     }

     if(rightmost != nullptr)
     rightmost -> right = node->right;
     
     if(node->left != nullptr)
     node->right = node->left;
     node->left = nullptr;
     return;
   }

    void flatten(TreeNode* root) {
        solve(root);
        return;
    }
};