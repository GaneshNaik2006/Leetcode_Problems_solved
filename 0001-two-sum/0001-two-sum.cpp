class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(m.find(target-nums[i])==m.end()){
                m[nums[i]]=i;

            }else{
                ans.push_back(i);
                ans.push_back(m[target-nums[i]]);
                return ans;
            }
        }
        return {-1,-1};
    }
};