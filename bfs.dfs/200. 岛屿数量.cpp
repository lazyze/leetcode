class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();
        visit = vector<vector<bool>> (r, vector<bool>(c, false));
        int ans = 0;
        for (int i= 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if(grid[i][j] == '1' && !visit[i][j]) {
                    //dfs(grid, i, j);
                    bfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        visit[i][j] = true;
        int x;
        int y;
        for (int k = 0; k < 4; k++) {
            x = i + dx[k];
            y = j + dy[k];
            if(x < 0 || x >= r || y < 0 || y >= c) continue;
            if(grid[x][y] == '1' && !visit[x][y] ) dfs(grid, x, y);
        }
    }

    void bfs(vector<vector<char>>& grid, int i, int j) {
        
        visit[i][j] = true;
        queue<pair<int, int>> que;
        que.push(make_pair(i, j));
        while(!que.empty()) {
            auto tmp = que.front();
            que.pop();
            int x;
            int y;
            for (int k = 0; k < 4; k++) {
                x = tmp.first + dx[k];
                y = tmp.second + dy[k];
                if(x < 0 || x >= r || y < 0 || y >= c) continue;
                if(grid[x][y] == '1' && !visit[x][y] ) {
                    que.push(make_pair(x, y));
                    visit[x][y] = true;
                }
            }
        }

    }
    vector<vector<bool>> visit;
    int r;
    int c;
    int dx[4] = {0, 1, 0 , -1};
    int dy[4] = {1, 0, -1, 0};
};