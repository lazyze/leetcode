//并查集做法
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        fa = vector<int>(r * c + 1, 0);
        for (int i = 0; i < r * c + 1; i++) {
            fa[i] = i;
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if(board[i][j] == 'X') continue;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x < 0 || y < 0 || x >= r || y >= c) {
                        fa[find(i * c + j)] = find(r * c);
                    } else if(board[x][y] == 'O'){
                        fa[find(x * c + y)] = find(i * c + j);
                    }
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if(board[i][j] == 'O' && find(i * c + j) != find(r * c)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
    int find(int x) {
        if(x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<int> fa;
};