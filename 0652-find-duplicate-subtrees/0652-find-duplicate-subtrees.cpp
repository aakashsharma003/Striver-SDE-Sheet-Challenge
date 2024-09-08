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
    vector<TreeNode*>ans;
    string solve(TreeNode* node, unordered_map<string, bool>&mp){
    if(!node) return "";
      string left, right;
      if(node->left == nullptr)
        left = "L";
      else left = solve(node->left, mp);
        if(node->right == nullptr)
          right = "R";
        else right = solve(node->right, mp);
        string cur = to_string(node->val);
        if(mp.find(cur + "->"+ left + "->" + right) != mp.end()){
            if(mp[cur + "->"+ left + "->" + right])
            ans.push_back(node);
            mp[cur + "->"+ left +"->" + right] = false;
        }
        else 
        mp[cur + "->"+ left + "->" + right] = true;
        
        return cur + "->"+ left + "->" + right;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, bool>mp;
        solve(root, mp);
        return ans;
    }
};