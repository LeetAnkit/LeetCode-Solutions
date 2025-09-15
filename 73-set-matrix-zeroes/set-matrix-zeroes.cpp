class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<bool> row(n, false);
        vector<bool> col(m, false);

        // First pass: mark rows and columns that need to be zeroed
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        // Second pass: zero out marked rows and columns
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
