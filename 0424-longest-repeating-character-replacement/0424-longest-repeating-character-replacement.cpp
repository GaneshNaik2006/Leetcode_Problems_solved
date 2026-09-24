class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
       
    int maxi=0;
    unordered_map<int,int> mp;

        int otherch=0;
        int l=0,r=0;
        int ans=0;
        while(r<n){
            
            mp[s[r]]++;
            maxi=max(maxi,mp[s[r]]);
            int otherch=(r-l+1)-maxi;
            if(l<=r && otherch>k){
                mp[s[l]]--;
                l++;
            }
        
            ans=max(ans,r-l+1);
            r++;
        }

        return ans;

    }
};