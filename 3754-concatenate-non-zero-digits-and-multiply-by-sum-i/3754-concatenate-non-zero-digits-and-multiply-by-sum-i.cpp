class Solution {
public:
    long long sumAndMultiply(int n) {
        int x=0;
        while(n!=0){
           int  r=n%10;
            if(r!=0) x=r+x*10;
            n=n/10;
        }

        int t=x;
        int y=0;
        while(t!=0){
            int r=t%10;
            y=r+y*10;
            t=t/10;
        }
        t=y;
        int sum=0;
    
        while(t!=0){
            sum+=t%10;
            t=t/10;
           
        }
     

        return 1ll*sum*y;
    }
};