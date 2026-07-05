class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        dp[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X') continue;
                if (i == n - 1 && j == n - 1) continue;

                int best = -1;
                long long cnt = 0;

                vector<pair<int,int>> dir = {{1,0},{0,1},{1,1}};

                for (auto [dx, dy] : dir) {
                    int ni = i + dx;
                    int nj = j + dy;

                    if (ni >= n || nj >= n) continue;
                    if (dp[ni][nj] == -1) continue;

                    if (dp[ni][nj] > best) {
                        best = dp[ni][nj];
                        cnt = ways[ni][nj];
                    } else if (dp[ni][nj] == best) {
                        cnt = (cnt + ways[ni][nj]) % MOD;
                    }
                }

                if (best == -1) continue;

                dp[i][j] = best;
                ways[i][j] = cnt;

                if (board[i][j] != 'E')
                    dp[i][j] += board[i][j] - '0';
            }
        }

        if (ways[0][0] == 0)
            return {0, 0};

        return {dp[0][0], ways[0][0]};
    }
};