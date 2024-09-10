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
class Solution {
public:
    int gcd(int x, int y) {
        while (x > 0 && y > 0) {
            if (x > y)
                x = x % y;
            else
                y = y % x;
        }
        if (x == 0)
            return y;
        else
            return x;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            prev = curr;
            curr = curr->next;
            if (curr == NULL)
                break;
            int value = gcd(prev->val, curr->val);
            ListNode* newnode = new ListNode(value);
            newnode->next = prev->next;
            prev->next = newnode;
        }
        return head;
    }
};