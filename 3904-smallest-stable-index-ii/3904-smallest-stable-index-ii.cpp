class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> mini(n);
        mini[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) {
            mini[i]=min(nums[i],mini[i+1]);
        }
        int ind=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++) {
            maxi=max(maxi,nums[i]);
            if(maxi-mini[i]<=k) ind=min(ind,i);
        }
        return (ind!=INT_MAX)?ind:-1;
    }
};