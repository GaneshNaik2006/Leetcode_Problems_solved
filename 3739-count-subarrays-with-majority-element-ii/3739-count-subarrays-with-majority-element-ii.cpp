class Solution {
public:
    long long merge(vector<int>& nums,int low ,int mid,int high){
        int left=low;
        int right=mid+1;
        long long cnt=0;
        vector<int> temp;
        while(left<=mid && right<=high){
            if(nums[left] <nums[right]){
                cnt+=(high-right+1);
                temp.push_back(nums[left]);
                left++;
            } else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
             temp.push_back(nums[right]);
             right++;
        }
        int k=temp.size();
        for(int i=0;i<k;i++){
            nums[low+i]=temp[i];
        }
        return cnt;
    }
    long long mergeSort(vector<int>& nums,int low,int high){
        if(low>=high) return 0;
        int mid=low+(high-low)/2;
        long long cnt=0;
       cnt=cnt+ mergeSort(nums,low,mid);
       cnt= cnt+ mergeSort(nums,mid+1,high);
       cnt=cnt+ merge(nums,low,mid,high);

          return cnt;  
    }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target) nums[i]=1;
            else nums[i]=-1;
        }
        vector<int> ps(n+1);
        
        ps[0]=0;
        for(int i=0;i<n;i++){
            ps[i+1]=nums[i]+ps[i];
        }

       return mergeSort(ps,0,n);
    }
};