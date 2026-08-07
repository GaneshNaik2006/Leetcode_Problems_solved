class Solution {
public:
     int memo1(vector<int>& nums,vector<int>& dp,int i){
        if(i<0) return 0;
        if(i==0 ) return nums[i];
        if(dp[i]!=-1) return dp[i];

        int left=memo1(nums,dp,i-1);
        int include=memo1(nums,dp,i-2)+nums[i];

        return dp[i]=max(left,include);
    }
       int memo2(vector<int>& nums,vector<int>& dp,int i){
        if(i<1) return 0;
        if(i==1 ) return nums[i];
        if(dp[i]!=-1) return dp[i];

        int left=memo2(nums,dp,i-1);
        int include=memo2(nums,dp,i-2)+nums[i];

        return dp[i]=max(left,include);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        int a1=memo1(nums,dp1,n-2);
        int a2=memo2(nums,dp2,n-1);

        return max(a1,a2);
    }
};