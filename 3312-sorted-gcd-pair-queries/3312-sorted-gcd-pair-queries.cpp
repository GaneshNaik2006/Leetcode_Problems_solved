class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        // divCnt[g] = numbers divisible by g
        vector<long long> divCnt(mx + 1, 0);

        for (int g = 1; g <= mx; g++) {
            for (int j = g; j <= mx; j += g)
                divCnt[g] += freq[j];
        }

        // exact[g] = pairs having gcd exactly g
        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            long long c = divCnt[g];
            exact[g] = c * (c - 1) / 2;

            for (int j = 2 * g; j <= mx; j += g)
                exact[g] -= exact[j];
        }

        vector<long long> pref;
        vector<int> values;

        long long sum = 0;
        for (int g = 1; g <= mx; g++) {
            if (exact[g] > 0) {
                sum += exact[g];
                pref.push_back(sum);
                values.push_back(g);
            }
        }

        vector<int> ans;

        for (long long q : queries) {
            int idx = lower_bound(pref.begin(), pref.end(), q + 1) - pref.begin();
            ans.push_back(values[idx]);
        }

        return ans;
    }
};