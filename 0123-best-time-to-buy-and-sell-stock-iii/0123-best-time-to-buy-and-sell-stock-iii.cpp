class Solution {
public:
    int f(vector<int>& prices,int i,int buy,int cap,int n,vector<vector<vector<int>>>& dp){
        if(i==n) return 0;
        if(cap==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];

        int profit=0;
        if(buy){
            profit=max(f(prices,i+1,0,cap,n,dp)-prices[i],f(prices,i+1,1,cap,n,dp));

        }else{
            profit=max(f(prices,i+1,1,cap-1,n,dp)+prices[i],f(prices,i+1,0,cap,n,dp));
        }
        return dp[i][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(prices,0,1,2,n,dp);

    }
};