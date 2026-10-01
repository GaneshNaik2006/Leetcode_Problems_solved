class Solution {
public:
    int f(vector<int>& nums,int st,int n,vector<int>& dp){
        if(n==st) return nums[st];
        if(n<st) return 0;
        if(dp[n]!=-1) return dp[n];

        int take=nums[n]+f(nums,st,n-2,dp);
        int nottake=f(nums,st,n-1,dp);

        return dp[n]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n+1,-1);

        vector<int> dp2(n+1,-1);
        int f1=f(nums,1,n-1,dp1);
        int f2=f(nums,0,n-2,dp2);

        return max(f1,f2);
    }
};