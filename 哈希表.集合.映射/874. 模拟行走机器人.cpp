class Solution {
public:
    //北，东，南，西
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> uset;
        //unordered_set<string> uset;
        for (auto& it : obstacles) {
            uset.insert(hsh(it[0], it[1]));
        }
        int dir = 0;
        int x = 0;
        int y = 0;
        int ans = 0;
        for (auto& it : commands) {
            if (it > 0) {
                for (int i = 0; i < it; i++) {
                    x += dx[dir];
                    y += dy[dir];
                    if (uset.find(hsh(x, y)) != uset.end()) {
                        x -= dx[dir];
                        y -= dy[dir];
                        break;
                    }
                    ans = max(ans, x * x + y * y);
                }
                //cout << x << "," << y << endl;
            } else {
                if (it == -1) dir = (dir + 1) % 4;
                else dir = (dir - 1 + 4) % 4;
            }
        }
        return ans;
    }

    long long hsh(int x, int y) {
        return (x + 30000ll) * 60000 + y + 30000;
    }

    // string hsh(int x, int y) {
    //     return to_string(x) + "," + to_string(y);
    // }
};