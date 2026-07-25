class Solution 
{
    public:
        int maxProduct(int n) 
        {
            int maxi=-1;int secondmaxi=-1;
            while(n>0)
            {
                int d=n%10;
                n/=10;
                if(d>=maxi)
                {
                    secondmaxi=maxi;
                    maxi=d;
                }
                else if(d>=secondmaxi) secondmaxi=d;
            }
            return maxi*secondmaxi;
        }
};