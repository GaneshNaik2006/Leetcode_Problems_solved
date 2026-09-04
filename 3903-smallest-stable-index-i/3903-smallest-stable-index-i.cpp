class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int n=nums.size();
        vector<int> mins(n,0);
        vector<int> maxs(n,0);

        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            maxs[i]=maxi;
        }

        for(int i=n-1;i>=0 ;i--){
            mini=min(mini,nums[i]);
            mins[i]=mini;
        }

        int minidx=-1;
        mini=INT_MAX;

        for(int i=0;i<n;i++){
            if(maxs[i]-mins[i] <=k && mini >minidx ){
                
                minidx=i;
                mini=minidx;
            }
        }

    return minidx;
    }
};