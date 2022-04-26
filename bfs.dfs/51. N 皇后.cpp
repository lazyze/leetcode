class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string str(n , '.');
        for (int i = 0; i < n; i++) {
            an.push_back(str);
        }
        len = n;
        recur(0);
        return ans;
    }

    void recur(int n) {
        if(n == len) {
            ans.push_back(an);
            return ;
        }
        for (int i = 0; i < len; i++) {
            if(isok(n, i)) {
                an[n][i] = 'Q';
                recur(n + 1);
                an[n][i] = '.';
            } else continue;
        }
    }
    //判断位置(n, i)时候是否可以放置皇后
    bool isok(int n, int i) {
        for (int j = 0; j < i; j++) {
            if (an[n][j] == 'Q') return false;
        }
        int x = 1;
        while(--n >= 0) {
            if (an[n][i] == 'Q') return false;
            if (i - x >= 0 && an[n][i - x] == 'Q') return false;
            if (i + x < len && an[n][i + x] == 'Q') return false;
            x++;
        }
        return true;
    }

    int len;
    vector<string> an;
    vector<vector<string>> ans;
};