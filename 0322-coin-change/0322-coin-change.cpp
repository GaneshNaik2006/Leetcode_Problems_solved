class Solution {
public:
    int f(vector<int>& nums,int n,int target,vector<vector<int>>& dp){
        if(target==0) return 0;
        if(target<0) return 1e9;
        if(n<0) return 1e9;
        if(dp[n][target]!=-1) return dp[n][target];

        int take=1+f(nums,n,target-nums[n],dp);
        int nottake=f(nums,n-1,target,dp);

        return dp[n][target]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        
         int ans=f(coins,n-1,amount,dp);

         if(ans==1e9) return -1;
         return ans;
    }
};