class Solution {
public:

    void generate(vector<int>& arr, int idx, int cnt,
                  long long sum,
                  vector<vector<long long>>& v) {

        if (idx == arr.size()) {
            v[cnt].push_back(sum);
            return;
        }

        // Don't take current element
        generate(arr, idx + 1, cnt, sum, v);

        // Take current element
        generate(arr, idx + 1, cnt + 1,
                 sum + arr[idx], v);
    }

    int minimumDifference(vector<int>& nums) {

        int m = nums.size();
        int n = m / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        vector<vector<long long>> L(n + 1);
        vector<vector<long long>> R(n + 1);

        generate(left, 0, 0, 0, L);
        generate(right, 0, 0, 0, R);

        for (int i = 0; i <= n; i++) {
            sort(R[i].begin(), R[i].end());
        }

        long long total = 0;

        for (int x : nums) {
            total += x;
        }

        long long ans = LLONG_MAX;

        for (int cnt = 0; cnt <= n; cnt++) {

            int need = n - cnt;

            for (long long x : L[cnt]) {

                // We want:
                // x + y close to total / 2
                //
                // 2 * (x + y) close to total
                //
                // y close to (total - 2*x) / 2

                long long target = total - 2 * x;

                auto it = lower_bound(
                    R[need].begin(),
                    R[need].end(),
                    target / 2
                );

                // Check current element
                if (it != R[need].end()) {

                    long long y = *it;

                    long long diff =
                        llabs(2 * (x + y) - total);

                    ans = min(ans, diff);
                }

                // Check previous element
                if (it != R[need].begin()) {

                    --it;

                    long long y = *it;

                    long long diff =
                        llabs(2 * (x + y) - total);

                    ans = min(ans, diff);
                }
            }
        }

        return (int)ans;
    }
};