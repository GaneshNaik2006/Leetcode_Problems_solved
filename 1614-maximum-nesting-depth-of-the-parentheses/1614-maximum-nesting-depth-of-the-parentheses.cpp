class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();

        int f=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') f++;
            else if(s[i]==')') f--;
            maxi=max(f,maxi);
        }

        return maxi;
    }
};