class Solution {
public:
    int candy(vector<int>& nums) {
        int n=nums.size();
           vector<int> count(n,1);
        for(int i=0;i<n;i++){
            int left=i-1;
            if(left>=0 && nums[left]<nums[i]) {
                count[i]=count[left]+1;
                
            }
        }

         for(int i=n-1;i>=0;i--){
            int right=i+1;
             if(right<n && nums[right]<nums[i]){
                count[i]=max(count[i],count[right]+1);
            }
        }

        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=count[i];
        }

        return sum;
    }
};