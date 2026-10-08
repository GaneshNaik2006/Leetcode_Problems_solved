class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        string ans="";
        int st=-1;
        int end=-1;
        int open =0;
        bool x=true;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
            open++;
            else open--;
            if(open==1 && x) {
                st=i;
                x=false;
            }
            if(open ==0){
                 end=i;
                 if(st!=-1 && end!=-1)
                 ans+=s.substr(st+1,end-st-1);
                 x=true;
            } 
        }

        return ans;
    }
};