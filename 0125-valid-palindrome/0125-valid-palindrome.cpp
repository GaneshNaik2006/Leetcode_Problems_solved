class Solution {
public:
    bool f(char s){
        if((s>='A' && s<='Z') || (s>='a' && s<='z') || (s>='0' && s<='9')) return true;
        return false;
    }

    bool p(string& ans){
        int n=ans.size();

        int i=0;
        int j=n-1;

        while(i<j){
            if(ans[i]!=ans[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    bool isPalindrome(string s) {
        string ans="";

        int n=s.length();

        for(int i=0;i<n;i++){
            if(f(s[i])) ans.push_back(tolower(s[i]));
        }

        if(p(ans)) return true;
        return false;
        
    }
};