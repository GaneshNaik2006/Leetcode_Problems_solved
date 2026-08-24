class Solution {
public:
    int f(vector<int>& prices,int i,int buy,int fee,int n,vector<vector<int>>& dp){
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit=0;
        if(buy){
            profit=max(f(prices,i+1,0,fee,n,dp)-prices[i],f(prices,i+1,1,fee,n,dp));
        }else{
            profit=max(f(prices,i+1,1,fee,n,dp)+prices[i]-fee,f(prices,i+1,0,fee,n,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(prices,0,1,fee,n,dp);
    }
};