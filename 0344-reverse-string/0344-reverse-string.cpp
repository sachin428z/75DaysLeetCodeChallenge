class Solution {
public:
    void rev(vector<char>& s, int l, int r) {
        
        if(l>=r) return;
        swap(s[l],s[r]);
        rev(s,l+1,r-1);
    }

    void reverseString(vector<char>& s) {
        int l=0;
        int r=s.size()-1;
       return rev(s,l,r);
    }
};