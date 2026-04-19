class Solution {
public:
    long long calculateScore(string s) {
        vector<vector<int>> pos(26);
        int n=s.size();
        long long count=0;

        for(int i=0;i<n;i++) {
            int letter=s[i]-'a';
            int mirror=25-letter;
            if(!pos[mirror].empty()) {
                int j=pos[mirror].back();
                pos[mirror].pop_back();
                count+=abs(i-j);

            } else {
                pos[letter].push_back(i);

            }
        }
        return count;
    }
};