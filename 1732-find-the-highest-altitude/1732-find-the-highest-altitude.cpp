class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int h=0;
        int ans=0;

        for(int i=0;i<n;i++) {
            h+=gain[i];
            ans=max(ans,h);

        }
        return ans;
    }
};