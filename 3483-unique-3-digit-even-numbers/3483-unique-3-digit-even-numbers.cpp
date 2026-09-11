class Solution {
public:
  
    int totalNumbers(vector<int>& digits) {
       
       int n=digits.size();
        int cnt=0;
     
       
      set<long long> s;
       for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){

                    if(i==j || j==k || i==k) continue;
                 
                
                    int num=1LL*(digits[i]*100+digits[j]*10+digits[k]);
                 if(digits[i]!=0  && digits[k]%2==0 && s.find(num)==s.end()){
                    cnt++;
                    
                    s.insert(num);
                 }
                  
                }
            }
       }
       return cnt;
    }
};