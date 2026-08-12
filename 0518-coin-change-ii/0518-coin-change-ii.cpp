class Solution {
public:
    int f(vector<int>& nums,int k,int i ,vector<vector<int>>& dp){
        if(i==0) {
            if(k%nums[0]==0) return 1;
            else return 0;
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int nottake=f(nums,k,i-1,dp);
        int take=0;
        if(nums[i]<=k) take=f(nums,k-nums[i],i,dp);

        return dp[i][k]=nottake+take;
    }
    int change(int k,vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        int ans=f(nums,k,n-1,dp);

        return ans;
    }
};