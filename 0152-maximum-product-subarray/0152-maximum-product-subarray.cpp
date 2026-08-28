class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int currprod=1;
        int maxprod=INT_MIN;
        int prevprod=1;
        for(int i=0;i<n;i++){ 
            currprod=currprod*nums[i];
            maxprod=max(currprod,maxprod);

            if(currprod==0){
                currprod=1;
            }
        }
            currprod=1;
        for(int i=n-1;i>=0;i--){
            currprod=nums[i]*currprod;
            maxprod=max(currprod,maxprod);
            if(currprod==0){
                currprod=1;
            }
        }
        return maxprod;
    }
};