class Solution {
public:
    int lastStoneWeightII(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        vector<vector<bool>> dp(n,vector<bool>(totalsum+1,false));

        for(int i=0;i<n;i++) dp[i][0]=true;
        if(nums[0]<=totalsum) dp[0][nums[0]]=true;

        for(int i=1;i<n;i++){

            for(int j=1;j<=totalsum;j++){
                bool nottake=dp[i-1][j];
                bool take=false;
                if(nums[i]<=j){
                    take=dp[i-1][j-nums[i]];
                } 

                dp[i][j]=nottake || take;
            }
        }


    
        int ans=INT_MAX;

        for(int i=0;i<=totalsum;i++){
            if(dp[n-1][i]){
                ans=min(ans,abs(2*i-totalsum));
            }
        }
       

        return ans;
    }
};