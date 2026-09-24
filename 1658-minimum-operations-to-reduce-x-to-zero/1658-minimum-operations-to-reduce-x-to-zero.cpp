class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();

        int total=0;
        for(int i=0;i<n;i++) total+=nums[i];

        total=total-x;
        if(total<0) return -1;
        if(total==0) return n;

        int sum=0;

        int l=0,r=0;
        int largest=-1;

        while(r<n){
            sum+=nums[r];

            while(l<=r && sum>total){
                sum=sum-nums[l];
                l++;
            }
            if(sum==total)
            largest=max(largest,r-l+1);
            r++;
        }
        if(largest==-1) return -1;
    return n-largest;




    }
};