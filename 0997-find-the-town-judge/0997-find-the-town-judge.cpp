class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector <int> map(n + 1, 0);
        for (int i = 0; i < trust.size(); i++) {
            map[trust[i][0]] = -1;
            if (map[trust[i][1]] != -1) {
                map[trust[i][1]]++;
            }
        }
        int judge = -1;
        for (int i = 1; i <= n; i++) {
            if (map[i] != -1 && map[i] != n - 1) {
                return -1;
            }
            if (map[i] == n - 1) {
                judge = i;
            }
        }
        return judge;
    }
};