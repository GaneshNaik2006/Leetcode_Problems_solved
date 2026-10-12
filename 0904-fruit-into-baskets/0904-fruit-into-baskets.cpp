class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n=nums.size();
        
        unordered_map<int,int> mp;
        int l=0,r=0,maxi=-1;

        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>2){

                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
           
                
            }
            maxi=max(maxi,r-l+1);
            r++;

        }

        return maxi;
    }
};