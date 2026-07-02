class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();

        int c1=0;//change;
        int c2=0;
       
        for(int i=0;i<n;i++){
            if(bills[i]==5) c1+=5;
            else if(bills[i]==10){
                if (c1>=5){
                   c1-=5;
                   c2+=10;
                }
                else return false;
            }else {
                 if( (c1>=5 && c2>=10)){
                    c1-=5;
                    c2-=10;
                }else if(c1>=15 ) {
                   c1-=15;

                }
                else return false;
            }
        }

        return true;

    }
};