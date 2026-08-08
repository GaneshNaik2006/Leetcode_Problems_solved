class Solution {
public:
    int path(vector<vector<int>>& grid,int r,int c,int n ,int m,vector<vector<int>>& dp){
        if( r>=n || c>=m ) return 1e9;
        if(r==n-1 && c==m-1) return grid[r][c];
        if(dp[r][c]!=-1 ) return dp[r][c];
        int right=path(grid,r,c+1,n,m,dp) +grid[r][c];
        int down=path(grid,r+1,c,n,m,dp)+grid[r][c];

        return dp[r][c]=min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
         int n=grid.size();
         int m=grid[0].size();
         vector<vector<int>> dp(n,vector<int>(m,-1));
            return path(grid,0,0,n,m,dp);
    }
};