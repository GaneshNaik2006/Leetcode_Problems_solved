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
    struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;   // min heap based on value
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (int i = 0; i < n; i++) {
            ListNode* curr = lists[i];
            while (curr) {
                pq.push(curr);
                curr = curr->next;
            }
        }
        if(pq.empty()) return NULL;

        ListNode* head = pq.top();
        ListNode* temp = head;
        pq.pop();
        while (!pq.empty()) {
            temp->next = pq.top();
            pq.pop();
            temp=temp->next;
        }
          temp->next = nullptr;
       
        return head;
    }
};