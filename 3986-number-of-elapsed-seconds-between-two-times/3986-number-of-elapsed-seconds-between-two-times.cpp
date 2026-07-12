class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int stH=0,stM=0,stS=0,enH=0,enM=0,enS=0,x=0;

        for(int i=0;i<8;i++) {
            if(endTime[i]==':') {
                x++;
                i++;
            }
            int endig=endTime[i]-'0';
            int stdig=startTime[i]-'0';

            if(x==0) {
                stH=stH*10+stdig;
                enH=enH*10+endig;
            } else if(x==1) {
                stM=stM*10+stdig;
                enM=enM*10+endig;
            } else {
                stS=stS*10+stdig;
                enS=enS*10+endig;
            }
        }

        int h=enH-stH;
        int m=enM-stM;
        int s=enS-stS;

        return h*3600+m*60+s;

    }
};