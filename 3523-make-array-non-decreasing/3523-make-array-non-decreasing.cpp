class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=maxi){
                cnt++;
            }
            maxi=max(maxi,nums[i]);
        }
        return cnt;
    }
};