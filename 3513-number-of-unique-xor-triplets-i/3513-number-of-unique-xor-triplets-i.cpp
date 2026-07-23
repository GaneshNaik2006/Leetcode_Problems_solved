class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();

        if(n<=2) return n;
        long long ans=1;
        while(ans<=n){
            ans=ans<<1;
        }
        return ans;
    }
};