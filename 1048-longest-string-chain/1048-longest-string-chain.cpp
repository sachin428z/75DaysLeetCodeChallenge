class Solution {
public:
    static bool compare(string &s1, string &s2) {
        return s1.size() < s2.size();
    }

    bool checkPossible(string &s1, string &s2) {
        // s1 should be longer than s2 by exactly 1 character
        if (s1.size() != s2.size() + 1) return false;

        int first = 0, second = 0;

        while (first < s1.size()) {
            if (second < s2.size() && s1[first] == s2[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }

        return first == s1.size() && second == s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), compare);

        vector<int> dp(n, 1);
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (checkPossible(words[i], words[j]) &&
                    dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }

            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};