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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            len++;
        }
        if (n>len) return head;
        if (n==len) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        temp = head;
        for (int i=0; i<len-n-1; i++) {
            temp = temp->next;
        }
        ListNode* toBeDel = temp->next;
        temp->next = toBeDel->next;
        delete toBeDel;
        return head;
    }
};