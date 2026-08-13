class Solution {
public:

    struct Node {
        char left, right;
        int pref, suff, best, len;

        Node() {
            left = right = '#';
            pref = suff = best = len = 0;
        }

        Node(char c) {
            left = right = c;
            pref = suff = best = len = 1;
        }
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.left = a.left;
        res.right = b.right;

        // Prefix
        res.pref = a.pref;
        if (a.pref == a.len && a.right == b.left) {
            res.pref = a.len + b.pref;
        }

        // Suffix
        res.suff = b.suff;
        if (b.suff == b.len && a.right == b.left) {
            res.suff = b.len + a.suff;
        }

        // Best answer
        res.best = max(a.best, b.best);

        // Substring crossing the middle
        if (a.right == b.left) {
            res.best = max(res.best, a.suff + b.pref);
        }

        return res;
    }

    void build(int idx, int l, int r, string &s) {
        if (l == r) {
            seg[idx] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid, s);
        build(2 * idx + 1, mid + 1, r, s);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char c) {
        if (l == r) {
            seg[idx] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * idx, l, mid, pos, c);
        else
            update(2 * idx + 1, mid + 1, r, pos, c);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    vector<int> longestRepeating(string s,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.length();
        int k = queryCharacters.length();

        seg.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < k; i++) {

            int pos = queryIndices[i];
            char c = queryCharacters[i];

            // Update string
            s[pos] = c;

            // Update segment tree
            update(1, 0, n - 1, pos, c);

            // Root contains answer for whole string
            ans.push_back(seg[1].best);
        }

        return ans;
    }
};