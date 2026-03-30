class Solution {
public:
    char findTheDifference(string s, string t) {
        char res=0;
        for(char c: s) {
            res=res^c;
        }
        for(char c: t) {
            res=res^c;
        }
        return res;
    }
};