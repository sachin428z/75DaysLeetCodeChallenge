class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minTime=INT_MAX;

        for(int i=0;i<landStartTime.size();i++) {
            for(int j=0;j<waterStartTime.size();j++) {
                int landFinish=max(landStartTime[i],0)+landDuration[i];
                int waterBegin=max(landFinish,waterStartTime[j]);
                int totalTime1 = waterBegin + waterDuration[j];

            int waterFinish = max(waterStartTime[j], 0) + waterDuration[j];
            int landBegin = max(waterFinish, landStartTime[i]);
            int totalTime2 = landBegin + landDuration[i];

            minTime = min({minTime, totalTime1, totalTime2});
            }
        }
        return minTime;
    }
};