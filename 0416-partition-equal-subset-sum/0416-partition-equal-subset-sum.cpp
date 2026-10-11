class Solution {
public:
    bool f(vector<int>& nums,int i,int n,int sum,int total,vector<vector<int>>& dp){
        if(total-sum==0) return true;
        if(i>=n || sum<0 || total<0 || total-sum <0) return false;

        if(dp[i][total-sum]!=-1) return dp[i][total-sum];

        if(f(nums,i+1,n,sum+nums[i],total-nums[i],dp)) return dp[i][total-sum]=true;
        if(f(nums,i+1,n,sum,total,dp)) return dp[i][total-sum]=true;

        return dp[i][total-sum]=false;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();

        int sum=0;
        
        int total=0;

        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        vector<vector<int>> dp(n+1,vector<int> (total+1,-1));
        return f(nums,0,n,sum,total,dp);
    }
};