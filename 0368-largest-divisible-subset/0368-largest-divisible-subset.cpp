class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<int> ans;
        vector<int> dp(n,1);
        vector<int> parent(n);

        int lastIndex=0;
        int maxLen=0;

        for(int i=0;i<n;i++) {
            parent[i]=i;
            for(int prevInd=0;prevInd<i;prevInd++) {
                if(nums[i] % nums[prevInd] == 0 && dp[i] < dp[prevInd] + 1) {

                    dp[i] = dp[prevInd] + 1; 
                    parent[i] = prevInd;
            }
        }
            if(dp[i] > maxLen) {
                lastIndex = i;
                maxLen = dp[i];
            }
        }

        int i = lastIndex;

        while(parent[i] != i) {
            ans.push_back(nums[i]);
            i = parent[i]; 
        }
        ans.push_back(nums[i]);

        return ans;
    }
};