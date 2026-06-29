class Solution {
public:
    int numOfStrings(vector<string>& nums, string word) {
        int n=nums.size();
       
       

        int count=0;
        for(int i=0;i<n;i++){
            if(word.find(nums[i])!=string::npos) count++;
        }
        return count;
    }
};