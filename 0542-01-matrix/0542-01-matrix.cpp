class Solution {
public:
   void dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int n,int m,vector<vector<int>>& ans,queue<pair<pair<int,int>,int>>& q){

    

    while(!q.empty()){
         int x=q.front().first.first;
            int y=q.front().first.second;
            int z=q.front().second;

            q.pop();
            if(x+1 < n && !vis[x+1][y] && grid[x+1][y]==1 ){
                vis[x+1][y]=true;
                q.push({{x+1,y},z+1});
                ans[x+1][y]=z+1;
            }
             if(y+1 <m && !vis[x][y+1] && grid[x][y+1]==1 ){
                vis[x][y+1]=true;
                
                q.push({{x,y+1},z+1});
               ans[x][y+1]=z+1;
            }
             if(y-1 >=0 && !vis[x][y-1] && grid[x][y-1]==1 ){
                vis[x][y-1]=true;
                
                q.push({{x,y-1},z+1});
                ans[x][y-1]=z+1;
            }
             if(x-1 >=0 && !vis[x-1][y] && grid[x-1][y]==1 ){
                vis[x-1][y]=true;
                
                q.push({{x-1,y},z+1});
                ans[x-1][y]=z+1;
            }
    }

       
       
   }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<bool>> vis(n,vector<bool> (m,false));
         vector<vector<int>> ans(n,vector<int>(m,0));
         queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]==0){
                   q.push({{i,j},0});
                   vis[i][j]=true;
                }
            }
        }
        
        dfs(mat,vis,n,m,ans,q);

        return ans;
    }
};