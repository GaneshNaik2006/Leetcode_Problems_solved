class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& vis,int n,int m,queue<pair<pair<int,int>,int>>& q){
        
        int time=0,maxtime=0;
        
       
        
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int z=q.front().second;

            q.pop();
            if(x+1 < n && !vis[x+1][y] && grid[x+1][y]==1 ){
                vis[x+1][y]=true;
                grid[x+1][y]=2;
                q.push({{x+1,y},z+1});
                maxtime=max(maxtime,z+1);
            }
             if(y+1 <m && !vis[x][y+1] && grid[x][y+1]==1 ){
                vis[x][y+1]=true;
                 grid[x][y+1]=2;
                q.push({{x,y+1},z+1});
                maxtime=max(maxtime,z+1);
            }
             if(y-1 >=0 && !vis[x][y-1] && grid[x][y-1]==1 ){
                vis[x][y-1]=true;
                 grid[x][y-1]=2;
                q.push({{x,y-1},z+1});
                maxtime=max(maxtime,z+1);
            }
             if(x-1 >=0 && !vis[x-1][y] && grid[x-1][y]==1 ){
                vis[x-1][y]=true;
                 grid[x-1][y]=2;
                q.push({{x-1,y},z+1});
                maxtime=max(maxtime,z+1);
            }
            
        }
        return maxtime;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> vis(n,vector<bool> (m,false)); 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j]==2  ){
                     q.push({{i,j},0});
                }
            }
        }
        int maxtime=helper(grid,0,0,vis,n,m,q);

        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
       return maxtime; 
    }
};