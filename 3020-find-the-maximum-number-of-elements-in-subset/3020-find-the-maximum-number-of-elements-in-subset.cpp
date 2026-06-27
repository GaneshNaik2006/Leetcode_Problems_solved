class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        int count = 1;
        int maxcount = 1;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            if (nums[i] == 1) {
                int cnt = mp[1];
                if (cnt % 2 == 0)
                    cnt--;
                maxcount = max(maxcount, cnt);
                continue;
            }
            count = 1;

            if (mp[nums[i]] >= 2) {
                long long x = 1LL * nums[i] * nums[i];
                while (mp.find(x) != mp.end()) {
                    count++;
                    if (mp[x] < 2)
                        break;
                    if (x > 1000000000LL)
                        break;
                    x = x * x;
                }
            }
            maxcount = max(maxcount, 2 * count - 1);
        }

        return maxcount;
    }
};