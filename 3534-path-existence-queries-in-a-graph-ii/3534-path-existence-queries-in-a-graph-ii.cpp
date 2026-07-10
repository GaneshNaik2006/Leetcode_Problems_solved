

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<pair<int,int>> a;
        for(int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        vector<int> pos(n);
        for(int i = 0; i < n; i++)
            pos[a[i].second] = i;

        // Component IDs
        vector<int> comp(n);
        int cid = 0;
        comp[0] = 0;
        for(int i = 1; i < n; i++){
            if(a[i].first - a[i-1].first > maxDiff)
                cid++;
            comp[i] = cid;
        }

        // far[i] = farthest index reachable in one edge
        vector<int> far(n);
        int r = 0;
        for(int i = 0; i < n; i++){
            while(r + 1 < n &&
                  comp[r + 1] == comp[i] &&
                  a[r + 1].first - a[i].first <= maxDiff)
                r++;
            far[i] = r;
        }

        const int LOG = 18;

        vector<vector<int>> up(LOG, vector<int>(n));

        for(int i = 0; i < n; i++)
            up[0][i] = far[i];

        for(int k = 1; k < LOG; k++){
            for(int i = 0; i < n; i++)
                up[k][i] = up[k-1][ up[k-1][i] ];
        }

        vector<int> ans;

        for(auto &q : queries){

            int u = pos[q[0]];
            int v = pos[q[1]];

            if(u == v){
                ans.push_back(0);
                continue;
            }

            if(comp[u] != comp[v]){
                ans.push_back(-1);
                continue;
            }

            if(u > v) swap(u, v);

            int cur = u;
            int steps = 0;

            for(int k = LOG - 1; k >= 0; k--){
                if(up[k][cur] < v){
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }

            ans.push_back(steps + 1);
        }

        return ans;
    }
};