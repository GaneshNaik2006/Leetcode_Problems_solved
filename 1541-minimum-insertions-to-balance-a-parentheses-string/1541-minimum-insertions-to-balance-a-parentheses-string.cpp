class Solution {
public:
    int minInsertions(string s) {
        int op=0;
        int ans=0;

        int n=s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='(') op++;
            else {
                if(i+1<n && s[i+1]==')') i++;
                else ans++;

                if(op>0) op--;
                else ans++;
            }
        }

        return 2*op+ans;
    }
};