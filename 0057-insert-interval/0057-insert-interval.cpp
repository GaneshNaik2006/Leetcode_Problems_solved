class Solution {
public:
vector<vector<int>> overlap(vector<vector<int>>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;

    ans.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (ans.back()[1] >= nums[i][0]) {
            ans.back()[1] = max(ans.back()[1], nums[i][1]);
        } else {
            ans.push_back(nums[i]);
        }
    }

    return ans;
}
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       

       
            intervals.push_back(newInterval);
        
        sort(intervals.begin(),intervals.end());
        return overlap(intervals);
    }
};