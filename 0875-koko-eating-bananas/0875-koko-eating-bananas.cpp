class Solution {
public:
    bool isvalid(vector<int>& nums,int h,int mid,int n){
        int count=0;
        if(mid<=0) return false;
            for(int i=0;i<n;i++){
            count+=(nums[i]+mid-1)/mid;
        
        }
        
        return count<=h;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        int n=nums.size();

        int st=0;
        int end=0;
        
        for(int i=0;i<n;i++){
            end=max(end,nums[i]);
        }
        
        int ans=0;
        while(st<=end){
            int mid=st+(end-st)/2;

            if(isvalid(nums,h,mid,n)) {
                cout<<mid<<endl;
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }

        return ans;
    }
};