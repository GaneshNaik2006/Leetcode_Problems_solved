class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();

        stack<int> st;
        vector<int> ans(n,INT_MIN);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]) st.pop();
            if(!st.empty())
            ans[i]=st.top();
            st.push(nums[i]);
            
        }

        

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]) st.pop();
            
            if(!st.empty() && ans[i]==INT_MIN)
            ans[i]=st.top();

            st.push(nums[i]);
        }

        for(int i=0;i<n;i++){
            if(ans[i]==INT_MIN) ans[i]=-1;
        }

        return ans;


    }
};