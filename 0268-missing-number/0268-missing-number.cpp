class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xall=0;

        int xn=0;
        for(int i=0;i<n;i++){
            xn=xn^i;
            xall=xall^nums[i];
        }
        xn=xn^n;
        return xall^xn;
    }
};