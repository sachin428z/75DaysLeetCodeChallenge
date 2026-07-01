class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int l = 0;

                for(int d = 0; d < 8; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];

                    if(ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        if(board[ni][nj] == 1 || board[ni][nj] == -1)
                            l++;
                    }
                }

                if(board[i][j] == 1 && (l < 2 || l > 3))
                    board[i][j] = -1;

                else if(board[i][j] == 0 && l == 3)
                    board[i][j] = 2;
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 2)
                    board[i][j] = 1;
                else if(board[i][j] == -1)
                    board[i][j] = 0;
            }
        }
    }
};