class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size();
        int m=word2.size();

        vector<char> list1;
        vector<char> list2;
        for(auto& s: word1){
            for(auto& c:s) {
                list1.push_back(c);
            }
        }
        for(auto& s:word2){
            for(auto& c:s) {
                list2.push_back(c);
            }
        }
        if(list1.size()!=list2.size()) return false;
        for(int i=0;i<min(list1.size(),list2.size());i++) {
            if(list1[i]!=list2[i]) return false;
        }
        return true;
    }
};