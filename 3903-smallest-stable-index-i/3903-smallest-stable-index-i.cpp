class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=INT_MIN;
        int res=INT_MAX;

        int ind=INT_MAX;
        for(int i=0;i<n;i++) {
            maxi=max(maxi,nums[i]);
            int mini=INT_MAX;
            for(int j=i;j<n;j++) {
                mini=min(mini,nums[j]);

            }
            if(maxi-mini<=k) ind=min(ind,i);

        }
        return (ind!=INT_MAX)?  ind:-1;
    }
};