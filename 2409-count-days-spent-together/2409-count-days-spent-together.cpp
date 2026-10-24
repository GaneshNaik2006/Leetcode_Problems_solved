class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<bool> alice(366,false);
        vector<bool> bob(366,false);

        int sta=0;
        int enda=0;

        int alicestartmonth=(arriveAlice[0]-'0')*10+(arriveAlice[1]-'0');
        cout<<alicestartmonth<<endl;
        int alicestartdate=(arriveAlice[3]-'0')*10+(arriveAlice[4]-'0');
        cout<<alicestartdate<<endl;
        int aliceleavemonth=(leaveAlice[0]-'0')*10 +(leaveAlice[1]-'0');
        cout<<aliceleavemonth<<endl;
        int aliceleavedate=(leaveAlice[3]-'0')*10 +(leaveAlice[4]-'0');
        cout<<aliceleavedate<<endl;
        int bobstartmonth=(arriveBob[0]-'0')*10 +(arriveBob[1]-'0');
        cout<< bobstartmonth<<endl;
        int bobstartdate=(arriveBob[3]-'0')*10 +(arriveBob[4]-'0');
        cout<<bobstartdate<<endl;
        int bobleavemonth=(leaveBob[0]-'0')*10 +(leaveBob[1]-'0');
        cout<< bobleavemonth<<endl;
        int bobleavedate=(leaveBob[3]-'0')*10 +(leaveBob[4]-'0');
        cout<<bobleavedate<<endl;
        vector<int> month={0,31,28,31,30,31,30,31,31,30,31,30,31};
        vector<int> monthps(13,0);
        monthps[0]=0;
        cout<<monthps[0]<<" ";
        for(int i=1;i<13;i++){
            monthps[i]=month[i]+monthps[i-1];
            cout<<monthps[i]<<" ";
        }
        cout<<endl;
       sta= monthps[alicestartmonth-1]+alicestartdate;
       cout<<sta <<endl;
       enda=monthps[aliceleavemonth-1]+aliceleavedate;
        cout<<enda<<endl;
       int stb=monthps[bobstartmonth-1]+bobstartdate;
       cout<<stb <<endl;
       int endb=monthps[bobleavemonth-1]+bobleavedate;
       cout<<endb <<endl;

       for(int i=sta;i<=enda;i++){
        alice[i]=true;
       }

       for(int i=stb;i<=endb;i++){
        bob[i]=true;
       }
            int ans=0;
        for(int i=0;i<366;i++){
            if(alice[i] && bob[i]) ans++;
        }
       
        return ans;
    }
};