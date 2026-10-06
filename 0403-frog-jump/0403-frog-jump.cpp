class Solution {
public:

    bool f(vector<int>& nums,int i,int k,int n,vector<vector<int>>& dp,unordered_map<int,int>& mp){
        if(i==n-1) return true;
        if(dp[i][k]!=-1) return dp[i][k];
        
        for(int j=k-1;j<=k+1;j++){
            if(j<=0) continue;

            int nextpos=nums[i]+j;
            if(mp.find(nextpos)!=mp.end()){
               if(f(nums,mp[nextpos],j,n,dp,mp)) return dp[i][k]=true; 
            }
        }

        
        return dp[i][k]=false;

    }

    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(stones[1]!=1) return false;
        if(n==2) return true;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++) mp[stones[i]]=i;
        return f(stones,1,1,n,dp,mp);
    }
};