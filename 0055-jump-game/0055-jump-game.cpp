class Solution {
public:
    bool f(vector<int>& nums,int i,int n,vector<int>& dp){
        if(i==n-1) return true;
       
        if(i>=n ) return false;
         if(dp[i]!=-1) return dp[i];

        int x=nums[i];
        bool y=false;
        for(int j=1;j<=x;j++){
        if(f(nums,i+j,n,dp)){
            return dp[i]=true;
        }
           
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return f(nums,0,n,dp);
    }
};