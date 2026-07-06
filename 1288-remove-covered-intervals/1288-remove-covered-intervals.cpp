class Solution {
public:

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
         sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        for(int i=1;i<n;i++){
            if(!ans.empty() && ans.back()[0] <= intervals[i][0]&&  intervals[i][1] <=  ans.back()[1]) {
                continue;
            }
            ans.push_back(intervals[i]);
        }
        return ans.size();
    }
};