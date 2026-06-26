class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }

    int countDistinctIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> unique;
        
        for(auto it: nums) {
            unique.insert(it);
            unique.insert(reverseNum(it));
        }
        return unique.size();

    }
};