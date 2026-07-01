class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mask = 0;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            while ((mask & nums[right]) != 0) {
                mask ^= nums[left];
                left++;
            }

            mask |= nums[right];
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};