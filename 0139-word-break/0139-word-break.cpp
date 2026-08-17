class Solution {
public:
    bool f(string& s,vector<string>& nums,int i,vector<int>& dp,int n){
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];
        for(auto word:nums){
            int m=word.size();
            
             if (i + m <= n && s.substr(i, m) == word){
                if(f(s,nums,i+m,dp,n)) return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& nums) {
        int n=s.size();

        vector<int> dp(n,-1);
        return f(s,nums,0,dp,n);
    }
};