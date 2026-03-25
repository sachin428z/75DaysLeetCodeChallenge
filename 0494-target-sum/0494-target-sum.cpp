class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       int total=accumulate(nums.begin(),nums.end(),0);
       if ((total+target)%2!=0 || abs(target)>total) return 0;
       int newTarget=(total+target)/2;
       vector<int> dp(newTarget+1, 0);
       dp[0]=1;
       for(int num: nums) {
        for(int j=newTarget;j>=num;j--) {
            dp[j]+=dp[j-num];
        }
       } 
       return dp[newTarget];
    }
};