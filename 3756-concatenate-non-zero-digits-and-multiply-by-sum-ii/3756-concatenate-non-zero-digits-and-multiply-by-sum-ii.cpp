class Solution {
public:
 const int mod = 1000000007;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
       int n=s.size();
       vector<int> presum(n+1,0);
       vector<int> num(n+1,0);
       vector<int> count(n+1,0);

       for(int i=0;i<n;i++){
            int d=s[i]-'0';
            presum[i+1]=presum[i]+d;
            if(d!=0)
            num[i+1]=((1LL*num[i]*10)%mod +d)%mod;
            else num[i+1]=num[i];
            if(d!=0)
            count[i+1]=count[i]+1;
            else count[i+1]=count[i];
       }
       int mx=0;
       int k=count.size();
       for(int i=0;i<k;i++){
        mx=max(mx,count[i]);
       }
       vector<long long> pow10(mx+1,1);
       for(int i=1;i<=mx;i++){
        pow10[i]=(1LL*pow10[i-1]*10)%mod;
       }
        int m=queries.size();
        vector<int> ans;
       for(int i=0;i<m;i++){
           int l=queries[i][0];
           int r=queries[i][1];

           long long sum=presum[r+1]-presum[l];
           long long nums =
                (num[r+1] - (1LL * num[l] * pow10[count[r+1]-count[l]]) % mod + mod) % mod;
           ans.push_back((1LL*sum*nums)%mod);
           
       }
       return ans;
    }
};