class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int cantake=INT_MAX;
        int profit=0;
        for(int i=0;i<n;i++){
            if(prices[i]<cantake){
                cantake=prices[i];
            }else{
                profit=max(prices[i]-cantake,profit);
            }
        }
        return profit;
    }
};