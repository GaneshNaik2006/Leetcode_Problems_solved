class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();

        int cand=nums[0];
        int cnt=1;
        for(int i=1;i<n;i++){
            if(cand==nums[i]) cnt=cnt+1;
            else cnt=cnt-1;
            if(cnt==0) {
                cand=nums[i];
                cnt=1;
            }
        }

        return cand;
    }
};