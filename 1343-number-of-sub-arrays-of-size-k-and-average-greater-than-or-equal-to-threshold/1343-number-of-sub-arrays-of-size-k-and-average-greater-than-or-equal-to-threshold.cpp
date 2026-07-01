class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt=0,sum=0,t=k*threshold;
        int n=arr.size();
        for(int i=0;i<n;i++) {
            sum+=arr[i];
            if(i>=k) sum-=arr[i-k];
            if(i>=k-1 && sum>=t) cnt++;
        }
        return cnt;
    }
};