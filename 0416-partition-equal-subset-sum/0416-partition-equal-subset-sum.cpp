class Solution {
public:
    bool f(vector<int>& nums,int i,int sum,int ts,vector<vector<int>>& dp){
        if(ts==sum) return true;
        if(ts-sum <0 || i<0) return false;
        if(dp[i][ts-sum]!=-1) return dp[i][ts-sum];
        bool take=false;
       if(ts>=nums[i]) take=f(nums,i-1,sum+nums[i],ts-nums[i],dp);
       bool nottake=f(nums,i-1,sum,ts,dp);

       return dp[i][ts-sum]=(take||nottake);  
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();

        int ts=0;

        for(int i=0;i<n;i++) {
            ts+=nums[i];
        }

        vector<vector<int>> dp(n,vector<int>(ts+1,-1));

        return f(nums,n-1,0,ts,dp);
    }
};