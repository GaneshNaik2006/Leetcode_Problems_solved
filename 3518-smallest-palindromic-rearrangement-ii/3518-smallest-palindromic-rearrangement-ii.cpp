class Solution {
public:
    const long long LIMIT = 1000001;

    vector<int> primes;

    void sieve(int n) {
        vector<bool> isPrime(n + 1, true);

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);

                if ((long long)i * i <= n) {
                    for (long long j = 1LL * i * i; j <= n; j += i)
                        isPrime[j] = false;
                }
            }
        }
    }

    long long getPower(long long base, int exp) {
        long long ans = 1;

        while (exp--) {
            if (ans > LIMIT / base)
                return LIMIT;

            ans *= base;
        }

        return ans;
    }

    int factPower(int n, int p) {
        int ans = 0;

        while (n) {
            n /= p;
            ans += n;
        }

        return ans;
    }


    long long countWays(vector<int>& freq) {

        int n = 0;

        for (int x : freq)
            n += x;


        long long ans = 1;


        for (int p : primes) {

            if (p > n)
                break;


            int power = factPower(n, p);


            for (int x : freq)
                power -= factPower(x, p);


            if (power > 0) {

                long long val = getPower(p, power);

                if (ans > LIMIT / val)
                    return LIMIT;

                ans *= val;


                if (ans >= LIMIT)
                    return LIMIT;
            }
        }

        return ans;
    }



    string smallestPalindrome(string s, int k) {

        vector<int> freq(26,0);

        for(char c:s)
            freq[c-'a']++;


        vector<int> half(26,0);

        string mid="";


        for(int i=0;i<26;i++){

            half[i]=freq[i]/2;

            if(freq[i]%2)
                mid.push_back('a'+i);
        }


        int halfLen=s.size()/2;


        sieve(halfLen);



        if(countWays(half)<k)
            return "";


        string first="";


        for(int pos=0; pos<halfLen; pos++){

            for(int c=0;c<26;c++){

                if(half[c]==0)
                    continue;


                // try placing this character
                half[c]--;


                long long ways=countWays(half);


                if(ways>=k){

                    first.push_back('a'+c);
                    break;

                }
                else{

                    k-=ways;
                    half[c]++;

                }
            }
        }


        string second=first;

        reverse(second.begin(),second.end());


        return first+mid+second;
    }
};