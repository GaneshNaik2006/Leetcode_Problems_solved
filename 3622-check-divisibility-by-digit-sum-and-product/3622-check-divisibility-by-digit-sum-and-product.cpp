class Solution {
public:
    bool checkDivisibility(int n) {
        long long digsum=0;
        long long digprod=1;
        int t=n;
        while(t!=0){
            int r=t%10;
            digsum+=r;
            digprod*=r;
            t=t/10;
        }
        long long ans=digsum+digprod;
        return (n%ans)==0;
    }
};