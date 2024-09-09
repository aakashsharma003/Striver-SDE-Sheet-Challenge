/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool solve(ListNode* cur, ListNode* head,TreeNode* node){
       if(!node || !cur) return cur == nullptr;
       bool left = false, right = false;
       if(node->val == cur->val){
            left = solve(cur->next, head, node->left);
            right = solve(cur->next, head, node->right);
       }
       else{
          left = solve(head, head, node->left);
          right = solve(head, head, node->right);
       }
    //    cout<<"node"<<node->val<<endl;
    //    cout<<left<<" "<<right<<endl;
      return left || right;
   }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head || !root)return false;

        return solve(head, head, root)|| isSubPath(head,root->left) || isSubPath(head,root->right);

    }

};