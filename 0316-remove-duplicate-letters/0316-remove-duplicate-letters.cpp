class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> mp;
        int n=s.length();

        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
    unordered_set<char> s1;
    stack<char> st;

    for(int i=0;i<n;i++){
       mp[s[i]]--;
       if(s1.find(s[i])!=s1.end()) continue; //edge case .
        while(!st.empty() && st.top()-'a' > s[i]-'a' && mp[st.top()]>0){
            s1.erase(st.top());
            st.pop();
            
        }
         
        if(s1.find(s[i])==s1.end()){
            st.push(s[i]);
            s1.insert(s[i]);
        }
    }
    string ans;

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};