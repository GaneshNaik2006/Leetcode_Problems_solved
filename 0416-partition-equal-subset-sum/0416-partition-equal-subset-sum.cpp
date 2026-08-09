class Solution {
public:
    bool can(vector<int>& nums,int k,int sum ,int i,vector<vector<int>>& dp){
        if(k==sum ) return true;
        if(i==0) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool one=can(nums,k,sum+nums[i],i-1,dp);
        bool two=can(nums,k,sum,i-1,dp);
        return dp[i][sum]=one||two;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int k=0;

        for(int i=0;i<n;i++){
            k+=nums[i];
        }
        if(k%2!=0) return false;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return can(nums,k/2,0,n-1,dp);
    }
};