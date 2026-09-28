class Solution {
public:
    void f(vector<vector<char>>& nums,int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || nums[i][j]=='0') return ;

        nums[i][j]='0';

        f(nums,i-1,j,n,m);
         f(nums,i+1,j,n,m);
          f(nums,i,j-1,n,m);
           f(nums,i,j+1,n,m);

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int ans=0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1') {
                    ans++;
                    f(grid,i,j,n,m);
                }
            }
        }
        return ans;
    }
};