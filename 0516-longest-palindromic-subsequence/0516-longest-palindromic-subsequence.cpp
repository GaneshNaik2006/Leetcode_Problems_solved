class Solution {
public:
    

    int sub(string& s,int i,int j,vector<vector<int>>& dp){
       if(i>j) return 0;
       if(i==j) return 1;
       if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]) return 2+sub(s,i+1,j-1,dp);
        return dp[i][j]=max(sub(s,i+1,j,dp),sub(s,i,j-1,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
       
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return sub(s,0,n-1,dp);
    }
};