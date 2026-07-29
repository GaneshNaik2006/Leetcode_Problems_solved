class Solution {
public:
    bool iscycle(int src,vector<vector<int>>& nums,vector<bool>& vis,vector<bool>& recvis){
        vis[src]=true;
        recvis[src]=true;

        for(int i=0;i<nums.size();i++){
            int v=nums[i][0];
            int u=nums[i][1];

           if(u==src){
            if(!vis[v]){
                if(iscycle(v,nums,vis,recvis)) return true;
            }else if(recvis[v]){
                return true;
            }
           }
          
        }
         recvis[src]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& nums) {
        vector<bool> vis(n,false);
        vector<bool> recvis(n,false);

        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(iscycle(i,nums,vis,recvis)) return false;
            }
        }
        return true;
    }
};