class Solution {
public:
    int memo(vector<int>& nums,vector<int>& dp,int i){
        if(i<0) return 0;
        if(i==0 ) return nums[i];
        // if(i==1) return max(nums[0],nums[1]);
        if(dp[i]!=-1) return dp[i];

        int left=memo(nums,dp,i-1);
        int include=memo(nums,dp,i-2)+nums[i];

        return dp[i]=max(left,include);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> dp(n+1,-1);
    
        return memo(nums,dp,n-1);
    }
};