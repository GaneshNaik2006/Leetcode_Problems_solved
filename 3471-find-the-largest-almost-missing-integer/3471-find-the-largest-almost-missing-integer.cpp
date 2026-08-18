class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++) mp[nums[i]]++;

        if(k==1){
            int maxi=-1;
            for(auto it:mp){
                if(it.second==1) {
                    maxi=max(maxi,it.first);
                }
            }
            return maxi;
        }
        if(k==n){
            return *max_element(nums.begin(),nums.end());
        }

        if(mp[nums[0]]==1 && mp[nums[n-1]]==1){
            return max(nums[0],nums[n-1]);
        }else if( mp[nums[n-1]]==1) return nums[n-1];
        else if(mp[nums[0]]==1) return nums[0];

        return -1;
    }
};