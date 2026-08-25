class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
      sort(nums.begin(),nums.end());
       set<vector<int>> ans;
  
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            set<int> s;
            int x=nums[i];
            for(int j=i+1;j<n;j++){
               if(s.find(-(x+nums[j]))!=s.end()){
                vector<int> temp={x,nums[j],-(nums[j]+x)};
           
               

                    ans.insert({x,nums[j],-(x+nums[j])});
                }
                s.insert(nums[j]);   
            }
        }
        vector<vector<int>> result(ans.begin(),ans.end());
        return result ;
        
       

    }
};