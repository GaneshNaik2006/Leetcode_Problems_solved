class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n=s.length();

        vector<int> ans(n,0);
        int d=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                d++;
                ans[i]=d%2;
            }else if(s[i]==')'){
                ans[i]=d%2;
                d--;
            }
        }

        return ans;
    }
};