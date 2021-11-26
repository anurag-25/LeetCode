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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* kThFromBeg = head;
        for (int i=1; i<k; i++) kThFromBeg = kThFromBeg->next;
        
        ListNode* slow = head, *fast = kThFromBeg;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        swap (slow->val, kThFromBeg->val);
        return head;
    }
};