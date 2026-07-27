class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, vector<vector<bool>>& vis, int color,int sp,int n,int m){
        vis[sr][sc]=true;
        image[sr][sc]=color;

        if( sr-1 >=0 && !vis[sr-1][sc] && image[sr-1][sc]==sp){
           
            dfs(image,sr-1,sc,vis,color,sp,n,m);
        }
        if( sc+1 <m && !vis[sr][sc+1] && image[sr][sc+1]==sp){
            
            dfs(image,sr,sc+1,vis,color,sp,n,m);
        }
        if( sc-1 >=0 && !vis[sr][sc-1] && image[sr][sc-1]==sp){
          
            dfs(image,sr,sc-1,vis,color,sp,n,m);
        }
        if( sr+1<n && !vis[sr+1][sc] && image[sr+1][sc]==sp){
            
            dfs(image,sr+1,sc,vis,color,sp,n,m);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        int sp=image[sr][sc];
        dfs(image,sr,sc,vis,color,sp,n,m);

        return image;
    }
};