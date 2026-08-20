class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Mark reserved seats using bits 2 to 9
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            // Only seats 2 to 9 matter
            if (s >= 2 && s <= 9) {
                mp[row] |= (1 << s);
            }
        }

        int ans = (n - mp.size()) * 2;

        // Masks for:
        // 2,3,4,5
        int left = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);

        // 4,5,6,7
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);

        // 6,7,8,9
        int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (auto &[row, mask] : mp) {
            bool l = (mask & left) == 0;
            bool m = (mask & middle) == 0;
            bool r = (mask & right) == 0;

            if (l && r) {
                // Can take both groups: 2-5 and 6-9
                ans += 2;
            }
            else if (l || m || r) {
                // Can take exactly one group
                ans += 1;
            }
        }

        return ans;
    }
};