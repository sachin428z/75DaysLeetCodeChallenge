class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n), last(26, -1);

        for (int i = 0; i < n; i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        vector<pair<int,int>> intervals;

        for (int c = 0; c < 26; c++) {
            if (first[c] == n) continue;

            int l = first[c];
            int r = last[c];
            bool valid = true;

            for (int i = l; i <= r; i++) {
                int ch = s[i] - 'a';

                if (first[ch] < l) {
                    valid = false;
                    break;
                }

                r = max(r, last[ch]);
            }

            if (valid) intervals.push_back({l, r});
        }

        sort(intervals.begin(), intervals.end());

        vector<pair<int,int>> chosen;

        for (auto &[l, r] : intervals) {
            if (chosen.empty() || l > chosen.back().second) {
                chosen.push_back({l, r});
            }
            else if (r < chosen.back().second) {
                chosen.back() = {l, r};
            }
        }

        vector<string> ans;

        for (auto &[l, r] : chosen) {
            ans.push_back(s.substr(l, r - l + 1));
        }

        return ans;
    }
};