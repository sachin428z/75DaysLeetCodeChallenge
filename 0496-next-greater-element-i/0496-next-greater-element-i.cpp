class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
           stack<int> st;
           int n=nums2.size();

           for(int i=n-1;i>=0;i--) {
                int num = nums2[i];
            while (!st.empty() && st.top()<=num) {
            st.pop();
           }

           if (st.empty()) mp[num]=-1;
           else mp[num]=st.top();
           
           st.push(num);
    }
           vector<int> result;
        for (int num : nums1) {
            result.push_back(mp[num]);
        }
        return  result;
    }
};