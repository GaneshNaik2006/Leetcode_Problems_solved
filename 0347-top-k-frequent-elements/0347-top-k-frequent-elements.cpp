class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;

        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<int> ans;

        while(!pq.empty() && k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};