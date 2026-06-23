class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();

        int r=0,l=0,minlen=INT_MAX,count=0,sindex=-1;
        unordered_map<char,int> mp;

        for(int i=0;i<m;i++) mp[t[i]]++;
        while(r<n){
            if(mp[s[r]]>0) count+=1;
            mp[s[r]]--;

            while(count==m){
                if(minlen> r-l+1){
                    minlen=r-l+1;
                    sindex=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        return sindex==-1?"":s.substr(sindex,minlen);
    }
};