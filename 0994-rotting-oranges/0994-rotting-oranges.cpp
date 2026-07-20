/*
Rotten Orange를 root로 하는 트리에서 퍼져나가는 bfs
bfs의 depth max가 정답이다
*/
#define EMPTY 0
#define FRESH 1
#define ROTTEN 2
#define MAX 11

class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool visited[MAX][MAX];
    queue<pair<int, int>> q;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        memset(visited, false, sizeof(visited));
        int fresh_count = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == ROTTEN) {
                    q.push({i, j});
                    visited[i][j] = true;
                }else if(grid[i][j] == FRESH){
                    fresh_count++;
                }
            }
        }

        if(fresh_count == 0) return 0;
        if(q.empty()) return -1;

        return bfs(grid);
    }

private:
    int bfs(vector<vector<int>>& grid){
        int height = 0;
        while(!q.empty()){
            int q_size = q.size();
            height++;
            for(int i = 0; i < q_size; i++){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                for(int j = 0; j < 4; j++){
                    int ny = y + dy[j];
                    int nx = x + dx[j];

                    if(ny < 0 || nx < 0 || ny >= grid.size() || nx >= grid[0].size()) continue;

                    if(!visited[ny][nx] && grid[ny][nx] == FRESH) {
                        q.push({ny, nx});
                        visited[ny][nx] = true;
                    }
                }
            }
        }

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j] == FRESH) {
                    return -1;
                }
            }
        }

        return height - 1;
    }
};