class Solution {
public:
    void color(vector<vector<char>>& grid, int i, int j, int island) {
        if (grid[i][j] == '1') {
            grid[i][j] += island;
            if (i < grid.size() - 1)
                color(grid, i + 1, j, island);
            if (j < grid[0].size() - 1)
                color(grid, i, j + 1, island);
            if (i > 0)
                color(grid, i - 1, j, island);
            if (j > 0)
                color(grid, i, j - 1, island);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size(), island = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > '1') continue;
                else if (grid[i][j] == '1') {
                    color(grid, i, j, island);
                    island++;
                }
            }
        }
        return --island;
    }
};