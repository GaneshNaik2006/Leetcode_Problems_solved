class Solution {
public:
    static const long long MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (!A[i][k]) continue;

                long long aik = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (!B[k][j]) continue;

                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (exp) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        int S = 2 * m;

        vector<long long> dp(S, 0);

        // Length = 2
        for (int v = 1; v <= m; v++) {
            dp[v - 1] = v - 1;       // Up(v)
            dp[m + v - 1] = m - v;   // Down(v)
        }

        if (n == 2) {
            long long ans = 0;
            for (auto x : dp) ans = (ans + x) % MOD;
            return ans;
        }

        Matrix T(S, vector<long long>(S, 0));

        // Up(v) <- Down(u), u < v
        for (int v = 1; v <= m; v++) {
            int row = v - 1;

            for (int u = 1; u < v; u++) {
                int col = m + (u - 1);
                T[row][col] = 1;
            }
        }

        // Down(v) <- Up(u), u > v
        for (int v = 1; v <= m; v++) {
            int row = m + (v - 1);

            for (int u = v + 1; u <= m; u++) {
                int col = u - 1;
                T[row][col] = 1;
            }
        }

        Matrix P = power(T, n - 2);

        vector<long long> finalState(S, 0);

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                finalState[i] =
                    (finalState[i] + P[i][j] * dp[j]) % MOD;
            }
        }

        long long ans = 0;
        for (long long x : finalState) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};