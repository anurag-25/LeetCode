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
#define pil pair<int,ListNode*>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <pil, vector<pil>, greater<pil>> pq;
        int k = lists.size();
        for (int i=0; i<k; i++) {
            if (lists[i]) pq.push({lists[i]->val, lists[i]});
        }
        ListNode* head = new ListNode(-1), *curr = head;
        int value;
        ListNode* temp = new ListNode();
        while (!pq.empty()) {
            temp = pq.top().second;
            pq.pop();
            curr->next = temp;
            temp = temp->next;
            curr = curr->next;
            if (temp) pq.push ({temp->val, temp});
        }
        return head->next;
    }
};