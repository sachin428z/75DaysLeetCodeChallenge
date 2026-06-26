class Solution {
public:
    int alternateDigitSum(int n) {
        stack<int> st;
        int sum=0;

        while(n) {
            int ld=n%10;
            st.push(ld);
            n=n/10;
        }
         
        int sign=1;
        while(!st.empty()) {
            sum+=sign*st.top();
            st.pop();
            sign*=-1;
        }
        return sum;
    }
};