class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> result;

        if(nums.empty()) return result;

        int start=nums[0];
        for(int i=1;i<=n;i++) {
            if(i==n || nums[i]!=nums[i-1]+1) {
                if(start==nums[i-1]) result.push_back(to_string(start));
                else result.push_back(to_string(start)+ "->" + to_string(nums[i-1]));

                if(i<n) start=nums[i];

            }
        }

        return result;


    }
};