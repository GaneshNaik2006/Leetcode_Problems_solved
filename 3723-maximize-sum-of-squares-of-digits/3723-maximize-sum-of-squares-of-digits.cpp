class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        if (sum > 9LL* num) return "";
        if(sum<9){
            ans.push_back(sum+'0');
            for(int i=0;i<num-1;i++){
                ans.push_back('0');
            }
           
        }else{
            int x=sum/9;

            for(int i=0;i<x;i++) ans.push_back('9');
            int y=sum%9;
            int z=0;
            if(y!=0)
          {
              ans.push_back(y+'0');
                z=1;
          }

            for(int i=0;i<num-x-z;i++){
                ans.push_back('0');
            }
        }

            // cout<<ans<<endl;
             
            int s=0;
            
            int n=ans.size();
            
            for(int i=0;i<n;i++){
                s+=ans[i]-'0';
            }
            cout<<n<<endl;
            if(sum!=s || n!=num) return "";

        return ans;
        
    }
};