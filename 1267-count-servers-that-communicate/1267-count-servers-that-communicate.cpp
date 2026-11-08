class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<int> rows (n, 0);
        std::vector<int> cols(m, 0);
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (grid[row][col]) {
                    ++rows[row];
                    ++cols[col];
                }
            }
        }
        int communicate = 0;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (grid[row][col] && (rows[row] > 1 || cols[col] > 1)) communicate += 1;
            }
        }
        return communicate;
    }
};