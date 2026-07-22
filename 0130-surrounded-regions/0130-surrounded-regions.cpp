#define MAX 200

class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<pair<int, int>> q;
    vector<pair<int, int>> surrounded;
    int m, n;
    bool visited[MAX][MAX];
    bool surrounded_flag = true;
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        memset(visited, false, sizeof(visited));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X') continue;
                if(visited[i][j]) continue;

                if(board[i][j] == 'O'){
                    surrounded_flag = true;
                    surrounded.push_back({i, j});
                    q.push({i, j});
                    visited[i][j] = true;
                    bfs(board);
                }

                if(surrounded_flag){
                    for(size_t k = 0; k < surrounded.size(); k++){
                        board[surrounded[k].first][surrounded[k].second] = 'X';
                    }
                }

                surrounded.clear();
            }
        }
    }

private:
    void bfs(vector<vector<char>>& board){
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                for(int j = 0; j < 4; j++){
                    int ny = y + dy[j];
                    int nx = x + dx[j];

                    if(ny < 0 || nx < 0 || ny >= m || nx >= n) {
                        surrounded_flag = false;
                        continue;
                    }

                    if(!visited[ny][nx] && board[ny][nx] == 'O'){
                        visited[ny][nx] = true;
                        q.push({ny, nx});
                        surrounded.push_back({ny, nx});
                    }
                }
            }
        }
    }
};