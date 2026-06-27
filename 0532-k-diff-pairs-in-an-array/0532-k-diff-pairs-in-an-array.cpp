class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        set<pair<int,int>> st;
        int cnt=0;
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(abs(nums[i]-nums[j])==k) {
                    st.insert({min(nums[i], nums[j]),max(nums[i], nums[j])});
                }
            }
        }
        return st.size();
    }
};