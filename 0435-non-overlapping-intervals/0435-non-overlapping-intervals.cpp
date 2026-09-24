class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();

        sort(intervals.begin(),intervals.end(),[](vector<int>& a ,vector<int>& b){
            return a[1]<b[1];
        });

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(ans.back()[1]>intervals[i][0]){
                
            }else{
                ans.push_back(intervals[i]);
            }

        }

        int m=ans.size();

        return n-m;
    }
};