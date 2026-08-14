class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        unordered_map<int,int> mp;

        int l=0,r=0;
        int maxlen=0;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>2){
                mp[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};