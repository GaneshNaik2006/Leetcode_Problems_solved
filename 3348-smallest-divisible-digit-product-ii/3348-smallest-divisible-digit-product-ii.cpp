class Solution {
public:

    string smallestNumber(string num, long long t) {

        // ---------------------------------------------------------
        // STEP 1: Factorize t
        // ---------------------------------------------------------

        int need2 = 0;
        int need3 = 0;
        int need5 = 0;
        int need7 = 0;

        while (t % 2 == 0) {
            need2++;
            t /= 2;
        }

        while (t % 3 == 0) {
            need3++;
            t /= 3;
        }

        while (t % 5 == 0) {
            need5++;
            t /= 5;
        }

        while (t % 7 == 0) {
            need7++;
            t /= 7;
        }

        // Digits 1..9 cannot create any other prime factor.
        if (t != 1)
            return "-1";


        // ---------------------------------------------------------
        // STEP 2: Prime-factor contribution of every digit
        //
        // digit : 2 3 5 7
        //
        // 1 -> 0 0 0 0
        // 2 -> 1 0 0 0
        // 3 -> 0 1 0 0
        // 4 -> 2 0 0 0
        // 5 -> 0 0 1 0
        // 6 -> 1 1 0 0
        // 7 -> 0 0 0 1
        // 8 -> 3 0 0 0
        // 9 -> 0 2 0 0
        // ---------------------------------------------------------

        int f2[10] = {
            0, 0, 1, 0, 2, 0, 1, 0, 3, 0
        };

        int f3[10] = {
            0, 0, 0, 1, 0, 0, 1, 0, 0, 2
        };

        int f5[10] = {
            0, 0, 0, 0, 0, 1, 0, 0, 0, 0
        };

        int f7[10] = {
            0, 0, 0, 0, 0, 0, 0, 1, 0, 0
        };


        // ---------------------------------------------------------
        // STEP 3: DP
        //
        // dp[a][b][c][d] =
        // minimum number of digits required to get AT LEAST
        //
        // 2^a * 3^b * 5^c * 7^d
        // ---------------------------------------------------------

        const int INF = 1e9;

        int B = need3 + 1;
        int C = need5 + 1;
        int D = need7 + 1;

        auto ID = [&](int a, int b, int c, int d) {
            return (((a * B + b) * C + c) * D + d);
        };

        int totalStates =
            (need2 + 1) *
            (need3 + 1) *
            (need5 + 1) *
            (need7 + 1);

        vector<int> dp(totalStates, INF);

        dp[ID(0, 0, 0, 0)] = 0;


        // ---------------------------------------------------------
        // Bottom-up DP
        //
        // Every transition decreases at least one requirement,
        // so all required states have already been computed.
        // ---------------------------------------------------------

        for (int a = 0; a <= need2; a++) {

            for (int b = 0; b <= need3; b++) {

                for (int c = 0; c <= need5; c++) {

                    for (int d = 0; d <= need7; d++) {

                        if (a == 0 && b == 0 &&
                            c == 0 && d == 0)
                            continue;

                        int cur = ID(a, b, c, d);

                        for (int digit = 2; digit <= 9; digit++) {

                            int na = max(0, a - f2[digit]);
                            int nb = max(0, b - f3[digit]);
                            int nc = max(0, c - f5[digit]);
                            int nd = max(0, d - f7[digit]);

                            // Digit must actually contribute something.
                            if (na == a &&
                                nb == b &&
                                nc == c &&
                                nd == d) {
                                continue;
                            }

                            int previous =
                                ID(na, nb, nc, nd);

                            if (dp[previous] != INF) {
                                dp[cur] = min(
                                    dp[cur],
                                    dp[previous] + 1
                                );
                            }
                        }
                    }
                }
            }
        }


        // Minimum number of useful digits required overall.
        int minDigits =
            dp[ID(need2, need3, need5, need7)];

        if (minDigits == INF)
            return "-1";


        // ---------------------------------------------------------
        // Helper:
        // Can the remaining 'slots' satisfy the requirement?
        // ---------------------------------------------------------

        auto possible = [&](int a, int b, int c, int d,
                            int slots) -> bool {

            return dp[ID(a, b, c, d)] <= slots;
        };


        // ---------------------------------------------------------
        // STEP 4:
        // Check whether num itself is already valid.
        // ---------------------------------------------------------

        bool zeroFree = true;

        int a = need2;
        int b = need3;
        int c = need5;
        int d = need7;

        for (char ch : num) {

            int digit = ch - '0';

            if (digit == 0) {
                zeroFree = false;
                break;
            }

            a = max(0, a - f2[digit]);
            b = max(0, b - f3[digit]);
            c = max(0, c - f5[digit]);
            d = max(0, d - f7[digit]);
        }

        if (zeroFree &&
            a == 0 &&
            b == 0 &&
            c == 0 &&
            d == 0) {

            return num;
        }


        // ---------------------------------------------------------
        // STEP 5:
        // Try to find the smallest valid number of SAME length.
        //
        // We choose a position where we make the number larger.
        //
        // We try positions from RIGHT -> LEFT.
        //
        // Example:
        //
        // num = 19
        //
        // Try changing position 1:
        // 9 -> no larger digit can provide factor 2.
        //
        // Then change position 0:
        // 1 -> 2
        //
        // suffix -> smallest possible = 1
        //
        // answer = 21
        // ---------------------------------------------------------

        int n = (int)num.size();

        // prefix[i] = remaining factor requirement
        // after processing num[0 ... i-1]
        vector<array<int, 4>> prefix(n + 1);

        prefix[0] = {
            need2,
            need3,
            need5,
            need7
        };

        for (int i = 0; i < n; i++) {

            int digit = num[i] - '0';

            prefix[i + 1] = {
                max(0, prefix[i][0] - f2[digit]),
                max(0, prefix[i][1] - f3[digit]),
                max(0, prefix[i][2] - f5[digit]),
                max(0, prefix[i][3] - f7[digit])
            };
        }


        // ---------------------------------------------------------
        // If num contains zero:
        //
        // We cannot keep a prefix containing that zero.
        //
        // Therefore the pivot must be at or BEFORE the first zero.
        // ---------------------------------------------------------

        int firstZero = n;

        for (int i = 0; i < n; i++) {

            if (num[i] == '0') {
                firstZero = i;
                break;
            }
        }


        // ---------------------------------------------------------
        // Try every possible pivot.
        // Rightmost pivot gives the smallest number.
        // ---------------------------------------------------------

        for (int pos = n - 1;
             pos >= 0;
             pos--) {

            // Prefix before pivot must be zero-free.
            if (pos > firstZero)
                continue;

            int original = num[pos] - '0';

            int pa = prefix[pos][0];
            int pb = prefix[pos][1];
            int pc = prefix[pos][2];
            int pd = prefix[pos][3];


            // Increase this digit by the smallest possible amount.
            for (int digit = original + 1;
                 digit <= 9;
                 digit++) {

                int na = max(0, pa - f2[digit]);
                int nb = max(0, pb - f3[digit]);
                int nc = max(0, pc - f5[digit]);
                int nd = max(0, pd - f7[digit]);

                int remaining = n - pos - 1;

                // Can suffix satisfy the remaining factors?
                if (!possible(na, nb, nc, nd, remaining))
                    continue;


                // -------------------------------------------------
                // We found the pivot.
                // Prefix remains exactly the same.
                // -------------------------------------------------

                string ans = num.substr(0, pos);

                ans.push_back(char('0' + digit));


                // -------------------------------------------------
                // Build the smallest possible suffix.
                // -------------------------------------------------

                for (int j = pos + 1;
                     j < n;
                     j++) {

                    for (int x = 1; x <= 9; x++) {

                        int xa =
                            max(0, na - f2[x]);

                        int xb =
                            max(0, nb - f3[x]);

                        int xc =
                            max(0, nc - f5[x]);

                        int xd =
                            max(0, nd - f7[x]);

                        int left = n - j - 1;

                        if (possible(xa, xb, xc, xd, left)) {

                            ans.push_back(char('0' + x));

                            na = xa;
                            nb = xb;
                            nc = xc;
                            nd = xd;

                            break;
                        }
                    }
                }

                return ans;
            }
        }


        // ---------------------------------------------------------
        // STEP 6:
        // Same length is impossible.
        //
        // Therefore we need a LONGER number.
        //
        // IMPORTANT:
        //
        // It is NOT necessarily n + 1.
        //
        // Example:
        //
        // num = "12"
        // t = 1968750
        //
        // Minimum useful digits = 9.
        //
        // Therefore answer length must be 9.
        // ---------------------------------------------------------

        int len = max(n + 1, minDigits);

        string ans;

        a = need2;
        b = need3;
        c = need5;
        d = need7;


        // ---------------------------------------------------------
        // Construct smallest zero-free number of length 'len'.
        // ---------------------------------------------------------

        for (int pos = 0;
             pos < len;
             pos++) {

            for (int digit = 1;
                 digit <= 9;
                 digit++) {

                int na =
                    max(0, a - f2[digit]);

                int nb =
                    max(0, b - f3[digit]);

                int nc =
                    max(0, c - f5[digit]);

                int nd =
                    max(0, d - f7[digit]);

                int remaining =
                    len - pos - 1;

                if (!possible(na, nb, nc, nd, remaining))
                    continue;


                ans.push_back(char('0' + digit));

                a = na;
                b = nb;
                c = nc;
                d = nd;

                break;
            }
        }

        return ans;
    }
};