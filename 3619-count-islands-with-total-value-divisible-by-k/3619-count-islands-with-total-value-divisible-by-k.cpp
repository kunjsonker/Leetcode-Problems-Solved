class Solution {
public:
    long long bfs(vector<vector<int>>& grid , int i , int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        long long val = grid[i][j];
        grid[i][j] = 0;
        return val + bfs(grid , i+1 , j) + bfs(grid , i-1 , j) + bfs(grid , i , j+1) + bfs(grid , i , j-1);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size() , ans = 0;
        for(int i = 0; i< m; i++) {
            for(int j = 0; j< n; j++) {
                if(grid[i][j] > 0) {
                    long long total = bfs(grid , i , j);
                    if(total%k == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};