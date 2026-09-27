class Solution {
public:
    int reverseBits(int n) {
        
        vector<int> st(32,0);
       int i=0;
        while(n!=0){
            st[i]=n%2;
            n=n/2;
            i++;
        }
        int m=st.size();
        long long ans=0;
   
        long long  x=1;
        for(int i=m-1;i>=0;i--){
            ans+=st[i]*x;
            x=x*2;
            
        }
        return ans;
    }
};