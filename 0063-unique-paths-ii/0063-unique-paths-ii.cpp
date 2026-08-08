class Solution {
public:
    int ans(vector<vector<int>>& nums,int r,int c,int n,int m,vector<vector<int>>& dp){
        if(r<0 || c<0 || r>=n || c>=m || nums[r][c]==1) return 0;
        if(r==n-1 && c==m-1) return 1;
        if(dp[r][c]!=0) return dp[r][c];
      
        int right=ans(nums,r,c+1,n,m,dp);
        int down=ans(nums,r+1,c,n,m,dp);
   
        return dp[r][c]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
         if (nums[0][0] == 1 || nums[n - 1][m - 1] == 1)
            return 0;

        vector<vector<int>> dp(n,vector<int>(m,0));
        return ans(nums,0,0,n,m,dp);
    }
};