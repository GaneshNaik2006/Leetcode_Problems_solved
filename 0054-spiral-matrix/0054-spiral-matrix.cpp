class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int minr=0,minc=0,maxr=n-1,maxc=m-1;

        int count=0;
        vector<int> ans;
        while(count<n*m){

            
            //left->right
            for(int i=minc;i<=maxc && count<n*m;i++){
                ans.push_back(mat[minr][i]);
                count++;
            }
            minr++;
            //right top->right bottom

            for(int i=minr;i<=maxr && count<n*m;i++){
                ans.push_back(mat[i][maxc]);
                count++;
            }
            maxc--;

            //bottom right ->bottom left

            for(int i=maxc;i>=minc&& count<n*m;i--){
                ans.push_back(mat[maxr][i]);
                count++;
            }
            maxr--;

            //left bottom ->top left

            for(int i=maxr;i>=minr && count<n*m;i--){
                ans.push_back(mat[i][minc]);
                count++;
            }
            minc++;
        }

        return ans;

    }
};