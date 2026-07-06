class Solution {
public:
     static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),cmp);
        int cnt=1;
        int lastendtime=nums[0][1];
        for(int i=1;i<n;i++){
            if(nums[i][0]>=lastendtime){
                cnt++;
                lastendtime=nums[i][1];
            }
        }
        return n-cnt;
    }
};