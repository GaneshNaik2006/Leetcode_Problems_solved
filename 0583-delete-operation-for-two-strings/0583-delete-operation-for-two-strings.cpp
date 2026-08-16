class Solution {
public:
    int f(string& s1,string& s2,int i,int j, vector<vector<int>>& dp){
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i-1]==s2[j-1]){
            return dp[i][j]=1+f(s1,s2,i-1,j-1,dp);
        }
        return dp[i][j]=max(f(s1,s2,i-1,j,dp),f(s1,s2,i,j-1,dp));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int x=f(word1,word2,n,m,dp);

        
        return n+m -2*x;
    }
};