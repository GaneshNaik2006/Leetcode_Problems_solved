class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> ans;
        int n=s.size();

        for(int i=0;i<n;i++){
            int dig=s[i]-'a';
            ans.push_back(dig);
        }
        sort(ans.begin(),ans.end());
        vector<char> store={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        vector<char> anss(n);
        for(int i=0;i<n;i++){
            anss[i]=store[ans[i]];
        }
        string first="";
        string last="";
        string one="";
        int i=0;
        while(i<n-1){
            if(anss[i]==anss[i+1]){
                first.push_back(anss[i]);
                last.push_back(anss[i+1]);
                i=i+2;
            }else {
                one.push_back(anss[i]);
                i++;
            }
        }
        if(i<n) one.push_back(anss[i]);
        reverse(last.begin(),last.end());

        return first+one+last;
    }
};