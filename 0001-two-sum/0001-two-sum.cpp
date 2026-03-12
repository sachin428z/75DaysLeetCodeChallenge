class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int j = 0; j < nums.size(); ++j) {
            int complement = target - nums[j];
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], j};
            }
            hash[nums[j]] = j;
        }
        // Return an empty vector if no solution is found
        return {};
    }
};