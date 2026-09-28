class Solution {
public:
    int f(vector<int>& nums,int n,vector<int>& dp){
        if(n==0) return nums[0];
        if(n<0 ) return 0;
        if(dp[n]!=-1) return dp[n];

        int take=nums[n]+f(nums,n-2,dp);
        int notake=f(nums,n-1,dp);

        return dp[n]=max(take,notake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return f(nums,n-1,dp);
    }
};