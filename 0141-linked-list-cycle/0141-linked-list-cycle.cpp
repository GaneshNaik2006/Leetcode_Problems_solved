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
        ListNode* slow=head;
        ListNode* fast=head;

        while(slow!=NULL && fast!=NULL){
            slow=slow->next;
            if(fast->next==NULL) break;
            fast=fast->next->next;
            if(slow && fast && slow==fast) return true;
        }
        return false;
    }
};