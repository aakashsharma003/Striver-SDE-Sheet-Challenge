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
   void preOrder(TreeNode* curNode,  vector<TreeNode*>&pref){
       if(!curNode) return;
       pref.push_back(curNode);
       preOrder(curNode->left, pref);
         preOrder(curNode->right, pref);
         return;
   }


    void flatten(TreeNode* root) {
        if(!root) return;
       vector<TreeNode*> pref;
       preOrder(root, pref);
       TreeNode* cur = pref[0];
       cur->left = nullptr;
       for(int i = 1;i < pref.size();i++){
             cur->right = pref[i];
             cur = cur ->right;
             pref[i]->left = nullptr;
       }
       root = cur;
       return;
    }
};