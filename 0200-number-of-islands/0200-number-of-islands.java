class Solution {
    private int row, col;
    private int ans = 0;
    private boolean[][] visited;
    private int[] dy = {1, -1, 0, 0};
    private int[] dx = {0, 0, 1, -1};
    
    private void bfs(int r, int c, char[][] grid){
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{r, c});
        while(!q.isEmpty()){
            int[] current = q.poll(); 

            int y = current[0];
            int x = current[1];

            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if(ny < 0 || nx < 0 || ny >= col ||  nx >= row ) continue;

                if(!visited[ny][nx] && grid[ny][nx] == '1'){
                    visited[ny][nx] = true;
                    q.add(new int[]{ny, nx});
                }
            }
        }

        ans++;
    }
    
    public int numIslands(char[][] grid) {
        col = grid.length;
        row = grid[0].length;
        visited = new boolean[col][row];

        for(int i = 0; i < col; i++){
            for(int j = 0; j < row; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    visited[i][j] = true;
                    bfs(i, j, grid);
                }
            }
        }

        return ans;
    }
}