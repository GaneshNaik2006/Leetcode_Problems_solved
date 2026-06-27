class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(gifts[i]);
        }

        while(k>0 && !pq.empty()){
            int x=pq.top();
            pq.pop();
            pq.push(floor(sqrt(x)));
            k--;
        }
        long long sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};