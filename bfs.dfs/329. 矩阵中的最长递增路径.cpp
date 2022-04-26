class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        r = matrix.size();
        c = matrix[0].size();
        visit = vector<vector<bool>> (r, vector<bool>(c, false));
        visitval = vector<vector<int>> (r, vector<int>(c, 0));
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (visit[i][j] == false)
                ans = max(dfs(matrix, i, j), ans);
            }
        }
        return ans;
    }
   
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        visit[i][j] = true;
        
        int ans = 1;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x < 0 || y < 0 || x >= r || y >= c) continue;
            if(matrix[x][y] > matrix[i][j]) {
                if(visit[x][y]) {
                    ans = max(ans, 1 + visitval[x][y]);
                }
                else ans = max(ans, 1 + dfs(matrix, x, y));
            }
        }
        
        visitval[i][j] = ans;
        return ans;
    }

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<vector<bool>> visit;
    //unordered_map<int, int> unmap;
    vector<vector<int>> visitval;
    int r;
    int c;
};

// //拓扑排序(bfs)解法
// class Solution {
// public:
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
//         r = matrix.size();
//         c = matrix[0].size();
//         indegree = vector<int>(r * c,  0);
//         depth = vector<int>(r * c, 1);
//         edge = vector<vector<int>>(r * c, vector<int>());
//         for (int i = 0; i < r; i++) {
//             for (int j = 0; j < c; j++) {
//                 for (int k = 0; k < 4; k++){
//                     int x = i + dx[k];
//                     int y = j + dy[k];
//                     if (x < 0 || x >= r || y < 0 || y >= c) continue;
//                     if (matrix[x][y] > matrix[i][j]) {
//                         edge[i * c + j].push_back(x * c + y);
//                         indegree[x * c + y]++;
//                     }
//                 }
//             }
//         }
//         ans = 1;
//         tops();
//         return ans;
//     }

//     void tops() {
//         queue<int> que;
//         for (int i = 0; i < r * c; i++) {
//             //cout << i << "入度为" << indegree[i] << endl;
//             if (indegree[i] == 0) {
//                 //cout << i << endl;
//                 que.push(i); 
//             }
//         }
//         while (!que.empty()) {
//             int top = que.front();
//             que.pop();
//             for (auto it : edge[top]) {
//                 indegree[it]--;
//                 if(indegree[it] == 0) {
//                     depth[it] = 1 + depth[top];
//                     ans = max(ans, depth[it]);
//                     que.push(it);
//                 }
//             }
//         }
//     }
//     int r;
//     int c;
//     int ans;
//     vector<int> indegree;
//     vector<vector<int>> edge;
//     vector<int> depth;
//     int dx[4] = {0, 1, 0, -1};
//     int dy[4] = {1, 0, -1, 0};
// };