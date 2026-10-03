class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length();
        int m=t.length();

        if(n!=m) return false;

        unordered_map<int,int> mps;
        unordered_map<int,int> mpt;

        for(int i=0;i<n;i++){
            mps[s[i]]++;
            mpt[t[i]]++;
        }

        for(int i=0;i<n;i++){
            if(mps[s[i]]!=mpt[s[i]]) return false;
        }
        return true;
    }
};