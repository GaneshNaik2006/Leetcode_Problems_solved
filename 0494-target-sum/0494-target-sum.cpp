class Solution {
public:
    int f(vector<int>& nums,int k,int i,vector<vector<int>>& dp){
        if(i==0){
            if(k==0 && nums[i]==0) return 2;
            if(k==0 || nums[i]==k) return 1;
            return 0;
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int take=0;
        if(nums[i]<=k)
         take=f(nums,k-nums[i],i-1,dp);
        int nottake=f(nums,k,i-1,dp);

        return dp[i][k]=take+nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum-target <0 || (sum-target)%2!=0) return 0;
        int k=(sum-target)/2;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return f(nums,k,n-1,dp);
    }
};