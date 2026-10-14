class Solution {
public:
      int f(vector<int>& nums,int i,int buy,int n,vector<vector<vector<int>>>& dp,int cnt){
        if(i==n || cnt==2) return 0;
        if(dp[i][buy][cnt]!=-1) return dp[i][buy][cnt];

        if(buy){
            int take=f(nums,i+1,0,n,dp,cnt)-nums[i];
            int nottake=f(nums,i+1,1,n,dp,cnt);

            return dp[i][buy][cnt]=max(take,nottake);
        }else{
             int take=f(nums,i+1,1,n,dp,cnt+1)+nums[i];
            int nottake=f(nums,i+1,0,n,dp,cnt);

            return dp[i][buy][cnt]=max(take,nottake);
        }
        return 0;
    }
   int maxProfit(vector<int>& nums) {
        int n=nums.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(4,-1)));
        int cnt=0;
        return f(nums,0,1,n,dp,cnt);
    }
};