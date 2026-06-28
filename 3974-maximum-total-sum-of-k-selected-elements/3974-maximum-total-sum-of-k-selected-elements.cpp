class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long sum=0;

        for(int i=n-1;i>=0 && k>0;i--) {
            if(1LL*nums[i]*mul>nums[i]) {
                sum+=1LL*nums[i]*mul;
            } else {
                sum+=nums[i];
            }
            mul--;
           k--;
        }
        return sum;
    }
};