class Solution {
public:
    int commonFactors(int a, int b) {
        vector<int> ans;
        int count=0;

        for(int i=1;i<=b;i++) {
            if(a%i==0 && b%i==0) {
                ans.push_back(i);
                count++;
            }
        }
        return count;
    }
};