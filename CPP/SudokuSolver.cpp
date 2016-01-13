class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool> > v(9, vector<bool>(9, true)), h(9, vector<bool>(9, true)), block(9, vector<bool>(9, true));
        vector<pair<int, int> > fill;
        int val;
        //row
        for (int i = 0; i < 9; ++i) {
            //col
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    val = board[i][j] - '0' - 1;
                    h[i][val] = false;
                    v[j][val] = false;
                    block[i/3*3 + j/3][val] = false;
                }
                else fill.push_back(make_pair(i, j));
            }
        }
        solver(board, v, h, block, 0, fill);
        
    }
private:
    bool solver(vector<vector<char>>& board, vector<vector<bool>> &v, vector<vector<bool>> &h, vector<vector<bool>> &block, 
                int n, vector<pair<int, int>> &fill) {
        if (n == fill.size()) return true;
        int x = fill[n].first, y = fill[n].second;
        for (int i = 0; i < 9; ++i) {
            if (h[x][i] && v[y][i] && block[x/3*3 + y/3][i]) {
                board[x][y] = i + 1 + '0';
                h[x][i] = false;
                v[y][i] = false;
                block[x/3*3 + y/3][i] = false;
                if (!solver(board, v, h, block, n + 1, fill)) {
                    board[x][y] = '.';
                    h[x][i] = true;
                    v[y][i] = true;
                    block[x/3*3 + y/3][i] = true;
                }
                else return true;
            }
        }
        return false;
    }
};