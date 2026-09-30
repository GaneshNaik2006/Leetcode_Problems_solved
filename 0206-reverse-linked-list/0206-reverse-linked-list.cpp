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
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;

        ListNode* prev=NULL;
        ListNode* first=head;
        ListNode* sec=head->next;

        while(first){
            first->next=prev;
            prev=first;
            first=sec;
            if(sec) sec=sec->next;
        }

        return prev;
    }
};