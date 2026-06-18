class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        int n=nums.size();

        for(int i=0;i<n;i++) {
            mpp[nums[i]]++;
        }
        for(auto it: mpp) {
            if(it.second==2) 
            ans.push_back(it.first);
        }
        return ans;
    }
};