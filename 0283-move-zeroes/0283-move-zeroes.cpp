class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();

        for(int i=0;i<n;i++) if(nums[i]==0) cnt++;

        while(cnt--){
            for(int i=0;i<n-1;i++){
                if(nums[i]==0){
                    swap(nums[i],nums[i+1]);
                }
            }
        }
    }
};