class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.length();

        int d=0;
        

        stack<char> st;
        int score=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') {
                st.push(s[i]);
                d++;
            }
            else{
                d--;
                st.pop();
                if(s[i-1]=='(') {
                    score+=1<<d;
                }
                
            }
        }
        return score;
    }
};