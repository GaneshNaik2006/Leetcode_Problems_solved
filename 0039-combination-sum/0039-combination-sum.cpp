class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>& candidates,int target,int i,int n,int sum,vector<int>& arr){
        if(sum==target){
            ans.push_back(arr);
            return;
        }
        if(i==n || sum>target ){
          
            return;
        }
        
        arr.push_back(candidates[i]);
        f(candidates,target,i,n,sum+candidates[i],arr);
        arr.pop_back();
        f(candidates,target,i+1,n,sum,arr);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> arr;
        f(candidates,target,0,n,0,arr);

        return ans;
    }
};