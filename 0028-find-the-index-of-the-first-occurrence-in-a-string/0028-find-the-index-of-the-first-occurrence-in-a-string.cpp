class Solution {
public:
    int strStr(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        int ans=1;
        for(int i=0;i<=n-m;i++){
            if(s1[i]==s2[0]){
                
                int k=0;
                for(int j=i;j<i+m;j++){
                    if(s1[j]!=s2[k]){

                        
                        break;
                    }
                    k++;
                }
               if(k==m) return i;
            }
        }
        return -1;
    }
};