class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> ans;
        for(auto nums: matrix) {
            int count=0;
            for(int i=0;i<n;i++) {
                if(nums[i]==1) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};