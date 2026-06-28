class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int> pq;
        long long sum=0;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            sum+=nums[i];
        }

        int mx,rs,el;

        while(pq.top()!=1){
            mx=pq.top();
            pq.pop();
            rs=sum-mx;
            if(rs<=0 || rs>=mx) return 0;
            int prev = mx % rs;

    if (prev == 0 && rs != 1)
        return false;

    sum = rs + (prev == 0 ? rs : prev);
    pq.push(prev == 0 ? rs : prev);
        }

        return 1;
    }
};