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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<pair<int,ListNode*>> arr1;
         vector<pair<int,ListNode*>> arr2;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1){
            arr1.push_back({temp1->val,temp1});
            temp1=temp1->next;
        }
        
        while(temp2){
              arr2.push_back({temp2->val,temp2});
            temp2=temp2->next;
        }

        int n=arr1.size(),m=arr2.size();
        ListNode* ans=NULL;
        // for(int i=0;i<n;i++) cout<<arr1[i].first<<endl;
        // cout<<"hi"<<endl;
        // for(int i=0;i<m;i++) cout<<arr2[i].first<<endl;
       int i=n-1,j=m-1;
       while(i>=0 && j>=0){
        
                if( arr1[i]==arr2[j] ){
                   ans=arr1[i].second;
                }
            
            i--,j--;
       }

       return ans;


    }
};