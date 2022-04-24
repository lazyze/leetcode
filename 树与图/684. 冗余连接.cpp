class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        graph = vector<vector<int>>(n + 1, vector<int>());
        visit = vector<bool>(n + 1, false);
        int a;
        int b;
        hascycle = false;
        for (auto& it : edges) {
            a = it[0];
            b = it[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
            //***下行写法会报错
            //dfs(1, -1);
            dfs(a, -1);
            if(hascycle) {
                return it;
            }
        }
        return {};
    }

    void dfs(int i, int fa) {
        visit[i] = true;
        for (auto& it : graph[i]) {
            if(it == fa) continue;
            if(visit[it]) {
                hascycle = true;
                break;
            }
            else dfs(it, i);
        }
        visit[i] = false;
    }
    //出边数组
    vector<vector<int>> graph;
    bool hascycle;
    vector<bool> visit;
};