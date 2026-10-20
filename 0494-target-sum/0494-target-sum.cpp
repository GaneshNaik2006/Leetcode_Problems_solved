class Solution {
public:
    int  f(vector<int>& nums,int i,int target,vector<vector<int>>& dp){
     
        if(i<0) return target==0;
        if (abs(target) > 1000) return 0;
        if(dp[i][target+1000]!=-1) return dp[i][target+1000];

        int takep=f(nums,i-1,target-nums[i],dp);
        int taken=f(nums,i-1,target+nums[i],dp);
       

        return dp[i][target+1000]=takep+taken;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2001,-1));

        return f(nums,n-1,target,dp);
    }
};