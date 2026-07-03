class Solution {
public:
    
    bool checkValidString(string s) {
        int n=s.length();
        int mx=0,mn=0;

        for(int i=0;i<n;i++){
            if(s[i]=='(') {
                mn++;
                mx++;
            }
            else if(s[i]==')') {
                mn--;
               mx--;
            }
            else {
                 mn--;
                mx++;
            }

            if(mx<0) return false;
            if(mn<0) mn=0;
        }
        return mn==0;
    }
};