class Solution {
public:
    int minimumPushes(string s) {
        unordered_map<char,int> mp;
        for(char x:s) mp[x]++;
        vector<int> arr;
        for(auto it:mp){
            arr.push_back(it.second);
        }

        sort(arr.rbegin(),arr.rend());
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=arr[i]*(i/8 +1);
        }
        return ans;
    }
};