class Solution {
public:
    int stone(vector<int>& piles,int i,int j,vector<vector<int>>& dp){
       if(i==j) return piles[i];
    if(dp[i][j]!=INT_MIN) return dp[i][j];
       int left=piles[i]-stone(piles,i+1,j,dp);
       int right=piles[j]-stone(piles,i,j-1,dp);

       return dp[i][j]=max(left,right);



        
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
      vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        return stone(piles,0,n-1,dp)>0;
    }
};