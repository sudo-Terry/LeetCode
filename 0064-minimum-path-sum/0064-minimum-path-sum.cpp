class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> grid_sum(m, vector<int>(n, 0));
        grid_sum[0][0] = grid[0][0];

        for (int i = 1; i < m; i++) {
            grid_sum[i][0] = grid_sum[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            grid_sum[0][j] = grid_sum[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid_sum[i][j] = min(grid_sum[i - 1][j], grid_sum[i][j - 1]) + grid[i][j];
            }
        }

        return grid_sum[m - 1][n - 1];
    }
};