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
        if (!head) return false;
        unordered_set <ListNode*> seen;
        while (head) {
            if (seen.find(head) != seen.end()) return true;
            seen.insert (head);
            head = head->next;
        }
        return false;
    }
};