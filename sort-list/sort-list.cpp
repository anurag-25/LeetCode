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
    void splitLL (ListNode* head, ListNode** left, ListNode** right) {
        *left = head;
        ListNode* fast = head, *prev = NULL;
        while (fast && fast->next) {
            if (prev==NULL) prev = head;
            else prev = prev->next;
            fast = fast->next->next;
        }
        *right = prev->next;
        prev->next = NULL;
    }
    
    ListNode* merge (ListNode* left, ListNode* right) {
        ListNode* head = new ListNode (-1);
        ListNode* temp = head;
        while (left && right) {
            if (left->val < right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if (left) temp->next = left;
        else temp->next = right;
        
        return head->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (head==NULL || head->next == NULL) return head; 
        
        ListNode* left = NULL, *right = NULL;
        splitLL (head, &left, &right);
        
        left = sortList (left);
        right = sortList (right);
        
        return merge (left, right);
    }
};