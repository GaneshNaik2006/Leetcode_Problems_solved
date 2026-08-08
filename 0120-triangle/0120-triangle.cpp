class Solution {
public:
    int ans(vector<vector<int>>& nums,int i,int j,int n,vector<vector<int>>& dp){
         if (i == n - 1)
            return nums[i][j];
            
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int down = ans(nums, i + 1, j, n,dp);
        int diagonal = ans(nums, i + 1, j + 1, n,dp);

        return dp[i][j]=nums[i][j] + min(down, diagonal);
       
        
         }
    int minimumTotal(vector<vector<int>>& nums) {
        int n=nums.size();
        
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        return ans(nums,0,0,n,dp);
    }
};