class Solution {
public:
    int minimumDeletions(vector<int>& arr) {
        int n=arr.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int minidx=-1;
        int maxidx=-1;

        for(int i=0;i<n;i++){
            if(arr[i]<mini) {
                mini=arr[i];
                minidx=i;
            } 
            if(arr[i]>maxi){
                maxi=arr[i];
                maxidx=i;
            }
        }

       int front =max(minidx,maxidx)+1;
       int back=max(n-1-minidx,n-1-maxidx)+1;
       int both=min(minidx,n-1-minidx)+min(n-1-maxidx,maxidx)+2;

       return min({front,back,both});
    }
};