class Solution {
public:
    bool f(vector<vector<char>>& nums,string& word,int i,int j,int idx,int n,int m,int k,vector<vector<bool>>& vis){
        if(idx==k) return true;
        if(i<0 || j<0 || i>=n || j>=m || idx>=k || vis[i][j] || nums[i][j]!=word[idx] ) return false;
        vis[i][j]=true;
        if(f(nums,word,i-1,j,idx+1,n,m,k,vis)) return true;
         if(f(nums,word,i+1,j,idx+1,n,m,k,vis)) return true;
          if(f(nums,word,i,j+1,idx+1,n,m,k,vis)) return true;
           if(f(nums,word,i,j-1,idx+1,n,m,k,vis)) return true;
            vis[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int k=word.size();
       
        for(int i=0;i<n;i++){    
            for(int j=0;j<m;j++){
                vector<vector<bool>> vis(n,vector<bool> (m,false));
                if(f(board,word,i,j,0,n,m,k,vis)) return true;
            }
        }

        return false;
    }
};