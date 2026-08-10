class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        // dp[i] = true means the current player can win
        // when there are i stones.

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                int square = j * j;

                // If removing this square leaves a losing
                // position for the opponent, current player wins.
                if (dp[i - square] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};