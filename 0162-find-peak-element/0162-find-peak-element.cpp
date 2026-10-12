class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;

        int st=0,end=n-1;
        if(n==2)  {
            if(nums[1]>nums[0]) return 1;
            else return 0;
        }

        while(st<=end){
            int mid=st+(end-st)/2;
            if(mid+1==n && mid-1==-1 ) return mid;
            if(mid+1<n && mid-1==-1 && nums[mid]>nums[mid+1])  return mid;
            if(mid+1==n && mid-1>=0 && nums[mid]>nums[mid-1])  return mid;
            if(mid+1 <n && mid-1>=0 &&nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) return mid;
            else if(mid+1<n && nums[mid]<nums[mid+1]) st=mid+1;
            else end=mid-1;
        }

        return 0;

    }
};