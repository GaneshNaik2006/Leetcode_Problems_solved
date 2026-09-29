class Solution {
public:
    bool f(vector<vector<char>>& grid,int n,int m,int score,int i,int j,vector<vector<vector<int>>>& dp){
        if(score==0 && ((i==n && j==m-1) || (i==n-1 && j==m))) return true;
        
        if( i>=n || j>=m || score<0 ) return false;
        if(dp[i][j][score]!=-1) return dp[i][j][score];
        if(grid[i][j]=='('){
            if(f(grid,n,m,score+1,i+1,j,dp)) return true;
            if(f(grid,n,m,score+1,i,j+1,dp)) return true;
        }if(grid[i][j]==')'){
            if(f(grid,n,m,score-1,i+1,j,dp)) return true;
            if(f(grid,n,m,score-1,i,j+1,dp)) return true;
        }
        return dp[i][j][score]= false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(n+m+1,-1)));
        return f(grid,n,m,0,0,0,dp);
    }
};