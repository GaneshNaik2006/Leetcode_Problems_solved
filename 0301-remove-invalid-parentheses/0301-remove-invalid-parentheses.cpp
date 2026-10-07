class Solution {
public:
    unordered_set<string> st;

    void solve(string &s,int i,int open,int close,int balance,string curr){
        if(i==s.size()){
            if(open==0&&close==0&&balance==0)
                st.insert(curr);
            return;
        }

        if(balance<0) return;

        char ch=s[i];

        if(ch!='('&&ch!=')'){
            solve(s,i+1,open,close,balance,curr+ch);
            return;
        }

        if(ch=='('&&open>0)
            solve(s,i+1,open-1,close,balance,curr);

        if(ch==')'&&close>0)
            solve(s,i+1,open,close-1,balance,curr);

        if(ch=='(')
            solve(s,i+1,open,close,balance+1,curr+ch);
        else
            solve(s,i+1,open,close,balance-1,curr+ch);
    }

    vector<string> removeInvalidParentheses(string s){
        int open=0,close=0;

        for(char ch:s){
            if(ch=='(')
                open++;
            else if(ch==')'){
                if(open>0)
                    open--;
                else
                    close++;
            }
        }

        solve(s,0,open,close,0,"");

        vector<string> ans;
        for(auto x:st)
            ans.push_back(x);

        return ans;
    }
};