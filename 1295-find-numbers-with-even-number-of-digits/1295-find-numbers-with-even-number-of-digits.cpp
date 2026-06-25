class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;i++) {
            while(nums[i]) {
                int ld=nums[i]%10;
                nums[i]=nums[i]/10;
                cnt++;
            }

            if(cnt%2==0) ans++;
            cnt=0;
           
        }
        return ans;
    }
};