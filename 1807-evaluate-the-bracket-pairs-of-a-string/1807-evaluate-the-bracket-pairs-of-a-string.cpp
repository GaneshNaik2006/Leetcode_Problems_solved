class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.length();
        int m=knowledge.size();
        unordered_map<string,string> mp;

        for(int i=0;i<m;i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        knowledge.clear();
        string ans="";
        string path="";

        bool accept =true;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                accept=false;
            }
            else if(!accept && s[i]!=')'){
                path.push_back(s[i]);
            }

           else if(accept){
                ans.push_back(s[i]);
            }
            else if(s[i]==')'){
                accept=true;
                if(mp.find(path)!=mp.end()) ans+=mp[path];
                else ans+="?";
                path="";
            }

        }
        return ans; 
    }
};