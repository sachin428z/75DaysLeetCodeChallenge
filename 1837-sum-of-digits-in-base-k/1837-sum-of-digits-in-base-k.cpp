class Solution {
public:
    int sumBase(int n, int k) {
        int sum=0;
        
        while(n) {
            int ld=n%k;
            n=n/k;
            sum+=ld;
        }
        return sum;
    }
};