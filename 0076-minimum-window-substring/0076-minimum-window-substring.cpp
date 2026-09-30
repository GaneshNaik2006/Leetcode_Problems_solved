class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();

        unordered_map<char,int> mp;

        for(int i=0;i<m;i++) mp[t[i]]++;

        int r=0,l=0,minlen=INT_MAX,si=-1,cnt=0;

        while(r<n){
            if(mp[s[r]]>0) cnt++;
            mp[s[r]]--;

            while(cnt==m){
                if(minlen>r-l+1) {
                    minlen=r-l+1;
                    si=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }

        return si==-1 ?"" :s.substr(si,minlen);
    }
};