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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> idx;
        ListNode* temp=head;
        ListNode* prev=NULL;
        int i=0;
        
        while(temp!=NULL){
            if(prev && temp->next){
               if(prev->val >temp->val && temp->next->val >temp->val){
               
                    idx.push_back(i+1);
               }else if(prev->val <temp->val && temp->next->val <temp->val){
                    
                    idx.push_back(i+1);
               }
            }
            prev=temp;
            temp=temp->next;
            i++;
        }

        int minidx=INT_MAX;
        int maxidx=INT_MIN;
        int n=idx.size();
        if(n<2) return {-1,-1};
        for(int i=1;i<n;i++){
            minidx=min(idx[i]-idx[i-1],minidx);
        }
       
       maxidx=idx[n-1]-idx[0];

       return {minidx,maxidx};
    }
};