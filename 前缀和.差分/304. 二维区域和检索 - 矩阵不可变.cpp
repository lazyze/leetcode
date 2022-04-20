class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int l = matrix[0].size();
        sum.clear();
        for (int i = 0; i < r; i++) {
            sum.push_back({}); //注意此种用法
            for (int j = 0; j < l; j++) {
                sum[i].push_back(getsum(i, j -1) + getsum(i - 1, j) - getsum(i - 1, j -1) + matrix[i][j]);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getsum(row2, col2) - getsum(row2, col1 - 1) - getsum(row1 - 1, col2) + getsum(row1 - 1, col1 - 1); 
    }

    int getsum(int i, int j) {
        if (i >= 0 && j >= 0) return sum[i][j];
        return 0;
    }

    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */