class Solution {
public:
    bool isPalindrome(int x) {
        int temp=x;
        long rev=0; //Since long has a larger range than int, temp is automatically promoted to long:

        while(x>0) {
            rev=(rev*10)+(x%10);
            x=x/10;
        }

        if (temp==rev) return true;
        else return false;
    }
};