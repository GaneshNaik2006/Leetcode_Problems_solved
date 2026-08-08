class Solution {
public:
    int ans(int r,int c,vector<vector<bool>>& vis,int n,int m,vector<vector<int>>& dp){
        if(r<0 || c<0 || r>=n || c>=m || vis[r][c]==true) return 0;
        if(r==n-1 && c==m-1) return 1;
        if(dp[r][c]!=0) return dp[r][c];
        vis[r][c]=true;
        int right=ans(r,c+1,vis,n,m,dp);
        int down=ans(r+1,c,vis,n,m,dp);
        vis[r][c]=false;

        return dp[r][c]=right+down;
    }
    int uniquePaths(int n, int m) {
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> dp(n,vector<int>(m,0));
        return ans(0,0,vis,n,m,dp);
    }
};