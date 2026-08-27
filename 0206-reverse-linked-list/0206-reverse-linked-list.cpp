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
        
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* curr=head;
    ListNode*  prev=NULL;
    if(!curr->next) return curr;
    ListNode* sec=curr->next;
    while(curr && sec){
        
        ListNode* third=sec->next;
        curr->next=prev;
       
        sec->next=curr;
         prev=sec;
        curr=third;
        if(third) sec=third->next;
       
    }
    if(curr) {
        curr->next=prev;
        prev=curr;
    }
    return prev;
    }

 
};