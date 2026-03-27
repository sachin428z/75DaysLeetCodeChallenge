class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n=nums.size();

        map<int,int> mp;
        for(int num:nums) {
            mp[num]++;
        }
        for(int num:nums) {
            if(num%2==0 && mp[num]==1) return num;
        }
        return -1;
    }
};