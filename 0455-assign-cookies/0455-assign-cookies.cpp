class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l=0, r=0;
        while(l<g.size() && r<s.size()) {
            if(s[r]>=g[l]) {
                l++;
                r++;
            } else {
                r++;
            }
        }
        return l;
    }
};