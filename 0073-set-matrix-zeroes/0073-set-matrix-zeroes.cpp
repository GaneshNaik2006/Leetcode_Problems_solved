class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();

        vector<pair<int,int>> v;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){
                if(nums[i][j]==0) v.push_back({i,j});
            }
        }

        int k=v.size();

        for(int i=0;i<k;i++){

            int r=v[i].first;
            int c=v[i].second;

            for(int x=0;x<m;x++){
                nums[r][x]=0;
            }

            for(int x=0;x<n;x++){
                nums[x][c]=0;
            }
        }

        

    }
};