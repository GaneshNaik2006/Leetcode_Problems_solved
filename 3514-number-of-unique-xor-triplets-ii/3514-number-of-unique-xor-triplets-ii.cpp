class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        vector<bool> pair(2048,false);
        
        if(n==1) return n;
        

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=nums[i]^nums[j];
                pair[x] = true;
            }
        }
        int i=0;
        vector<bool> ans(2048,false);
        for(int x=0;x<2048;x++){
    if(pair[x]){
        for(int v:nums)
            ans[x^v]=true;
    }
}


int cnt=0;
for(bool b:ans)
    cnt+=b;



        return cnt;

       

        
    }
};