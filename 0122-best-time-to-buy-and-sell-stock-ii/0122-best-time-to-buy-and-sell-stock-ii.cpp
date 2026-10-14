class Solution {
public:
    int f(vector<int>& nums,int i,int buy,int n,vector<vector<int>>& dp){
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        if(buy){
            int take=f(nums,i+1,0,n,dp)-nums[i];
            int nottake=f(nums,i+1,1,n,dp);

            return dp[i][buy]=max(take,nottake);
        }else{
             int take=f(nums,i+1,1,n,dp)+nums[i];
            int nottake=f(nums,i+1,0,n,dp);

            return dp[i][buy]=max(take,nottake);
        }
        return 0;
    }
    int maxProfit(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>> dp(n+1,vector<int>(3,-1));

        return f(nums,0,1,n,dp);
    }
};