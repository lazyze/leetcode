class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        fa = vector<int>(n, -1);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    int x = find(i);
                    int y = find(j);
                    if(x != y) fa[x] = y;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if(i == fa[i]) ans++;
        }
        return ans;
    }

    int find(int x) {
        if(x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }

    vector<int> fa;
};