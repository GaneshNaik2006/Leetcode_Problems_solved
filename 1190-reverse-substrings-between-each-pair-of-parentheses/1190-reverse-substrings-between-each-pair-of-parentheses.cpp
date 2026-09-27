class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<char> st;
        for(int i=0;i<n;i++){

            if(s[i]!=')'){
                st.push(s[i]);
            }else{
                string temp="";
                while(!st.empty() && st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();

                for (char c:temp){
                    st.push(c);
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};