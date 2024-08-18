/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* prev = head, *cur = head;
        while(cur != nullptr && prev != nullptr && cur->next != nullptr){
          prev = prev->next;
          cur = cur->next->next;
          if(prev == cur) return true;
        }
        return false;
    }
};