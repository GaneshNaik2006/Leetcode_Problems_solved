class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;

        return gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int mn=INT_MAX;
        int mx=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mn=min(nums[i],mn);
            mx=max(nums[i],mx);
        }

        return gcd(mn,mx);
    }
};