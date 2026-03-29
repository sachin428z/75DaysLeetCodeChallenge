class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size(), m=worker.size();
        int left=0;
        int right=0;
        int maxi=0;
        int total=0;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) {
            v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end());
        sort(worker.begin(),worker.end());
        while(right<m) {
            while(left<n && v[left].first<=worker[right]) {
                maxi=max(maxi,v[left].second);
                left++;
            }
            total+=maxi;
            right++;
        }
        return total;
    }
};