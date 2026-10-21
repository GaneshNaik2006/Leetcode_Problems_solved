class Solution {
public:
    int f(vector<int>& coins,int i,int amount,vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(i<0) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=0;
        if(amount>=coins[i]) take=f(coins,i,amount-coins[i],dp);
        int nottake=f(coins,i-1,amount,dp);

        return dp[i][amount]=take+nottake;

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int ans= f(coins,n-1,amount,dp);
        return ans;

    }
};