class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<string> str(strs);
        for(int i=0;i<n;i++){
            sort(str[i].begin(),str[i].end());
        }
        vector<vector<string>> ans;
        vector<bool> v(n,false);
        for(int i=0;i<n;i++){
            vector<string> temp;
            if(!v[i]){
                  temp.push_back(strs[i]);
                  v[i]=true;
            }
          
            for(int j=i+1;j<n;j++){
                if(str[i]==str[j] && !v[j]){
                    temp.push_back(strs[j]);
                    v[j]=true;
                }
            }
          
            if(temp.size()!=0) ans.push_back({temp});
        }

        return ans;
    }
};