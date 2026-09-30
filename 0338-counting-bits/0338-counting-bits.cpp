class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);

        for(int i=0;i<=n;i++){

            int x=i;
            int cnt=0;
            while(x!=0){
                if(x&1) cnt++;
                x=x/2;
            }
            ans[i]=cnt;
        }

        return ans;
    }
};