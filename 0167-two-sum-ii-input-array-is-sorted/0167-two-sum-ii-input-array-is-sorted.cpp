class Solution {
public:
    vector<int> twoSum(vector<int>& ans, int k) {
         int n=ans.size();
        int i=0,j=n-1;

        while(i<j){
            if(ans[i]+ans[j]==k) return {i+1,j+1};
            else if(ans[i]+ans[j]>k) j--;
            else i++;
        }
        return {-1,-1};
    }
};