class Solution {
public:
    int minimumPushes(string word) {
       int n=word.length();
        int count=0;
       for(int i=0;i<n;i++){
        if(i>=0 && i<=7) count+=1;
        else if(i>=8 && i<=15) count+=2;
        else if(i>=15 && i<=23) count+=3;
        else if(i<=23 && i<=25) count+=4;
       } 
       return count;
    }
};