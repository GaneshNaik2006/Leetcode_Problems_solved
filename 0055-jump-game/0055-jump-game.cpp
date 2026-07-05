class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> index;

        for(int i=0;i<n;i++){
            if(nums[i]==0) index.push_back(i);
        }
        
        int m=index.size();
        if(m==0) return true;
        if(m==1 && index[0]==n-1)  return true;
      
        for(int i=0;i<m;i++){
            int x=index[i];
            if(x==n-1) continue;
            bool is=false;
            for(int j=x-1;j>=0;j--){
                if(j+nums[j]>x){
                    
                    is=true;
                    break;
                }
            }
            if(!is) return false;
        }

        return true;
    }
};