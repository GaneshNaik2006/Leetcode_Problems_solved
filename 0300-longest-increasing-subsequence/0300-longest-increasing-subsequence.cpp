class Solution {
public:
    int f(vector<int>& nums,int i,int prev,int n,vector<vector<int>>& dp){
        if(i==n) return 0;
        if( prev!=-1 && dp[i][prev]!=-1) return dp[i][prev];

        int take=0;
        if(prev==-1 || nums[i]>nums[prev]) 
        take=1+f(nums,i+1,i,n,dp);
        int nottake=f(nums,i+1,prev,n,dp);

       if(prev==-1) prev=0;

       return dp[i][prev]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        return f(nums,0,-1,n,dp);
    }
};