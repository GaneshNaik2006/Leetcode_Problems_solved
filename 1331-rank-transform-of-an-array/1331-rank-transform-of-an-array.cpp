class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mp;
        
                int n=arr.size();
                if(n==0) return {};
        vector<int> nums(arr);
        sort(nums.begin(),nums.end());
        int cnt=1;
        
        mp[nums[0]]=1;
        for(int i=1;i<n;i++){
             if(nums[i-1] !=nums[i])
            cnt++;
            mp[nums[i]]=cnt;
        }

        for(int i=0;i<n;i++){
           nums[i]= mp[arr[i]];
        }
        return nums;
    }
};