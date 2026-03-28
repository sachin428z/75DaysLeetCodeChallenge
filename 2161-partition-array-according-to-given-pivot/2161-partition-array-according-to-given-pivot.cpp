class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int left=0, right=nums.size()-1;
        int n=nums.size();
        vector<int>less,equal,greater;
        for(int i=0;i<n;i++) {
            if(nums[i]<pivot) less.push_back(nums[i]);
            if(nums[i]==pivot) equal.push_back(nums[i]);
            if(nums[i]>pivot) greater.push_back(nums[i]);
        }
        vector<int> ans;
        ans.insert(ans.end(),less.begin(),less.end());
        ans.insert(ans.end(),equal.begin(),equal.end());
        ans.insert(ans.end(),greater.begin(),greater.end());
        return ans;
    }
};