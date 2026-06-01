class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        int cnt=0,sum=0;

        for(int i=n-1;i>=0;i--) {
            if(cnt<2) {
                sum+=cost[i];
                cnt++;
            } else {
                cnt=0;
            }
        }
        return sum;

    }
};