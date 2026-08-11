class Solution {
public:
    int f(vector<int>& nums,int k,int i ,vector<vector<int>>& dp){
        if(i==0) {
            if(k%nums[0]==0) return k/nums[0];
            else return 1e9;
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int nottake=f(nums,k,i-1,dp);
        int take=1e9;
        if(nums[i]<=k) take=1+f(nums,k-nums[i],i,dp);

        return dp[i][k]=min(nottake,take);
    }
    int coinChange(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        int ans=f(nums,k,n-1,dp);
        
        if(ans >= 1e9)
            return -1;

        return ans;
    }
};