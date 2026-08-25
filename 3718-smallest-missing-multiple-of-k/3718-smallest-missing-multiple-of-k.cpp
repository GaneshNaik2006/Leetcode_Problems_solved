class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int> s;

        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int t=k;
        
        while(s.find(t)!=s.end()){
            t=t+k;
        }
        return t;
    }
};