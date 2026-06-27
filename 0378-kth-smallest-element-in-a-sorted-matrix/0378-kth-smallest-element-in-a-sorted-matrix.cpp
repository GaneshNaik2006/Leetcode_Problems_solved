class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        priority_queue<int,vector<int> ,greater<int>> pq;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pq.push(mat[i][j]);
            }
        }

        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
        
    }
};