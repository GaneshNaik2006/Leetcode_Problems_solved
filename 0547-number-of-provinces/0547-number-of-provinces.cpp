class Solution {
public:
    vector<vector<int>> g;
    void dfs(int src,vector<bool>& vis){
        vis[src]=true;
        for(int j:g[src]){
            if(!vis[j]) {
                vis[j]=true;
                dfs(j,vis);
            }
        }
    }
    void addedge(int u,int v){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int findCircleNum(vector<vector<int>>& nums) {
        int n=nums.size();
        int count=0;
        g.resize(n); 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[i][j]){
                    addedge(i,j);
                }
            }
        }
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis);
                count++;
            }
        }
        return count;
    }
};