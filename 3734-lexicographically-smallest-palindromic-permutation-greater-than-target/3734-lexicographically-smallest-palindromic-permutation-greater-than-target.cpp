class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0, mid = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = i;
            }
        }

        if (odd > 1)
            return "";

        int m = n / 2;
        vector<int> half(26);

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        auto makePalindrome = [&](string left) {
            string ans = left;

            if (n % 2)
                ans += char('a' + mid);

            string right = left;
            reverse(right.begin(), right.end());
            ans += right;

            return ans;
        };

        string targetLeft = target.substr(0, m);

        for (int pos = m; pos >= 0; pos--) {
            vector<int> rem = half;
            bool possible = true;
            string left;

            for (int i = 0; i < pos; i++) {
                int x = targetLeft[i] - 'a';

                if (x < 0 || x >= 26 || rem[x] == 0) {
                    possible = false;
                    break;
                }

                left += targetLeft[i];
                rem[x]--;
            }

            if (!possible)
                continue;

            if (pos == m) {
                string candidate = makePalindrome(left);

                if (candidate > target)
                    return candidate;

                continue;
            }

            int x = targetLeft[pos] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (rem[c] == 0)
                    continue;

                string newLeft = left;
                newLeft += char('a' + c);
                rem[c]--;

                for (int j = 0; j < 26; j++)
                    newLeft += string(rem[j], char('a' + j));

                return makePalindrome(newLeft);
            }
        }

        return "";
    }
};