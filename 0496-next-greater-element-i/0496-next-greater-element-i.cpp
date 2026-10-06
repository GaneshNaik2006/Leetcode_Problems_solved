class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();

        unordered_map<int,int> mp;
        stack<int> st;
        for(int i=0;i<n;i++) mp[nums2[i]]=i;

        vector<int> temp(n,-1);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums2[st.top()]<=nums2[i]){
                st.pop();
            }
            if(!st.empty())
            temp[i]=nums2[st.top()];
            st.push(i);
        }

        int m=nums1.size();

        vector<int> ans(m);

        for(int i=0;i<m;i++){
            ans[i]=temp[mp[nums1[i]]];
        }

        return ans;



    }
};