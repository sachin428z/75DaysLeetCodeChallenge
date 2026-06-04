class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, int> level;

    void dfs(string word, string beginWord,
             vector<string>& seq) {

        if(word == beginWord) {
            vector<string> temp = seq;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        int steps = level[word];

        for(int i = 0; i < word.size(); i++) {
            char original = word[i];

            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                if(level.find(word) != level.end() &&
                   level[word] + 1 == steps) {

                    seq.push_back(word);
                    dfs(word, beginWord, seq);
                    seq.pop_back();
                }
            }

            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);

        level[beginWord] = 0;

        st.erase(beginWord);

        while(!q.empty()) {
            string word = q.front();
            q.pop();

            int steps = level[word];

            if(word == endWord) break;

            for(int i = 0; i < word.size(); i++) {
                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if(st.count(word)) {
                        q.push(word);
                        level[word] = steps + 1;
                        st.erase(word);
                    }
                }

                word[i] = original;
            }
        }

        if(level.find(endWord) == level.end())
            return {};

        vector<string> seq;
        seq.push_back(endWord);

        dfs(endWord, beginWord, seq);

        return ans;
    }
};