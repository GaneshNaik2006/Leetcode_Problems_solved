class Solution {
public:
    int gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
    int gcdOfOddEvenSums(int n) {
        long long sumeven=0;
        long long sume=0;
        long long sumo=1;
        long long sumodd=0;
        for(int i=0;i<n;i++ ){
            sume+=2;
            sumeven+=sume;
            sumodd+=sumo;
            sumo+=2;
            
        }
        return gcd(sumeven,sumodd);
    }
};