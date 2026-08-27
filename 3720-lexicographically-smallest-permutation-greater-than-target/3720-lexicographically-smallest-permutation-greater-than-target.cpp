class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        vector<int> temp = cnt;

        for (int i = 0; i < target.size(); i++) {
            int x = target[i] - 'a';

            if (temp[x] > 0) {
                temp[x]--;
            } else {
                for (int j = x + 1; j < 26; j++) {
                    if (temp[j] > 0) {
                        string ans = target.substr(0, i);
                        ans += char('a' + j);
                        temp[j]--;

                        for (int k = 0; k < 26; k++) {
                            ans += string(temp[k], char('a' + k));
                        }

                        return ans;
                    }
                }
                break;
            }
        }

        for (int i = target.size() - 1; i >= 0; i--) {
            int x = target[i] - 'a';

            temp = cnt;

            bool possible = true;

            for (int j = 0; j < i; j++) {
                int c = target[j] - 'a';

                if (temp[c] == 0) {
                    possible = false;
                    break;
                }

                temp[c]--;
            }

            if (!possible)
                continue;

            for (int j = x + 1; j < 26; j++) {
                if (temp[j] > 0) {
                    string ans = target.substr(0, i);
                    ans += char('a' + j);
                    temp[j]--;

                    for (int k = 0; k < 26; k++)
                        ans += string(temp[k], char('a' + k));

                    return ans;
                }
            }
        }

        return "";
    }
};