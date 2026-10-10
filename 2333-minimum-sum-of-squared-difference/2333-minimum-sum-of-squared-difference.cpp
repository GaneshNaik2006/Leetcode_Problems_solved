class Solution {
public:
    using ll = long long;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        ll k = k1+k2;
        priority_queue<ll> q;
        int n = nums1.size();
        ll s =0 ;
        for(int i =0 ;i <n ; i++ ){
            q.push(abs(nums1[i]-nums2[i]));
            s+=abs(nums1[i]-nums2[i]);
        }
        if(s <= k)return 0;
    
        ll cnt =0 ;
        ll res = q.top();
        while(!q.empty() && q.top()>0){
            while(!q.empty() && q.top() ==res){
                cnt++;
                q.pop();
            }

            if(q.empty())break;
            ll diff = res - q.top();
            if(diff*cnt <= k ){
                k-=diff*cnt;
                res=q.top();
            }
            else{
                break;
            }
        }

        ll temp = k/cnt;
        res-=temp;
        ll rem = k%cnt;
        ll sum = res*res*(cnt-rem) ;
        sum+= rem*(res-1)*(res-1);
        while(!q.empty()){
            sum+=q.top()*q.top();
            q.pop();
        }
        return sum;
    }
};