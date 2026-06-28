class Solution {
public:
    string finalString(string s) {
        string ans="";

        for(char ch: s) {
            if(ch!='i') ans+=ch;
            else reverse(begin(ans),end(ans)); 
        }
        return ans;
    }
};