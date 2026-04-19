class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        int left=n-1;
        for(int i=0;i<n;i++){

           if(!st.empty() && nums[st.top()]>nums[i]){
            while(!st.empty() && nums[st.top()]>nums[i]){
             left=min(st.top(),left);
              st.pop();
            }
            if(st.empty()){
                left=0;
            }
           }


           st.push(i);
        }
        stack<int>st2;
        int right=0;
        for(int i=n-1;i>=0;i--){
         if(!st2.empty() && nums[st2.top()]<nums[i]){
           while( !st2.empty() && nums[st2.top()]<nums[i]){
            right=max(right,st2.top());
            st2.pop();
           }

         }
         st2.push(i);
        }
       if(left>=right){
        return 0;
       }
       return right-left+1;
    }
};