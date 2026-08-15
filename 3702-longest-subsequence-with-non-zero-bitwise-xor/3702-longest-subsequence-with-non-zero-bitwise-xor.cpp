class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();

        int iszero=false;
        int xr=0;
        for(int i=0;i<n;i++){
            xr=xr^nums[i];
            if(nums[i]!=0) iszero=true;
        }
        if(xr!=0) return n;
        if(iszero) return n-1;

        return 0;
    }
};