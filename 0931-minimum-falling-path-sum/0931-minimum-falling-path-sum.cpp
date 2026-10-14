class Solution {
public:
    int f(vector<vector<int>>& nums,int i,int j,int n,vector<vector<int>>& dp)
    {   
        if(i>=n || i<0 || j>=n|| j<0) return 1e9;
        if(i==n-1) return nums[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];

        int x=f(nums,i+1,j-1,n,dp)+nums[i][j];
        
        int y=f(nums,i+1,j,n,dp)+nums[i][j];
        int z=f(nums,i+1,j+1,n,dp)+nums[i][j];

        return dp[i][j]=min({x,y,z});
    }
    int minFallingPathSum(vector<vector<int>>& nums) {
        
        int n=nums.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,f(nums,0,i,n,dp));
        }
        return mini;
    }
};