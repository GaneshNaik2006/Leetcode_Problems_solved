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
  
ListNode* reverse(ListNode* head){
    if(head==NULL || !head->next) return head;
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
    void reorderList(ListNode* head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* first=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* sec=slow->next;

        sec=reverse(sec);
        slow->next=NULL;
        ListNode* ans=head;
        while( sec){
            ListNode* temp1=first->next;
            ListNode* temp2=sec->next;

            first->next=sec;
            sec->next=temp1;

            first=temp1;
            sec=temp2;
           
        }
      
    }
};