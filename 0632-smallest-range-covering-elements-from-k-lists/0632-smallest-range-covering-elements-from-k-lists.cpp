class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int mn;
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i][0], {i, 0}});
            mx = max(mx, nums[i][0]);
        }
        mn = pq.top().first;
        vector<int> ans(2);
        ans[0] = mn;
        ans[1] = mx;
        pair<int, pair<int, int>> temp;
        int val, row, col;

        while (pq.size() == n) {
            temp = pq.top();
            pq.pop();

            
            row = temp.second.first;
            col = temp.second.second;

            if (col + 1 < nums[row].size()) {
                col++;
                pq.push({nums[row][col], {row, col}});
                mn = pq.top().first;
                mx = max(mx, nums[row][col]);
                if (mx - mn < ans[1] - ans[0] ||
                    (mx - mn == ans[1] - ans[0] && mn < ans[0])) {
                    ans[0] = mn;
                    ans[1] = mx;
                }
            }
        }
        return ans;
    }
};