class Solution {
public:


  
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
   int mx = INT_MIN;
        vector<int> g;
        int x;
        

        for(int i=0;i<n;i++){
              mx=max(mx,nums[i]);
            x=gcd(nums[i],mx);
            g.push_back(x);
        }
        sort(g.begin(),g.end());
        long long sum=0;
        int left,right;
        while(g.size()>1){
            left=g[0];
            right=g[g.size()-1];
            g.pop_back();
            g.erase(g.begin());
            sum+=gcd(left,right);
        }
        return sum;
    }
};