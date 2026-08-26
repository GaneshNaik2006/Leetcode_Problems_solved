class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();

        int count=0;
        int l=0,r=0;
        int minlen=INT_MAX;
        vector<pair<int,string>> v;
        while(r<n){
            if(s[r]=='1'){
                count++;
            }
            while(count>k){
                if(s[l]=='1') count--;
                l++;
            }
            if(count==k){
                while (s[l] == '0')
                    l++;
                  minlen=min(minlen,r-l+1);
                    v.push_back({r-l+1,s.substr(l,r-l+1)});
            }
            r++;
          
        }
        sort(v.begin(),v.end());
        
        if(v.empty()) return "";
        if(v[0].first!=minlen) return "";
    
        
        return v[0].second;

    }
};