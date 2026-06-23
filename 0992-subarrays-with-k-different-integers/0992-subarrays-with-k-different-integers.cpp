class Solution {
public:
    int subarray(vector<int>& nums ,int k){
        if(k<0) return 0;
        int n=nums.size();
        int r=0,l=0,sum=0,count=0;
        unordered_map<int,int> mp;
        while(r<n){
            
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans=subarray(nums,k)-subarray(nums,k-1);
        return ans;
    }
};