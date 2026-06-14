class Solution {
public:
    int reverseBits(int n) {
       int bits=32;
       int sum=0;

       for(int i=0;i<bits;i++) {
        int lbit=n&1;
        sum=sum<<1 | lbit;
        n>>=1;
       } 
       return  sum;
    }
};