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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode (-1);
        ListNode* geq = new ListNode (-1);

        ListNode *newHead = small, *geqHead = geq;
        while (head) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            }
            else {
                geq->next = head;
                geq = geq->next;
            }
            head = head->next;
        }
        geq->next = NULL;
        small->next = geqHead->next;
        return newHead->next;
    }
};