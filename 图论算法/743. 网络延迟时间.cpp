class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //bellman-ford算法
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        int ans = -1;
        bool flag;
        for (int i = 0; i < n; i++) {
            flag = false;
            for (auto& it : times) {
                int a = it[0];
                int b = it[1];
                int c = it[2];
                if(dist[a] + c < dist[b]) {
                    dist[b] = dist[a] + c;
                    flag = true;
                }
            }
            if(!flag) break;
        }
        for (int i = 1; i <= n; i++) {
            if(dist[i] == 1e9) return -1;
            if(dist[i] > ans) ans = dist[i];
        }
        return ans;
    }
};

//dijkstra解法
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> edge(n + 1);
        //建图，出边数组的形式，但需要记录权值
        //edge[2] = {{1, 1}, {3, 1}}
        for (auto& it : times) {
            int a = it[0];
            int b = it[1];
            int c = it[2];
            edge[a].push_back(make_pair(b, c));
        }
        vector<int> dist(n + 1, 1e9);
        vector<bool> visit(n + 1, false);
        dist[k] = 0;
        priority_queue<pair<int, int>> pque;
        pque.push(make_pair(dist[k], k));
        while (!pque.empty()) {
            //到k的路径和
            int a = -pque.top().first;
            //节点k
            int b = pque.top().second;
            //出队
            pque.pop();
            if(visit[b]) continue; 
            visit[b] = true;
            for (auto& it : edge[b]) {
                int node = it.first;
                int len = it.second;
                //cout << len << endl;
                if(a + len < dist[node]) {
                    dist[node] = a + len;
                    pque.push(make_pair(-dist[node], node));
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if(dist[i] == 1e9) return -1;
            if(ans < dist[i]) ans = dist[i];
        }
        return ans;
    }
};