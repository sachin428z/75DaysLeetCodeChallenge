class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=nums.size();
        int n=nums.size();

        for(int i=0;i<n;i++) {
            res+=i-nums[i];
        }
        return  res;
    }
};