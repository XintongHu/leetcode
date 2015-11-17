class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i, j, n = matrix.size(), tmp;
        double c = double(n - 1) / 2;
        for (i = 0; i <= c; ++i) {
            for (j = 0; j < c; ++j) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[int(2*c - j)][i];
                matrix[int(2*c - j)][i] = matrix[int(2*c - i)][int(2*c - j)];
                matrix[int(2*c - i)][int(2*c - j)] = matrix[j][int(2*c - i)];
                matrix[j][int(2*c - i)] = tmp;
            }
        }
    }
};