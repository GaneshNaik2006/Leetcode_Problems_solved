class Solution {
public:
    int f(vector<vector<int>>& nums,int i,int j,int n,int m,vector<vector<int>>& dp){
        if(i==n && j==m-1) return 1;
        if( i>=n || j>=m || nums[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int right=f(nums,i,j+1,n,m,dp);
        int down=f(nums,i+1,j,n,m,dp);

        return dp[i][j]=right+down;
     }
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return f(nums,0,0,n,m,dp);
    }
};