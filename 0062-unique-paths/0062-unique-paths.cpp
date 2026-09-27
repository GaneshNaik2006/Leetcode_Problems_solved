class Solution {
public:
    int f(int i,int j,int n,int m,vector<vector<int>>& dp){
        if(i==n-1 && j==m-1) return 1;
        if(i>=n || i<0 || j<0 || j>=m){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int right=f(i,j+1,n,m,dp);
        int down=f(i+1,j,n,m,dp);

        return dp[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(0,0,m,n,dp);
    }
};