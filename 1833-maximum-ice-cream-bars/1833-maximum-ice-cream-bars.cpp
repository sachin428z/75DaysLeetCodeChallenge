class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n=costs.size();
        int sum=0;
        int cnt=0;

        for(int i=0;i<n;i++) {
            if(costs[i]>coins) break;
            sum+=costs[i];
            cnt++;
            coins=coins-costs[i];
        }
        return cnt;
    }
};