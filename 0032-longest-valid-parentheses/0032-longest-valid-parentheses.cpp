class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        if(n==0) return 0;
        stack<pair<int,int>> st;
        int cnt=0;
        int maxcnt=-1;
        vector<bool> v(n,false); 
        for(int i=0;i<n;i++){

            if(s[i]=='(') {
                st.push({s[i],i});
            }else{
                if(st.empty()){
                    continue;
                }else{
                    v[i]=true;
                    v[st.top().second]=true;
                    st.pop();
                }
            }
            
        }
     
        for(int i=0;i<n;i++){
            if(v[i]) cnt++;
            else cnt=0;
            maxcnt=max(cnt,maxcnt);
        }
        return maxcnt;
    }
};